#include <stdio.h>
#include <string.h>

#include "../include/extractFiles.h"
#include "../include/base64.h"

int extract_attachments(const char *dir, char **attachments) {
    FILE *file = fopen(dir, "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        return 0;
    }

    // helpful variable for debugging
    // int row_count = 0;

    char row[1024];

    // variable for getting file's name
    // while it is in the next row of the file
    char prev_row[1024];

    int attachment_count = 0;

    char attachment_name[256];
    int found_plain_text = 0;
    int in_attachment_header = 0;
    int in_attachment_content = 0;

    while (!feof(file)) {
        fgets(row, sizeof(row), file);

        // reset in attachment state
        if(strncmp(row, "--", 2) == 0){
            in_attachment_content = 0;
            found_plain_text = 0;
        }

        if(in_attachment_content){
            char *attachment_data_decoded = base64_decode(row);
            //printf("\n%s\n", attachment_name);

            FILE *attachment_file = fopen(attachment_name, "ab");
            fwrite(attachment_data_decoded, 1, strlen(attachment_data_decoded), attachment_file);
            fclose(attachment_file);
        }
        if(in_attachment_header) {
            for (int i = 0; i <= 2; i++) {
                if (row[i] == '\n') {
                    in_attachment_content = 1;
                    in_attachment_header = 0;
                }
            }
        }

        if(strncmp(row, "Content-Type: application/", strlen("Content-Type: application/")) == 0){
            in_attachment_header = 1;
        } else if(strncmp(row, "Content-Type: text/plain", strlen("Content-Type: text/plain")) == 0){
            found_plain_text = 1;
        }

        if(found_plain_text && strncmp(row, "Content-Transfer-Encoding: base64", strlen("Content-Transfer-Encoding: base64")) == 0){
            in_attachment_header = 1;
        }

        // If the previous row is "Content-Disposition: attachment;"
        // then get attachment name from the next row
        if (strncmp(prev_row, "Content-Disposition: attachment;", strlen("Content-Disposition: attachment;")) == 0) {
            // Extract attachment name

            char *first_char = strchr(row, '"');
            char *last_char = strrchr(row, '"');

            if(strcmp(first_char, "(null)") != 0 || strcmp(last_char, "(null)") != 0){

                int name_start = first_char - row;
                int name_end = last_char - row - 1;

                // Search a row for a file name
                int name_idx = 0;
                char name[256] = {0};

                for(int i = name_start + 1; i <= name_end; i++){
                    name[name_idx] = row[i];
                    name_idx++;
                }
                name[name_idx + 1] = '\0';

                strcpy(attachment_name, name);

                // Change prev_row value, so it won't collide
                // with another if statement
                strcpy(prev_row, row);
            } else {
                strcpy(attachment_name, "undefined_file");
            }

            attachments[attachment_count] = attachment_name;
        }

        if (strncmp(row, "Content-Disposition: attachment; filename=", strlen("Content-Disposition: attachment; filename=")) == 0) {
            // Extract attachment name
            sscanf(row, "Content-Disposition: attachment; filename=\"%[^\"]\"", attachment_name);

            attachments[attachment_count] = attachment_name;
        } else if(strncmp(row, "Content-Disposition: attachment;", strlen("Content-Disposition: attachment;")) == 0){
            strcpy(prev_row, row);
        }

        if(strncmp(row, "Content-Disposition: attachment;", strlen("Content-Disposition: attachment;")) == 0){
            attachment_count++;
        }

        //row_count++;
    }
    fclose(file);
    return 1;
}

int count_attachments(const char *dir){
    FILE *file = fopen(dir, "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        return 0;
    }

    int attachment_count = 0;
    char row[1024];

    while (!feof(file)) {
        fgets(row, sizeof(row), file);

        if(strncmp(row, "Content-Disposition: attachment;", strlen("Content-Disposition: attachment;")) == 0){
           attachment_count++;
        }
    }

    fclose(file);
    return attachment_count;
}