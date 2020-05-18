#include <stdio.h>
#include "my_graphics/my_graphics.h"
#include "my_file_io/my_file_io.h"

int main(void)
{
    printf("Start of main\n");

    //test of librarys
    my_file_io_Test();
    my_graphics_Test();
    
    return 0;
}