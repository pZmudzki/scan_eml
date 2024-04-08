#include <stdio.h>
#include "../include/validateFile.h"
#include "../include/validatePesel.h"

int main(int argc, char **argv) {
    if(validateFile(argc, argv) == 0){
        return 0;
    }
    char *example_pesel = "12345678999";

    if(validatePesel(example_pesel) == 0){
        printf("zly pesel");
    } else{
        printf("dobry pesel");
    };
    return 0;
}
