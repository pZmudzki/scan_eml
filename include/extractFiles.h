#ifndef SCAN_EML_EXTRACTFILES_H
#define SCAN_EML_EXTRACTFILES_H

/***********************************************
extracts file attachments from .eml file
@param directory/path to .eml file
@return 0 - if error, 1 - if successful
***********************************************/
int extract_attachments(const char *dir);

#endif //SCAN_EML_EXTRACTFILES_H
