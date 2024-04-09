#include <stdio.h>
#include "../../include/validatePesel.h"

#define PESEL_MAX_LENGTH 11

// return 1 if pesel passes validation
// return 0 if pesel do not pass validation

int validatePesel(char *pesel){
    int length = 0; // pesel length
    int parsed_pesel[PESEL_MAX_LENGTH]; // parsed pesel from char to int array

    // calc pesel length and parse it to int arr
    for(int i = 0; pesel[i] != '\0'; i++){
        if(pesel[i] < '0' || pesel[i] > '9'){
            return 0;
        }
        parsed_pesel[i] = pesel[i] - '0'; // ASCII codes, for example: '1' (49) - '0' (48) = 1
        length++;
    }

    // pesel number always has to be 11 digits
    if(length != PESEL_MAX_LENGTH || parsed_pesel[4] > 3){
        return 0;
    }

    /*
     The last digit of pesel (controll digit) is created with this schema:

     example pesel: 0-2-0-7-0-8-0-3-6-2
     base digits: 1-3-7-9-1-3-7-9-1-3
     multiply n-th digit from pesel with n-th digit from "base digits"

     0   2   0   7   0   8   0   3   6   2
     *   *   *   *   *   *   *   *   *   *
     1   3   7   9   1   3   7   9   1   3
     =   =   =   =   =   =   =   =   =   =
     0   6   0   63  0   24  0   27  6   6

     if the result is 2 digits long the second digit stays

     x = 0 + 6 + 0 + 3 + 0 + 4 + 0 + 7 + 6 + 6 = 32

     if x is 2 digits long then the second digit stays

     10 - x = controll digit

     */

    int controll_digit = 10 - (parsed_pesel[0]*1 + parsed_pesel[1]*3 + parsed_pesel[2]*7 + parsed_pesel[3]*9 + parsed_pesel[4]*1 + parsed_pesel[5]*3 + parsed_pesel[6]*7 + parsed_pesel[7]*9 + parsed_pesel[8]*1 + parsed_pesel[9]*3) % 10;

    if(parsed_pesel[PESEL_MAX_LENGTH - 1] != controll_digit){
        return 0;
    }

    return 1;
}