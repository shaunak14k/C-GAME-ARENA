#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

char mainMenu();
void credits();

int main()
{
    system("clear");

    char mainMenuChoice;
    mainMenuChoice = mainMenu();

    char montyHall[] = "monty_hall.exe";
    char magic_number[] = "21_card_magic.exe";
    char quiz[] = "quiz.exe";
    char word_search[] = "word_search.exe";
    
    system("clear");

    switch(mainMenuChoice)
    {
        case '1':   system(montyHall);
                    break;
        
        case '2':   system(word_search);
                    break;

        case '3':   system(magic_number);
                    break;

        case '4':   system(quiz);
                    break;

        case '5':   credits();
                    break;          

        case '6':   system("clear");
                    printf("\n\n Exited from the game \n\n");   
                    exit(0);
                    //return 0;
    }

    main();

    return 0;
}

char mainMenu()
{
    //printf("\033[0;31m %d\033[0m",cards[10]);
    char choice;
    //char term;
    //char str[100];
    printf("\n\n  ______________________________________________________________________________________ ");
    printf("\n |                                                                                      |");
    printf("\n |                                                                                      |");
    printf("\n |                                                                                      |");
    printf("\n |                                                                                      |");
    printf("\n |                               ****************************                           |");
    printf("\n |                               |                          |                           |");
    printf("\n |                               |        C - ARCADE        |                           |");
    printf("\n |                               |                          |                           |");
    printf("\n |                               ****************************                           |");
    printf("\n |                                                                                      |");
    printf("\n |                                                                                      |");
    printf("\n |                                                                                      |");
    printf("\n |             ------------------------------------------------------------             |");
    printf("\n |             |       |                                                  |             |");
    printf("\n |             | \033[0;32m  1  \033[0m |               \033[0;32mMONTY HALL PROBLEM\033[0m                 |             |");
    printf("\n |             |       |                                                  |             |");
    printf("\n |             ------------------------------------------------------------             |");
    printf("\n |                                                                                      |");
    printf("\n |             ------------------------------------------------------------             |");
    printf("\n |             |       |                                                  |             |");
    printf("\n |             | \033[0;36m  2  \033[0m |                \033[0;36mWORD SEARCH GAME\033[0m                  |             |");
    printf("\n |             |       |                                                  |             |");
    printf("\n |             ------------------------------------------------------------             |");
    printf("\n |                                                                                      |");
    printf("\n |             ------------------------------------------------------------             |");
    printf("\n |             |       |                                                  |             |");
    printf("\n |             | \033[0;33m  3  \033[0m |                \033[0;33m21 NUMBERS MAGIC\033[0m                  |             |");
    printf("\n |             |       |                                                  |             |");
    printf("\n |             ------------------------------------------------------------             |");
    printf("\n |                                                                                      |");
    printf("\n |             ------------------------------------------------------------             |");
    printf("\n |             |       |                                                  |             |");
    printf("\n |             | \033[0;35m  4  \033[0m |                     \033[0;35mQUIZ\033[0m                         |             |");
    printf("\n |             |       |                                                  |             |");
    printf("\n |             ------------------------------------------------------------             |");
    printf("\n |                                                                                      |");
    printf("\n |             ------------------------------------------------------------             |");
    printf("\n |             |       |                                                  |             |");
    printf("\n |             |   5   |                    CREDITS                       |             |");
    printf("\n |             |       |                                                  |             |");
    printf("\n |             ------------------------------------------------------------             |");
    printf("\n |                                                                                      |");
    printf("\n |             ------------------------------------------------------------             |");
    printf("\n |             |       |                                                  |             |");
    printf("\n |             | \033[0;31m  6  \033[0m |                    \033[0;31m- QUIT -\033[0m                      |             |");
    printf("\n |             |       |                                                  |             |");
    printf("\n |             ------------------------------------------------------------             |");
    printf("\n |                                                                                      |");
    printf("\n |                                                                                      |");
    printf("\n |                                                                                      |");
    printf("\n |______________________________________________________________________________________|");
    //printf("\n ------------------------------------------------------ ");

    mainMenuLabel:
    printf("\n\n Enter number of the game you want to play : ");
    scanf(" %c",&choice);

    // if a character is entered or a number is entered that's not in given choices
    if(choice!='1' && choice!='2' && choice!='3' && choice!='4' && choice!='5' && choice!='6')
    {
        printf("\n\n Please enter appropriate values ");
        goto mainMenuLabel;
    }

    return choice;
}

void credits()
{
    printf("\n\n  \033[0;36m_______________________________________________________________ ");
    printf("\n \033[0;36m|                                                               \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                                                               \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                                                               \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                     ******\033[0;36m CREDITS \033[0m******                     \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                                                               \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                                                               \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                                                               \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m           **\033[0;31m Design & Development \033[0m**                          \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                                                               \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                                                               \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                \033[0;32mProject Team Lead -\033[0m                            \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                                                               \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                         Shaunak Khatavkar                     \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                                                               \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                                                               \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                \033[0;32mTeam Members -\033[0m                                 \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                                                               \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                         Aditya Sodani                         \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                                                               \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                         Aishwarya Shahane                     \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                                                               \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                         Akash Shirude                         \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                                                               \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                         Kirti Alkari                          \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                                                               \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                                                               \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                                                               \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m            **\033[0;31m Guidance \033[0m**                                     \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                                                               \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                  Prof. Premanand Ghadekar                     \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                                                               \033[0;36m|\033[0m");
    printf("\n \033[0;36m|\033[0m                                                               \033[0;36m|\033[0m");
    printf("\n \033[0;36m|_______________________________________________________________|\033[0m");
    //printf("\n ---------------------------------------------------------------------------------------------------------------");

    printf("\n\n  Press any key to go back  \n\n");
    getch();
}