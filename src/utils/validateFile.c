#include <stdio.h>
#include <stdlib.h>
#include "../../include/validateFile.h"

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
    return 1;
}

