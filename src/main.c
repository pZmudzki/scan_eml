#include <stdio.h>
#include "../include/validateFile.h"
#include "../include/searchFile.h"
#include "../include/extractFiles.h"

#define MAX_FILES 500

typedef struct found_file FOUND_FILE;

int main(int argc, char **argv) {

    if(validateFile(argc, argv) == 0){
        return 0;
    }

    int found_attachments_count = 1;
    char *attachments[found_attachments_count];

    printf("Extracting files...");
    if(!extract_attachments(argv[1], attachments)){
        return 0;
    }

    printf("N of attachments: %d\n", found_attachments_count);
    for(int i = 0; i <= found_attachments_count - 1; i++){
        printf("File %d: %s\n", i, attachments[i]);
    }


    printf(" DONE\n");

    printf("Scanning for pesel...\n");
    searchFile(argv[1]);
    printf("\nFinished scanning.\n");
    return 0;
}
