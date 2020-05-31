
//test my_validation
#ifndef _MY_VALIDATION_H_
#define _MY_VALIDATION_H_

//simple test funktion to show that my_validation exitst
int my_validation_Test();

// serches through file to check lines of the File
// returns a integer with number if Lines 
int checkLineCount(FILE *pFile);

// returns size of File in bytes
int checkFileSize(FILE *pFileSize);


#endif