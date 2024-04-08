#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/validatePesel.h"

#define PESEL_MAX_LENGTH 11

// return 1 if pesel passes validation
// return 0 if pesel do not pass validation

int validatePesel(char pesel[]){
    int length = 0; // pesel length
    char psl[PESEL_MAX_LENGTH + 1];
    int parsed_pesel[PESEL_MAX_LENGTH];

    strcpy(psl, pesel);

    //printf("%l", strtol(&pesel[0], NULL, 10);
    printf("%d", atoi(&psl[1]));
    //printf("%c", pesel[2]);
    // calc pesel length and parse it to int arr
    for(int i = 0; pesel[i] != '\0'; i++){
        int parsed_char = atoi(&pesel[i]);
        //printf("%d", pesel[2]);
        //parsed_pesel[i] = parsed_char;
        length++;
    }

    // pesel number always has to be 11 digits
    if(length != PESEL_MAX_LENGTH){
        return 0;
    }

    return 1;
}