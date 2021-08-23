#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>

void sectionCards();
void sectionCardsReverse();
int deal_cards();
void generateRandom();
char menu();
void howToPlay();
void delay(int);
void printDelay(char[],int);


int cards[21];
int cards1[7];
int cards2[7];
int cards3[7];
int n=21;
char str[200];

int main()
{
    system("clear");

    char menuChoice;
    menuChoice = menu();

    system("clear");

    switch(menuChoice)
    {
        case '1':   break;

        case '2':   howToPlay(); 
                    main();
                    break;

        case '3':   exit(0);
                    //return 0;
    }


    int i,j,k,choice;
    char charChoice;
    
    //Random numbers for array
    generateRandom();
   
    printf("\n");

    printf("\n  _________________________________________________________________________________________________________________________________________________________ ");
    printf("\n |                                                                                                                                                         |");
    printf("\n |                                                                                                                                                         |\n");
    
    //Printing all numbers in array
    printf(" |");
    for(i=0;i<n;i++)
    {
        printf("%7d",cards[i]);delay(15);
    }
    printf("      |");

    printf("\n |                                                                                                                                                         |");
   // printf("\n |                                                                                                                                                         |");
    printf("\n |_________________________________________________________________________________________________________________________________________________________|");
    //printf("\n -----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n  ");
    
    //printf("\n\n Pick any number from above and remember it.\n\n");
    strcpy(str,"\n\n Pick any number from above and remember it.\n\n");
    printDelay(str,5);

    //printf("\n\n Press any key to conitnue..\n\n");
    strcpy(str,"\n\n Press any key to conitnue..\n\n");
    printDelay(str,5);
    
    getch();

    int temp;

    for(i=0;i<3;i++)
    {
        choice = deal_cards();  //Display to user
        
        //Put cards into 3 sections
        sectionCards();

        //Reverse cards
        j=0,k=7-1;
        while(j<k)
        {
            //swap
            temp = cards1[j];
            cards1[j] = cards1[k];
            cards1[k] = temp;

            //swap
            temp = cards2[j];
            cards2[j] = cards2[k];
            cards2[k] = temp;

            //swap
            temp = cards3[j];
            cards3[j] = cards3[k];
            cards3[k] = temp;

            //update i and j
            j++;  
            k--;  
        }

    
        switch(choice)
        {
            //Rearrange cards
            case 1: for(j=0;j<7;j++)    //If it is in 1st set then swap it with 2nd
                    {
                        temp = cards1[j];
                        cards1[j] = cards2[j];
                        cards2[j] = temp;
                    }
                    break;

            case 3: for(j=0;j<7;j++)    //If it is in 3rd set then swap it with 2nd
                    {
                        temp = cards3[j];
                        cards3[j] = cards2[j];
                        cards2[j] = temp;
                    }
                    break;
        }

        //Put 3 section cards back into the main card array
        sectionCardsReverse();
    }

    int x = cards[10];
    int digits=0;
    while(x>0)
    {
       digits++;
       x=x/10;
     }

    //printf(" \n\n\n****** The number you picked was : '%d' ******\n\n",cards[10]);
    int time = 40;
    system("clear");
    printf("\n\n  __________________________________________________________ ");delay(time);
    printf("\n |                                                          |");delay(time);
    printf("\n |                                                          |");delay(time);
    if(digits == 2)
    {
           printf("\n |              \033[0;33mTHE NUMBER YOU PICKED WAS  -  %d\033[0m            |",cards[10]);delay(time);
    }
    else
    { 
        //printf("\033[0;31m %d\033[0m",cards[10]);
        printf("\n |             \033[0;33mTHE NUMBER YOU PICKED WAS  -  %d\033[0m              |",cards[10]);delay(time);
    }
    printf("\n |                                                          |");delay(time);
    printf("\n |__________________________________________________________|");delay(time);
    //printf("\n ------------------------------------------------------------ ");delay(time);
    
    //End the game
    printf("\n\n\n *** Press any key to continue *** \n\n");
    getch();

    main();
    
    return 0;
}

int deal_cards()
{
    system("clear");

    int i,j,k,choice;

    //Display numbers to user in 3 columns
    /*printf("\n\n\t______________________________________________\n");
    printf("\n\t    column 1 \t   column 2 \t column 3\n");
    printf("\t______________________________________________\n\n");
    */

    printf("\n\n\t ____________________________________________\n\t|                                            |\n\t|    column 1 \t   column 2 \t column 3    | \n\t|____________________________________________|\n\t|              |              |              | \n");
    //printDelay(str,0);
    k=0;
    printf("\t|");
    for(i=0;i<7;i++)
    {
        for(j=0;j<3;j++)
        {
            //Find number of digits for number 
            int dig=0;
            int x = cards[k];
            while(x>0)
            {
                dig++;
                x=x/10;
            }

            //Print the number in table
            if(dig==2)
            {
                printf("      %d      |",cards[k]);delay(15);
            }
            else if(dig==1)
            {
                printf("      %d       |",cards[k]);delay(15);
            }
            
            k++;
        }
        if(i==6)
            continue;

        // 14 spaces
        printf("\n\t|              |              |              |\n\t|");
        
    }
    //printf("\n\t|              |              |              | ");
    printf("\n\t|______________|______________|______________|");

    //Loop to ensure correct inputs are given
    do
    {
        //printf("\n\n\n In which column is your number ? : ");
        strcpy(str,"\n\n\n In which column is your number :  ");
        printDelay(str,10);
        scanf("%d",&choice);

        if(choice<1 || choice>3)
        {
            //printf("\n\n ** Please enter a valid column number **\n");
            strcpy(str,"\n\n ** Please enter a valid column number **\n");
            printDelay(str,10);
        }

    }while(choice<1 || choice>3);
    
    return choice;
}

