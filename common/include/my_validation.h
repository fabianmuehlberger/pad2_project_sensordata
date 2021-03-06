#ifndef _MY_VALIDATION_H_
#define _MY_VALIDATION_H_

#include "my_file_io.h"

#define FILE_TOKEN_AMOUNT 9

#define VALIDATION_TOKEN_ERR "Token check not passed"
#define VALIDATION_NEWLINE_ERR "no newline line ending"

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

int checkLineToken(char *fileLine);

int checkLineEnding(char *line);

int lineValidatonChecks(char *lineToValidate, int line, char *errorLogFileName);

void writeErrorLog(char *errorLogFileName, int line, int errorCode, char *errorMassage);

#endif