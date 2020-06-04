//this programm checks every library in the project and runns a test function incuded int the libraries

#include <stdio.h>
#include "my_graphics.h"
#include "my_file_io.h"
#include "my_validation.h"


int main()
{
    printf("Start of main\n");

    //test of librarys
    if (my_file_io_Test())
    {
        printf("my_file_io Test OK\n");
    }

    if (my_graphics_Test())
    {
        printf("my_graphics Test OK\n");
    }
    
    if (my_validation_Test())
    {
        printf("my_validation Test OK\n");
    }

    char joice = 'a';
    printHelp();
    while(joice != 'e')
    {
        printf("\nuser input: ");
        scanf(" %c", &joice);

        switch(joice)
        {
            case 'p': printData();
            break;
            case 'h': printHelp();
            break;
            case 'e': printf("EXIT..."); return 0;
        }
    }

return 0;
}