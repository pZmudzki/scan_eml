#include <time.h>
#include <stdio.h>
#include <string.h>
#include "../../include/saveLog.h"

char *currTime(){
    time_t raw_time;
    struct tm *time_info;
    time(&raw_time);
    time_info = localtime(&raw_time);
    char *time_str = asctime(time_info);
    time_str[strlen(time_str) - 1] = '\0';
    return time_str;
}

void saveLog(const char *text){
    FILE *fp;
    fp = fopen("log.txt", "a");

    fprintf(fp, "%s", text);

    fclose(fp);
}