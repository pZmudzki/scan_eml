#include <stdio.h>
#include "../include/validateFile.h"
#include "../include/searchFile.h"
#include "../include/extractFiles.h"
#include "../include/saveLog.h"


int main(int argc, char **argv) {

    if(validateFile(argc, argv) == 0){
        return 0;
    }

    printf("Scanning for pesel...\n");

    saveLog(currTime());
    saveLog(": Scanning for pesel...\n");

    searchFile(argv[1]);

    if(!extract_and_search_attachments(argv[1])){
        printf("\nError extracting attachments!\n");

        saveLog(currTime());
        saveLog(": Error extracting attachments!\n\n");

        return 0;
    } else {
        printf("\nFinished scanning.\n");

        saveLog(currTime());
        saveLog(": Finished scanning.\n\n");
    }

    return 0;
}
