#include <stdio.h>
#include "../include/validateFile.h"

int main(int argc, char **argv) {
    if(validateFile(argc, argv) == 0){
        printf("nieprzeszlo");
        return 1;
    }
    printf("przeszlo");
    return 0;
}
