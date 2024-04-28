#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/validateFile.h"
#include "../../include/saveLog.h"

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

int validateLinuxFile(const char *filepath){
    // variable for storing file command result
    char command_output[250];
    char command[100] = "file -b ";
    char *valid_format = "SMTP mail";
    FILE *fp_cmd;

    // concatenate command with filepath
    strcat(command, filepath);

    // open commandline stream
    fp_cmd = popen(command, "r");
    if(fp_cmd == NULL){
        printf("Failed to check file format.");

        saveLog(currTime());
        saveLog(": Failed to check file format\n");
        exit(0);
    }

    // get file command output directly from terminal
    fgets(command_output, sizeof(command_output), fp_cmd);

    // iterate through command_output and valid_format
    // check if string are the same
    for(int i = 0; i < strlen(valid_format); i++){
        if(command_output[i] != valid_format[i]){
            return 0;
        }
    }

    // close stream
    pclose(fp_cmd);

    return 1;
}

// return 1 if file passes validation
// return 0 if file do not pass validation
int validateFile(int argc, char **argv){
    if(argc > 2) {
        printf("Please enter a file path without spaces!\n");

        saveLog(currTime());
        saveLog(": Wrong program argument format (should be without spaces)\n");
        return 0;
    }
    if(fopen(argv[1], "r") == NULL) {
        printf("File doesn't exist!\n");

        saveLog(currTime());
        saveLog(": File doesn't exist!\n");
        return 0;
    }

    // Checking for linux OS with
    // __linux__ macro
    #ifdef __linux__
        if(!validateLinuxFile(argv[1])){
            printf("Wrong file format! Please enter .eml file.\n");

            saveLog(currTime());
            saveLog(": Wrong file format!\n");
            return 0;
        }

    // Checking for windows OS with
    // _WIN32 macro
    #elif _WIN32
        if(!validateWindowsFile(argv[1])){
            printf("Wrong file format! Please enter .eml file.\n");

            saveLog(currTime());
            saveLog(": Wrong file format!\n");
            return 0;
        }

    // Throw an error if user isn't on LINUX/WINDOWS
    #else
        printf("Your OS is incompatible!");

        saveLog(currTime());
        saveLog(": Detected incompatible OS! Please use Linux or Windows!\n");
        return 0;
    #endif
    return 1;
}

