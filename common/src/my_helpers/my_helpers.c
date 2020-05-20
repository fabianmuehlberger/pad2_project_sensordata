#include <stdio.h>
#include <string.h>

#define LEN 100

char inputString(char *name)
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

int inputInt(int *value)
{
    do
    {
        scanf("%i", value);
    } while (getchar() != '\n');
    return *value;
}

char inputChar(char *c)
{
    do
    {
        scanf("%c", c);
    } while (getchar() != '\n');

    return *c;
}