//Store numbers in array in 3 different arrays for 3 different columns
void sectionCards()
{
    int i,j,k,temp;

    for(i=0,j=0;i<n;i+=3,j++)
    {
        cards1[j] = cards[i];
    }

    for(i=1,j=0;i<n;i+=3,j++)
    {
        cards2[j] = cards[i];
    }

    for(i=2,j=0;i<n;i+=3,j++)
    {
        cards3[j] = cards[i];
    }
}

//Switch back the numbers in 3 arrays to 1 array
void sectionCardsReverse()
{
    int i,j,k,temp;

    for(i=20,j=0; j<7; i--,j++)
    {
        cards[i] = cards1[j];
    }
    for(j=0; j<7; i--,j++)
    {
        cards[i] = cards2[j];
    }
    for(j=0; j<7; i--,j++)
    {
        cards[i] = cards3[j];
    }
}

void delay(int time)
{
    clock_t goal = time + clock();
        while (goal > clock())
            ;   
    // this function will create a pause in the runtime process for the number of milliseconds that is given in 'time'

}

void printDelay(char str1[], int delayTime)
{
    int c;
    delayTime = 5;
    for (c = 0; str1[c] != '\0'; c++) 
    {    
        printf("%c", str1[c]);   
        //fflush(stdout); 
        delay(delayTime);    
    }      
}


char menu()
{
    char choice;
    int time=10;
    //char term;
    //char str[100];
    
    //printf("\033[0;33m"); //YELLOW
    // *** YELLOW COLORED BORDER ***
    printf("\n\n  \033[0;33m__________________________________________________________ ");delay(time);
    printf("\n \033[0;33m|\033[0m                                                          \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                          \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                          \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m         *********\033[0;33m GUESS THE NUMBER GAME \033[0m********         \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                          \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                          \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                          \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m         1.    Start the Game                             \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                          \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m         2.    How to play                                \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                          \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m         3.    Back to Main Menu                          \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                          \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                          \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|__________________________________________________________|\033[0m");delay(time);
    //printf("\n ------------------------------------------------------------ ");delay(time);

    menuLabel:
    printf("\n\n Enter your choice : ");
    scanf(" %c",&choice);

    // if a character is entered or a number is entered that's not in given choices
    if(choice!='1' && choice!='2' && choice!='3')
    {
        printf("\n\n Please enter appropriate values. Press any key to continue ");
        goto menuLabel;
    }
    system("clear");

    return choice;
}

void howToPlay()
{
    int time = 10;

   //printf("\033[0;33m"); //YELLOW
    // *** YELLOW COLORED BORDER ***

    printf("\n\n  \033[0;33m_____________________________________________________________________________________________________________ ");delay(time);
    printf("\n \033[0;33m|\033[0m                                                                                                             \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                                                                             \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                                                                             \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                 *********\033[0;33m GUESS THE NUMBER GAME \033[0m********                                    \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                                                                             \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                                                                             \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                                                                             \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m        A list of 21 numbers will be displayed to the player                                                 \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                                                                             \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m        Player has to pick any one number from the list and remember it                                      \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                                                                             \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                                                                             \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m        Game will then show the player the same list seperated in 3 columns                                  \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                                                                             \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m        Player will select the column in which the chosen number is present                                  \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                                                                             \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                                                                             \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m        Game will show such columns total 3 times and player has to select the right column each time        \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                                                                             \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                                                                             \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m        In the end Game will produce the number that the player had picked                                   \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                                                                             \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                                                                             \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|\033[0m                                                                                                             \033[0;33m|\033[0m");delay(time);
    printf("\n \033[0;33m|_____________________________________________________________________________________________________________|\033[0m");delay(time);
    //printf("\n ---------------------------------------------------------------------------------------------------------------");delay(time);

    printf("\n\n  Press any key to go back  \n\n");
    getch();
}

void generateRandom()
{
    int upper=50,lower=1;
    int count=0;
    int i,j;
    int randNum,found;
    
    /*for(i=0;i<n;i++)
    {
        cards[i] = (rand()% (upper-lower+1)) + lower;
    }*/
    srand(time(0));

    while(count <21) 
    { 
        randNum = (rand() % (upper-lower+1) + lower); //Generate a random number 
        found =0; //assume the random number hasnt been generated 
            
        //make sure the random number hasnt already been generated 
        for (i = 0; i < 21; i++) 
        { 
            if(cards[i] ==randNum) 
            { 
                //printf("\n copy found \n");
                found =1; 
                break; //once we have located the number we dont need to continue checking 
            } 
        } 
            
        //we have a new random number 
        if(found==0) 
        { 
            cards[count] =randNum; 
            count++; 
        }

        //If foun==1 means if a number is repeated then count will not get incremented 
    }

    return;
}