#include <stdio.h>
#include "../include/validateFile.h"
#include "../include/searchFile.h"

int main(int argc, char **argv) {
    if(validateFile(argc, argv) == 0){
        return 0;
    }

    searchFile(argv[1]);

    return 0;
}
