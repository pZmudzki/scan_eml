#ifndef SCAN_EML_EXTRACTFILES_H
#define SCAN_EML_EXTRACTFILES_H

#endif //SCAN_EML_EXTRACTFILES_H

/***********************************************
extracts file attachments from .eml file
@param dir - path to .eml file
@param attachments - list of attachments
@return 0 - if error, 1 - if successful
***********************************************/
int extract_and_search_attachments(const char *dir);

