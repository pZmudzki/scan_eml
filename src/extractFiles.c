#include <stdio.h>
#include <string.h>

#include "../include/extractFiles.h"
#include "../include/base64.h"

int extract_attachments(const char *dir) {
    FILE *file = fopen(dir, "r");
    if (file == NULL) {
        printf("Error opening file");
        return 0;
    }

    char row[1024];
    char attachment_name[256];
    int in_attachment_header = 0;
    int found_plain_text = 0;
    int in_attachment_content = 0;

    while (fgets(row, sizeof(row), file) != NULL) {

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

        if(strncmp(row, "Content-Type: application/", strlen("Content-Type: application/")) == 0){
            in_attachment_header = 1;
        } else if(strncmp(row, "Content-Type: text/plain", strlen("Content-Type: text/plain")) == 0){
            found_plain_text = 1;
        }

        if(found_plain_text && strncmp(row, "Content-Transfer-Encoding: base64", strlen("Content-Transfer-Encoding: base64")) == 0){
            in_attachment_header = 1;
        }

        if (strncmp(row, "Content-Disposition: attachment", strlen("Content-Disposition: attachment")) == 0) {
            // Extract attachment name
            sscanf(row, "Content-Disposition: attachment; filename=\"%[^\"]\"", attachment_name);
        }

        if(in_attachment_header && strncmp(row, "\n", 1) == 0) {
            in_attachment_content = 1;
            in_attachment_header = 0;
        }


    }
    fclose(file);
    return 1;
}