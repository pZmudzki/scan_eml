#include <stdio.h>
#include "../include/searchFile.h"
#include "../include/validatePesel.h"

#define PESEL_MAX_LENGTH 11

void searchFile(FILE *fp){

    char row[2000];

    int curr_idx = 0;
    char curr_sequence[PESEL_MAX_LENGTH + 1] = {0};

    printf("Scanning for pesel...\n");
    while(!feof(fp)){
        fgets(row, 2000, fp);
        //printf("%s\n", curr_sequence);
        for(int i = 0; row[i] != '\n'; i++){
            if(row[i] <= '9' && row[i] >= '0'){
                curr_sequence[curr_idx] = row[i];
                curr_idx++;
            } else {
                curr_idx = 0;
            }
            if(curr_idx == PESEL_MAX_LENGTH){
                if(validatePesel(curr_sequence) == 1){
                    printf("Correct: %s\n", curr_sequence);
                } else {
                    printf("Wrong: %s\n", curr_sequence);
                }
                curr_idx = 0;
            }
        }
    }
}