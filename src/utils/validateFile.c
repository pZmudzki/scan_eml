#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/validateFile.h"

int validateWindowsFile(char *filepath){
    char *eml = "lme";
    int path_length = (int)strlen(filepath);


    int j = 0;
    for(int i = path_length - 1; filepath[i] != '.'; i--){
        if(filepath[i] != eml[j]){
            return 0;
        }
        j++;
        //printf("%c", filepath[i]);
    }

    printf("\n");
    return 1;
}

int validateLinuxFile(char *filepath){}

// return 1 if file passes validation
// return 0 if file do not pass validation
int validateFile(int argc, char **argv){
    if(argc > 2) {
        printf("Please enter a file path without spaces!\n");
        return 0;
    }
    if(fopen(argv[1], "r") == NULL) {
        printf("File doesn't exist!\n");
        return 0;
    }

    // Checking for linux OS with
    // __linux__ macro
    #ifdef __linux__
        printf("Hey Geek it seems that you are working on a Linux OS.\n");

    // Checking for windows OS with
    // _WIN32 macro
    #elif _WIN32
        if(!validateWindowsFile(argv[1])){
            printf("Wrong file format! Please enter .eml file.\n");
            return 0;
        }

    // Throw an error
    #else
        printf("Your OS is not compatible!");

    #endif
    return 1;
}

