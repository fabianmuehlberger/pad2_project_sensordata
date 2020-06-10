#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRINGLEN 256

typedef struct Data
{
    int index;
    int validationCheck;
    int timeStampMS;

    int gyro_X;
    int gyro_Y;
    int gyro_z;

    int acc_X;
    int acc_Y;
    int acc_Z;

    int mag_X;
    int mag_Y;
    int mag_Z;

} Data;

Data writeDataToStructureArray(char *buffer);

void printSomeData(Data someData);

void printAnoterString(char *anotherString);

int main(void)
{
    char string[STRINGLEN];

    char *pEnd;
    char *curser;

    Data somedata;

    char anotherString[10] = "ffffff4";
    curser = anotherString;

    strcpy(string, "1;0;5;0;fffffff4;569;ffffffea;ffffffd9;fffffff5;0000019c;0000004b;fffffb8c");

    printf("string = %s\n", string);
    printf("anotherString = %s\n", anotherString);

    //CONVERSION:



    somedata = writeDataToStructureArray(string);

    printSomeData(somedata);
    return 0;
}
void printAnoterString(char *anotherString)
{
    char *curser;
    curser = anotherString;

    long int number;

    number = strtol(curser, NULL, 16);

    printf("%lu", number);
}

Data writeDataToStructureArray(char *buffer)
{
    Data tmpData;

    char *curser;
    char seperator[] = ";";

    curser = strtok(buffer, seperator);
    tmpData.index = atof(curser);

    curser = strtok(NULL, seperator);
    tmpData.validationCheck = (int)strtol(curser, NULL, 16);
    
    curser = strtok(NULL, seperator);
    tmpData.timeStampMS = (int)strtol(curser, NULL, 16);
    
    curser = strtok(NULL, seperator);
    tmpData.gyro_X = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.gyro_Y = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.gyro_z = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.acc_X = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.acc_Y = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.acc_Z = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.mag_X = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.mag_Y = (int)strtol(curser, NULL, 16);

    curser = strtok(NULL, seperator);
    tmpData.mag_Z = (int)strtol(curser, NULL, 16);

    return tmpData;
}

void printSomeData(Data someData)
{
    printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
           someData.index,
           someData.validationCheck,
           someData.timeStampMS,
           someData.acc_X,
           someData.acc_Y,
           someData.acc_Z,
           someData.gyro_X,
           someData.gyro_Y,
           someData.gyro_z,
           someData.mag_X,
           someData.mag_Y,
           someData.mag_Z);
}