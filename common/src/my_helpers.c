#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sensor_config.h"
#include "my_structure.h"
#include <math.h>

#define LEN 100

char getStringFromStdin(char *name)
{
    char buffer[LEN];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        size_t len = strlen(buffer);
        if ((len > 0 && buffer[len - 1] == '\n') || buffer[len - 1 == '\r'])
        {
            buffer[--len] = '\0';
            sscanf(buffer, "%s", name);
        }
    }
    return *name;
}

int getIntFromStdin(int *value)
{
    do
    {
        scanf("%i", value);
    } while (getchar() != '\n');
    return *value;
}

char getCharFromStdin(char *c)
{
    do
    {
        scanf("%c", c);
    } while (getchar() != '\n');

    return *c;
}

void removeNewLineFromString(char *line)
{
    int new_line = strlen(line) - 1;
    if (line[new_line] == '\n')
    {
        line[new_line] = '\0';
    }
}

void getUserInputStringFromConsole(char *fileName)
{
    do
    {
        scanf("%s", fileName);
    } while (getchar() != '\n');
}

void allocateMemoryForRawDataArray(Raw_Data *tmp)
{
    Raw_Data *new = malloc(100 * sizeof(Raw_Data));
    if (new == NULL)
    {
        printf("No memory Left, sorry :(");
    }
    else
    {
        tmp = new;
    }
}

void allocateMemoryForCleanDataArray(Clean_Data *tmp)
{
    Clean_Data *new = malloc(100 * sizeof(Raw_Data));
    if (new == NULL)
    {
        printf("No memory Left, sorry :(");
    }
    else
    {
        tmp = new;
    }
}

void changeAccAxis(Clean_Data *tmp)
{
    //Change the rotation value of the accelerometer to -/+ 180 and move the Y axis '0' point to up.
    //Two different pieces of code are used depending on how your IMU is mounted.
    //If IMU is upside down

    //If IMU is up the correct way, use these lines
    tmp->AccXangle -= (float)180.0;
    if (tmp->AccYangle > 90)
        tmp->AccYangle -= (float)270;
    else
        tmp->AccYangle += (float)90;

    /*
	if (AccXangle >180)
		AccXangle -= (float)360.0;

		AccYangle-=90;
	if (AccYangle >180)
			AccYangle -= (float)360.0;
    */
}

Clean_Data convertRawToClean(Raw_Data rawData)
{
    Clean_Data tmpData;

    float rate_gyr_y = 0.0; // [deg/s]
    float rate_gyr_x = 0.0; // [deg/s]
    float rate_gyr_z = 0.0; // [deg/s]

    //Convert Gyro raw to degrees per second
    rate_gyr_x = (float)rawData.gyro_X * G_GAIN;
    rate_gyr_y = (float)rawData.gyro_Y * G_GAIN;
    rate_gyr_z = (float)rawData.gyro_Z * G_GAIN;

    //Calculate the angles from the gyro
    tmpData.gyroXangle += rate_gyr_x * DT;
    tmpData.gyroYangle += rate_gyr_y * DT;
    tmpData.gyroZangle += rate_gyr_z * DT;

    //Convert Accelerometer values to degrees
    tmpData.AccXangle = (float)(atan2(rawData.acc_Y, rawData.acc_Z) + M_PI) * RAD_TO_DEG;
    tmpData.AccYangle = (float)(atan2(rawData.acc_Z, rawData.acc_X) + M_PI) * RAD_TO_DEG;

    tmpData.CFangleX = 0.0;
    tmpData.CFangleY = 0.0;

    changeAccAxis(&tmpData);

    //Complementary filter used to combine the accelerometer and gyro values.
    tmpData.CFangleX = AA * (tmpData.CFangleX + rate_gyr_x * DT) + (1 - AA) * tmpData.AccXangle;
    tmpData.CFangleY = AA * (tmpData.CFangleY + rate_gyr_y * DT) + (1 - AA) * tmpData.AccYangle;

    return tmpData;
}

void printHelp()
{
    printf("\n1: Read SourceData File\n"
           "2: Read RawData File\n"
           "3: printing RawData\n"
           "4: printing CleanData\n"
           "5: help\n"
           "6: EXIT\n");
}

void loadingBar(int lines)
{
    if(lines==20000|lines==17500|lines==15000|lines==13500|lines==12000|lines==10000|lines==7500|lines==5000|lines==3500|lines==2500|lines==1000|lines==500|lines==250)
        {
            printf(".");
            if(lines==20000)
            {
                printf("\a");
            }
        }
}
