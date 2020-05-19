//this programm checks every library in the project and runns a test function incuded int the libraries

#include <stdio.h>
#include "my_graphics/my_graphics.h"
#include "my_file_io/my_file_io.h"
#include "my_validation/my_validation.h"


int main(void)
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
    
    return 0;
}