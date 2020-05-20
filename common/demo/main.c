#include <stdio.h>
#include "my_helpers/my_helpers.h"

void help();

int quitProgram();

int main(void)
{
    printf("Start of main\n");

    //variable to keep the main while loop going
    int alive = 1;

    while (alive != 0)
    {
        printf("_____WELCOME_____\n");
        help();
        printf("enter number to choose option");
    
        int auswahl = 0;
        inputInt(&auswahl);
        
        switch (auswahl)
        {
        case 1:
            printf("Option one\n");
            break;
        case 2:
            printf("Option two\n");
            break;
        case 3:
            printf("Option three\n");
            printf("show help\n");
            help();
        case 4:
            printf("Option 4 \n");
            alive = quitProgram();

        default:
            printf("wrong number, try again\n");
            break;
        }
    }

    return 0;
}

void help()
{
    printf("-1- Option one\n");
    printf("-2- Option two\n");
    printf("-3- Option three\n");
}

int quitProgram()
{
    char choice;
    printf("Are you shure you want to quit? [y, n]\n");
    scanf("%c", choice);
    
    if (choice == 'y')
    {
        printf("quitting....");
        return 1;
    }
    else
    {
        printf("return to main\n");
        return 0;
    }  
}
