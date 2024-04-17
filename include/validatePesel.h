#ifndef SCAN_EML_VALIDATEPESEL_H
#define SCAN_EML_VALIDATEPESEL_H

/***********************************************
validates pesel (Polish id number)
@param pesel - string representing pesel id number
@return 0 - if wrong, 1 - if validated
***********************************************/
int validatePesel(char *pesel);

#endif //SCAN_EML_VALIDATEPESEL_H
