#include <stdio.h>
#include <stdlib.h>

int my_validation_Test()
{
    return 1;
}

int checkLineCount(FILE **pFileCount)
{
    int lineCount = 0;
    FILE *tmp = *pFileCount;
    char c = getc(tmp);
    while (c != EOF)
    {
        if (c == '\n')
        {
            lineCount++;
        }
        c = getc(tmp);
    }

    fclose(tmp);

    return lineCount;
}

int checkFileSize(FILE **pFileSize)
{
    long int fileSize = 0;
    FILE *tmp = *pFileSize;

    fseek(tmp, 0L, SEEK_END);
    fileSize = ftell(tmp);

    return fileSize;
}
