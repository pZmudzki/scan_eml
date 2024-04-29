#ifndef SCAN_EML_SAVELOG_H
#define SCAN_EML_SAVELOG_H

/***********************************************
saves provided message to log.txt file
@param message - string value to append to file
@return void
***********************************************/
void saveLog(const char *message);

/***********************************************
when called, returns current date and time
@return current date and time in string format
***********************************************/
char *currTime();

#endif //SCAN_EML_SAVELOG_H
