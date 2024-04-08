#include <stdio.h>
#include <stdlib.h>
#include "../include/validateFile.h"

// return 1 if file passes validation
// return 0 if file do not pass validation

int validateFile(int argc, char **argv){
    if(argc > 2) {
        printf("Please enter a file directory without spaces!\n");
        return 0;
    }
    if(fopen(argv[1], "r") == NULL){
        printf("File doesn't exist!\n");
        return 0;
    }

    int res = system("dir");
    printf("\n%d\n\n", res);
    //char *file_search_sys_command = "FILE" +
    //printf("\n%s\n\n", system("FILE %s", argv[1]))

    return 1;
}

