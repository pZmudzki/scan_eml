#include <stdio.h>
#include <string.h>

#include "../include/extractFiles.h"
#include "../include/base64.h"
#include "../include/searchFile.h"

#define MAX_NAME_LENGTH 256
#define MAX_ROW_LENGTH 1024

int count_attachments(const char *dir){
    FILE *file = fopen(dir, "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        return 0;
    }

    int attachment_count = 0;
    char row[MAX_ROW_LENGTH];

    while (!feof(file)) {
        fgets(row, sizeof(row), file);

        if(strncmp(row, "Content-Disposition: attachment;", strlen("Content-Disposition: attachment;")) == 0){
            attachment_count++;
        }
    }

    fclose(file);
    return attachment_count;
}

int extract_and_search_attachments(const char *dir) {
    FILE *file = fopen(dir, "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        return 0;
    }

    // helpful variable for debugging
    // int row_count = 0;

    char row[MAX_ROW_LENGTH];

    // variable for getting file's name
    // while it is in the next row of the file
    char prev_row[MAX_ROW_LENGTH];

    char attachment_name[MAX_NAME_LENGTH];

    // -1 because loop increases idx before
    // copying name to an array
    int curr_attachment_idx = -1;
    int found_plain_text = 0;
    int in_attachment_header = 0;
    int in_attachment_content = 0;

    /* -- for attachment search -- */

    // found attachments count
    int attachment_count = count_attachments(dir);
    // found attachments names
    char attachments[attachment_count][MAX_NAME_LENGTH];

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
                char name[MAX_NAME_LENGTH] = {0};

                for(int i = name_start + 1; i <= name_end; i++){
                    name[name_idx] = row[i];
                    name_idx++;
                }
                name[name_idx + 1] = '\0';

                strcpy(attachment_name, name);

                // Change prev_row value, so it won't collide
                // with another if statement
                strcpy(prev_row, row);

                strcpy(attachments[curr_attachment_idx], attachment_name);
            } else {
                strcpy(attachment_name, "undefined_file");
            }
        }

        if (strncmp(row, "Content-Disposition: attachment; filename=", strlen("Content-Disposition: attachment; filename=")) == 0) {
            // Extract attachment name
            sscanf(row, "Content-Disposition: attachment; filename=\"%[^\"]\"", attachment_name);


            strcpy(attachments[curr_attachment_idx], attachment_name);
        } else if(strncmp(row, "Content-Disposition: attachment;", strlen("Content-Disposition: attachment;")) == 0){
            strcpy(prev_row, row);
        }
        if(strncmp(row, "Content-Disposition: attachment;", strlen("Content-Disposition: attachment;")) == 0){
            curr_attachment_idx++;
        }
        //row_count++;
    }

    // Search file for each attachment found
    // then delete it them
    for(int i = 0; i <= attachment_count - 1; i++) {
        searchFile(attachments[i]);
        remove(attachments[i]);
    }

    fclose(file);
    return 1;
}