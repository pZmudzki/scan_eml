#ifndef SCAN_EML_EXTRACTFILES_H
#define SCAN_EML_EXTRACTFILES_H

#endif //SCAN_EML_EXTRACTFILES_H

/***********************************************
extracts file attachments from .eml file
@param dir - path to .eml file
@param attachments - list of attachments
@return 0 - if error, 1 - if successful
***********************************************/
int extract_attachments(const char *dir, char **attachments);

/***********************************************
extracts file attachments from .eml file
@param dir - path to .eml file
@return 0 - if no attachments found, 1 - more than 1 attachment
***********************************************/
int count_attachments(const char *dir);
