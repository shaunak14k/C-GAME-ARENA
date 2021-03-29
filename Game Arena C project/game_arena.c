#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<windows.h>
#include <unistd.h>
#include <process.h> 
#include <sys/types.h> /* for pid_t */
//#include <sys/wait.h> /* for wait */

char mainMenu();

int main()
{
    system("clear");

    char mainMenuChoice;
    mainMenuChoice = mainMenu();

    char montyHall[] = "monty_hall.exe";
    char magic_number[] = "21_card_magic.exe";
    
    system("clear");

    switch(mainMenuChoice)
    {
        case '1':   system(montyHall);
                    break;
        
        case '2':   system(magic_number);
                    break;

        case '3':   system("clear");
                    printf("\n\n Exited from the game \n\n");   
                    exit(0);
                    //return 0;
    }

    main();

    return 0;
}

char mainMenu()
{
    char choice;
    //char term;
    //char str[100];
    printf("\n\n  ____________________________________________________ ");
    printf("\n |                                                    |");
    printf("\n |                                                    |");
    printf("\n |                                                    |");
    printf("\n |             ****************************           |");
    printf("\n |             |        GAME ARENA        |           |");
    printf("\n |             ****************************           |");
    printf("\n |                                                    |");
    printf("\n |                                                    |");
    printf("\n |                                                    |");
    printf("\n |         -----------------------------------        |");
    printf("\n |         | 1 |    MONTY HALL PROBLEM       |        |");
    printf("\n |         -----------------------------------        |");
    printf("\n |                                                    |");
    printf("\n |         -----------------------------------        |");
    printf("\n |         | 2 |    GUESS THE NUMBER GAME    |        |");
    printf("\n |         -----------------------------------        |");
    printf("\n |                                                    |");
    printf("\n |         -----------------------------------        |");
    printf("\n |         | 3 |    QUIT                     |        |");
    printf("\n |         -----------------------------------        |");
    printf("\n |                                                    |");
    printf("\n |                                                    |");
    printf("\n |____________________________________________________|");
    //printf("\n ------------------------------------------------------ ");

    mainMenuLabel:
    printf("\n\n Enter number of the game you want to play : ");
    scanf(" %c",&choice);

    // if a character is entered or a number is entered that's not in given choices
    if(choice!='1' && choice!='2' && choice!='3')
    {
        printf("\n\n Please enter appropriate values ");
        goto mainMenuLabel;
    }

    return choice;
}