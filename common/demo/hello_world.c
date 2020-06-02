#include <stdio.h>

#define NAMELEN 40

void getUserInputFileName(char *fileName)
{
    do
    {
        scanf("%s", fileName);
    } while (getchar() != '\n');

    printf("filename in function = %s", fileName);
}

int main(void)
{
    printf("Hello_World\n");

    char filename[NAMELEN];
    getUserInputFileName(filename);
    printf("File name = %s", filename);

    printf("\\\\");

    return 0;
}
