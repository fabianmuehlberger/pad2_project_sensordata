
#ifndef _MY_VALIDATION_H_
#define _MY_VALIDATION_H_
//test my_validation

//simple test funktion to show that my_validation exitst
int my_validation_Test();

// serches through file to check lines of the File
// returns a integer with number if Lines 
int checkLineCount(char *pFile);

// returns size of File in bytes
int checkFileSize(char *pFileSize);

//prints current directory with its files 
// might be usefull to find a file
void checkDirectory();


#endif