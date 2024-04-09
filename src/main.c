#include <stdio.h>
#include "../include/validateFile.h"
#include "../include/validatePesel.h"

int main(int argc, char **argv) {
    if(validateFile(argc, argv) == 0){
        return 0;
    }

    char *example_pesel = "03211807116";

    if(validatePesel(example_pesel) == 0){
        printf("correct pesel");
    } else {
        printf("wrong pesel");
    }
    return 0;
}
