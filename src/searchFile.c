#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/searchFile.h"
#include "../include/validatePesel.h"
#include "../include/saveLog.h"

#define PESEL_MAX_LENGTH 11

const char * getFileNameFromDir(const char *dir){
    int dir_length = (int)(strlen(dir) - 1);
    int filename_length = 0;

    for(int i = dir_length; i >= 0 && dir[i] != '/'; i--){
        filename_length++;
    }

    char *filename = (char *)malloc(filename_length + 1);
    if (filename == NULL) {
        // Handle memory allocation error
        return NULL;
    }

    for (int i = 0; i < filename_length; i++) {
        filename[i] = dir[dir_length - filename_length + i + 1];
    }
    filename[filename_length] = '\0'; // Null-terminate the string

    return filename;
}

void searchFile(char *dir){
    FILE *fp;
    fp = fopen(dir, "r");

    printf("\nFile \"%s\":\n", getFileNameFromDir(dir));

    // save curr event to a file
    saveLog(currTime());
    saveLog(": Searching File \"");
    saveLog(getFileNameFromDir(dir));
    saveLog("\"\n");

    int pesel_found = 0;

    // row has 2000 space just to be safe that
    // everything in file will be scanned
    char row[2000];
    int row_count = 0;

    // currently scanned characters sequence
    char curr_sequence[PESEL_MAX_LENGTH + 1] = {0};
    // keep track of curr_sequence next character index to be place in
    int curr_idx = 0;

    while(!feof(fp)){
        // get row from a file
        fgets(row, 2000, fp);
        row_count++;
        // iterate through a row
        for(int i = 0; row[i] != '\n'; i++){
            // check if row[i] is a number
            if(row[i] <= '9' && row[i] >= '0'){
                curr_sequence[curr_idx] = row[i];
                curr_idx++;
            } else {
                // reset sequence
                curr_idx = 0;
            }
            // found 11 nums in a row
            if(curr_idx == PESEL_MAX_LENGTH){
                if(validatePesel(curr_sequence) == 1){
                    printf("Pesel found: %s Line: %d\n", curr_sequence, row_count);

                    saveLog(currTime());
                    saveLog(": Pesel found: ");
                    saveLog(curr_sequence);
                    saveLog(" Line: ");

                    char count_string[10];
                    sprintf(count_string, "%d", row_count);

                    saveLog(count_string);
                    saveLog("\n");

                    pesel_found = 1;
                }
                curr_idx = 0;
            }
        }
    }
    if(pesel_found == 0){
        printf("No pesel number was found!\n");

        saveLog(currTime());
        saveLog(": No pesel number was found!\n");
    }
    fclose(fp);
}