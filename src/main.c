#include <stdio.h>
#include "../include/validateFile.h"
#include "../include/searchFile.h"

int main(int argc, char **argv) {
    if(validateFile(argc, argv) == 0){
        return 0;
    }

    FILE *fptr;
    fptr = fopen(argv[1], "r");

    searchFile(fptr);

    fclose(fptr);

    return 0;
}
