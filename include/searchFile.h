#ifndef SCAN_EML_SEARCHFILE_H
#define SCAN_EML_SEARCHFILE_H

#include <stdio.h>

/***********************************************
searches through a file and displays pesel if found
@param dir - directory/path to file that will be scanned
@return none
***********************************************/
void searchFile(char *dir);

/***********************************************
extracts file name from passed file directory/path
@param dir - directory/path to file
@return string with extracted file name
***********************************************/
const char * getFileNameFromDir(const char *dir);

#endif //SCAN_EML_SEARCHFILE_H
