#include <stdio.h>
#include "../include/validateFile.h"
#include "../include/searchFile.h"

int main(int argc, char **argv) {
    if(validateFile(argc, argv) == 0){
        return 0;
    }

    printf("Scanning for pesel...\n");
    searchFile(argv[1]);
    printf("\nFinished scanning.\n");
    return 0;
}
