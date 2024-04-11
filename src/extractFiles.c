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

    char line[1024];
    int in_attachment = 0;
    char attachment_name[256];

    while (fgets(line, sizeof(line), file) != NULL) {
        if (strncmp(line, "Content-Type: application/", strlen("Content-Type: application/")) == 0) {
            in_attachment = 1;
        } else if (strncmp(line, "Content-Transfer-Encoding: base64", strlen("Content-Transfer-Encoding: base64")) == 0 && in_attachment) {
            char attachment_data[strlen(line) + 1];

            while (fgets(line, (int)strlen(line), file) != NULL) {
                if (strncmp(line, "--", 2) == 0) {
                    break;
                }
                printf("%s\n", line);
                strcat(attachment_data, line);
            }

            //printf("%s length: %llu\n", attachment_data, strlen(line));

            // Decode attachment_data (base64 encoded) into attachment_data_decoded
            char *attachment_data_decoded =  base64_decode(attachment_data);

            // Write attachment_data_decoded to a file

            FILE *attachment_file = fopen(attachment_name, "wb");
            fwrite(attachment_data_decoded, 1, strlen(attachment_data_decoded), attachment_file);
            fclose(attachment_file);

            // Reset variables for next attachment
            in_attachment = 0;
            attachment_name[0] = '\0';
            attachment_data[0] = '\0';
        } else if (strncmp(line, "Content-Disposition: attachment", strlen("Content-Disposition: attachment")) == 0) {
            // Extract attachment name
            sscanf(line, "Content-Disposition: attachment; filename=\"%[^\"]\"", attachment_name);
        }
    }

    fclose(file);
    return 1;
}