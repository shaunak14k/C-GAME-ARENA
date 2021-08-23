#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
//#include <unistd.h>

//Functions
int switchDoor();
void drawDoors(int);
void delay(int);
void printDelay(char[],int);
void winLose(bool);
char menu();
void montyHallExplanation();
void howToPlay();
void readRecord();
void storeRecord(char,int);
void summaryTable();
void montyHallExplanation();

//Global Variables
int carDoor;
int i,j;
int door[3] = {0,0,0};  //Main array for doors
char ch;
int choice;
int optionDoor = -1;
char str[200];
int c;

//Variables used for file handling
int noOfSwitchPlayers, noOfNotSwitchPlayers;
int switchWinCount, notSwitchWinCount;
float percentSwitchWinCount, percentNotSwitchWinCount;

//bool n = false;

int main()
{
    system("clear");

    char menuChoice;
    menuChoice = menu();
    switch(menuChoice)
    {
        case '1':   system("clear");
                    break;

        case '2':   howToPlay();
                    main();
                    break;

        case '3':   montyHallExplanation();
                    main();
                    break;

        case '4':   summaryTable();
                    main();
                    break;

        case '5':   exit(0);
                    //return 0;
    } 

    int upper=2,lower=0;

    i=0,j=0,door[0]=0,door[1]=0,door[2]=0;
    

    //Generate random variable from 0 to 2 to assign car(1) at index of door[]
    //If srand() is not called then same sequenc will be generated every time
    srand(time(0));
    i = (rand()% (upper-lower+1)) + lower;

    //Assign car to a door
    //i=1;
    door[i] = 1;
    carDoor = i+1;
    
    // Print the door array
    printf("\n");
    for(i=0;i<3;i++)
    {
        printf("\t%d",door[i]);
    }
    //getch();

    //Draw the doors
    drawDoors(0);
   
    repeat:
    strcpy(str,"\n\n\n Which door do you want to open : ");
    printDelay(str,10);
    
    scanf("%d",&choice);

    //If character is entered or an integer is entered that does not exist in menu
    if(choice>3 || choice<1)
    {
        //printf("\n\n Please enter appropriate values ");
        strcpy(str,"\n\n Please enter appropriate values ");
        printDelay(str,10);
        goto repeat;
    }

    //Traverse doors other than door 1(index 0)
    for(i=0;i<3;i++)
    {
        //Select the door which does not have Car behind it (value 1)
        if(door[i] == 0 && choice-1 != i)
        {

            strcpy(str,"\n\n****************************************************************");
            printDelay(str,10);       

            strcpy(str,"\n\n Now I am going to open a door which has a Goat behind it ");
            printDelay(str,10);

            strcpy(str,"\n\n****************************************************************");
            printDelay(str,10);      

            strcpy(str,"\n\nPress any key to continue .. \n\n");
            printDelay(str,10);   
            getch();

            //Draw the doors
            //Sleep(2000);
            drawDoors(1);

            //printf("\n\n****************************************************************");
            printf("\n");
            strcpy(str,"\n\n Obviously the car is not behind Door ");
            printDelay(str,10);   
            printf("%d.",i+1);//Door number
            //printf("\n\n Car is definitely not behind Door '%d' ",i+1);
            
            break;
        }
    }

    //Assign value to optionDoor (the door that player can switch)
    int k;
    for(k=0;k<3;k++)
    {
        if(k!= choice-1 && k!=i)
            optionDoor = k+1;
    }
    
    strcpy(str,"\n\n****************************************************************");
    printDelay(str,10);  

    strcpy(str,"\n\n Before I open Door ");
    printDelay(str,10);
    printf("%d ",choice);//Print door number

    strcpy(str,", the door that you have selected\n\n I'm going to let you switch to Door ");
    printDelay(str,10);
    printf("%d if you like.",optionDoor);//Print option door number

    strcpy(str,"\n\n****************************************************************");
    printDelay(str,10);     
    

    /*printf("\n\n****************************************************************");
    printf("\n\n Before I open Door No.'%d', the door that you have selected\n\n I'm going to let you switch to another door if you like",choice);
    printf("\n\n****************************************************************");
    */
    switchDoor();
    
    printf("\n\n");

    //End the game
    printf("\n *** Press any key to continue ***\n\n");
    getch();

    main();

    return 0;
}

int switchDoor()
{
    //system("clear");
    strcpy(str,"\n\n Your original choice was 'Door-");
    printDelay(str,10); 
    printf("%d'",choice);//Print door number
    strcpy(str,", Do you want to switch to 'Door-");
    printDelay(str,10); 
    printf("%d'",optionDoor);//Print door number
    strcpy(str," ? (Y/N) : ");
    printDelay(str,10); 
    
    scanf(" %c",&ch);

    if(ch=='y' || ch=='Y')
    {  
        //printf("\n\n You decided to Switch to -> 'Door-%d",optionDoor);
        strcpy(str,"\n\n You decided to Switch to -> 'Door-");
        printDelay(str,10); 
        printf("%d",optionDoor);

        //printf("\n\n\n *** Press any key to Open the 'Door-%d'  ***",optionDoor);
        strcpy(str,"\n\n\n *** Press any key to Open the 'Door-");
        printDelay(str,10); 
        printf("%d'  ***",optionDoor);

        getch();

        //Sleep(2000);
        //Draw doors
        drawDoors(2); 

        //When OptionDoor has a car behind it        
        if(door[optionDoor-1] == 1)
        {
            //Game won
            winLose(true);

            //Call file funtion
            storeRecord('s',1);
        }
        //When option Door has a Goat behind it
        else
        {
            //Game Lost
            winLose(false);

            //Call file funtion
            storeRecord('s',0);
        }

        strcpy(str,"\n\n RECAP : You Originally picked Door ");
        printDelay(str,10);
        printf("%d",choice);
        strcpy(str," and then switched to Door ");
        printDelay(str,10);
        printf("%d",optionDoor);

        /*//Traverse all doors
        for(j=0;j<3;j++)
        {
            //Select the switched door 
            if(j!=choice-1 && j!=i)
            {
                //Sleep(2000);
                //Draw doors
                drawDoors(2); 
                
                if(door[j] == 1)
                {
                    //Game won
                    winLose(true);

                    //Call file funtion
                    storeRecord('s',1);
                }
                else
                {
                    //Game Lost
                    winLose(false);

                    //Call file funtion
                    storeRecord('s',0);
                }

                strcpy(str,"\n\n RECAP : You Originally picked Door ");
                printDelay(str,10);
                printf("%d",choice);
                strcpy(str," and then switched to Door ");
                printDelay(str,10);
                printf("%d",optionDoor);

                break;
            }
        }*/
    }
    else if(ch=='n' || ch=='N')
    {
        //printf("\n\n You decided to stick to your original choice -> 'Door-%d",choice);
        strcpy(str,"\n\n You decided to stick to your original choice -> 'Door-");
        printDelay(str,10); 
        printf("%d'",choice);
        
        //printf("\n\n\n *** Press any key to Open the 'Door-%d' ***",choice);
        strcpy(str,"\n\n\n *** Press any key to Open the 'Door-");
        printDelay(str,10); 
        printf("%d'  ***",choice);
        
        getch();

        //Sleep(2000);
        //Draw doors
        drawDoors(2);

        if(door[choice-1] == 1)
        {
            //Game won
            winLose(true);

            //Call file funtion
            storeRecord('d',1);
        }
        else
        {
            //Game Lost
            winLose(false);

            //Call file funtion
            storeRecord('d',0);
        }

        //Print recap of choices player made
        strcpy(str,"\n\n RECAP : You Originally picked Door ");
        printDelay(str,10);
        printf("%d",choice);
        strcpy(str," and then stayed with that door");
        printDelay(str,10);
        
    }
    else
    {
        //printf("\n\n Please enter 'Y' or 'N' \n");
        strcpy(str,"\n\n Please enter 'Y' or 'N' \n");
        printDelay(str,40); 
        
        switchDoor();
    }

    //repeat1:    
    //printf("\n\n Do you want to play again ? (Y/N) : ");
    /*strcpy(str,"\n\n Do you want to play again ? (Y/N) : ");
    printDelay(str,40); 
    
    scanf(" %c",&ch);
    if(ch=='Y' || ch=='y')
        main();
    else if(ch=='n' || ch=='N')
        printf("\n\n EXIT \n\n");
    else
        goto repeat1;
    */

    return 0;
}

void delay(int milliseconds)
{
    clock_t start = clock();

    while((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds);
    // this function will create a pause in the runtime process for the number of milliseconds that is given in 'time'

}

void printDelay(char str1[], int delayTime)
{
    delayTime = 3;
    for (c = 0; str1[c] != '\0'; c++) 
    {    
        printf("%c", str1[c]);   
        //fflush(stdout); 
        delay(delayTime);    
    }      
}

void winLose(bool win)
{
    if(win)
    {
        //printf("\n\n ***************************************");
        strcpy(str,"\n\n ***************************************");
        printDelay(str,10);
        printf("      \n |                                     |");

        //printf("\n\n |   Congratulations ! You Win a Car!   |");
        strcpy(str,"\n |   Congratulations!! You Win a CAR!  |");
        printDelay(str,40);

        //printf("\n\n ***************************************");
        printf("      \n |                                     |");
        strcpy(str,"\n ***************************************\n");
        printDelay(str,10);
    }
    else
    {
        //printf("\n\n ****************");
        strcpy(str,"\n\n ****************");
        printDelay(str,10);
        printf("    \n |              |");

        //printf("\n\n |   You Lose   |");
        strcpy(str,"\n |    LOSER!!   |");
        printDelay(str,40);
        
        //printf("\n\n ****************");
        printf("    \n |              |");
        strcpy(str,"\n ****************\n");
        printDelay(str,10);
    }
}

char menu()
{
    char choice;
    //char term;
    //char str[100];
    
    //printf("\033[0;32m"); //GREEN
    // *** GREEN COLORED BORDER ***
    printf("\n\n\033[0;32m  ____________________________________________________ ");
    printf("\n \033[0;32m|\033[0m                                                    \033[0;32m|\033[0m");
    printf("\n \033[0;32m|\033[0m                                                    \033[0;32m|\033[0m");
    printf("\n \033[0;32m|\033[0m                                                    \033[0;32m|\033[0m");
    printf("\n \033[0;32m|\033[0m         *********\033[0;32m MONTY HALL GAME \033[0m********         \033[0;32m|\033[0m");
    printf("\n \033[0;32m|\033[0m                                                    \033[0;32m|\033[0m");
    printf("\n \033[0;32m|\033[0m                                                    \033[0;32m|\033[0m");
    printf("\n \033[0;32m|\033[0m                                                    \033[0;32m|\033[0m");
    printf("\n \033[0;32m|\033[0m         1.    Start the Game                       \033[0;32m|\033[0m");
    printf("\n \033[0;32m|\033[0m                                                    \033[0;32m|\033[0m");
    printf("\n \033[0;32m|\033[0m         2.    How to Play                          \033[0;32m|\033[0m");
    printf("\n \033[0;32m|\033[0m                                                    \033[0;32m|\033[0m");
    printf("\n \033[0;32m|\033[0m         3.    Game Explanation                     \033[0;32m|\033[0m");
    printf("\n \033[0;32m|\033[0m                                                    \033[0;32m|\033[0m");
    printf("\n \033[0;32m|\033[0m         4.    Summary of pervious contestants      \033[0;32m|\033[0m");
    printf("\n \033[0;32m|\033[0m                                                    \033[0;32m|\033[0m");
    printf("\n \033[0;32m|\033[0m         5.    Back to Main Menu                    \033[0;32m|\033[0m");
    printf("\n \033[0;32m|\033[0m                                                    \033[0;32m|\033[0m");
    printf("\n \033[0;32m|\033[0m                                                    \033[0;32m|\033[0m");
    printf("\n \033[0;32m|____________________________________________________|\033[0m");
    //printf("\n ------------------------------------------------------ ");

    menuLabel:
    printf("\n\n Enter your choice : ");
    scanf(" %c",&choice);

    // if a character is entered or a number is entered that's not in given choices
    if(choice!='1' && choice!='2' && choice!='3' && choice!='4' && choice!='5')
    {
        printf("\n\n Please enter appropriate values. Press any key to continue ");
        goto menuLabel;
    }

    return choice;
}

void howToPlay()
{
    system("clear");

    int time = 10;

    //printf("\033[0;32m"); //GREEN
    // *** GREEN COLORED BORDER ***

    printf("\n  \033[0;32m_____________________________________________________________________________________________________________ \033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                    *********\033[0;32m MONTY HALL GAME \033[0m********                                       \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m        There are 3 doors on the screen                                                                      \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m        Behind 2 of the doors there is a Goat but behind 1 of the doors there is a Sports Car                \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m        Monty will ask you to pick any one of the doors                                                      \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m        Then before opening the door you chose, he will show you a door which has a Goat behind it           \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m        Now there is one door that definitely has a Goat behind it and now 2 unkown doors are left           \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m        You get a choice to either switch to the other door or stick to the original door                    \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m        In the end, Monty will open all the remaining doors and you either win a Sports Car or a Goat        \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m        \033[0;32m** RULES ** \033[0m                                                                                         \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m        1) You can pick only 1 door at a time                                                                \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m        2) You will get only one chance to switch the door agter your first pick                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|_____________________________________________________________________________________________________________|\033[0m");delay(time);
    //printf("\n ---------------------------------------------------------------------------------------------------------------");delay(time);

    printf("\n\n  Press any key to go back  \n\n");
    getch();
}

void readRecord()
{
    //THIS FUNCTION WILL READ THE FILE OF WINNING RECORDS

    FILE *fp;

    float data;
    
    int count = 1;

    fp = fopen("scoreRecord.txt","r");
    if(fp == NULL)
    {
        printf("\n File does NOT EXIST\n\n");
    }
    else
    {
        //printf("\n\n File is opened");
    
        
        while(!feof(fp))
        {
            fscanf(fp,"%f",&data);

            //printf("%0.2f",data);delay(20);
            
            switch(count)
            {
                case 1: noOfSwitchPlayers = (int)data;
                        count++;
                        break;
                
                case 2: switchWinCount = (int)data;
                        count++;
                        break;

                case 3: percentSwitchWinCount = data;
                        count++;
                        break;

                case 4: noOfNotSwitchPlayers = (int)data;
                        count++;
                        break;

                case 5: notSwitchWinCount = (int)data;
                        count++;
                        break;

                case 6: percentNotSwitchWinCount = data;
                        count++;
                        break;
            }
        }
    }
}

void storeRecord(char sw, int win)
{
    //THIS FUNCTION WILL STORE THE WINNING and PLAYER RECORDS IN A FILE

    readRecord();

    FILE *fp;

    fp = fopen("scoreRecord.txt","w");

    if(fp == NULL)
    {
        printf("\n File does NOT EXIST\n\n");
    }
    else
    {
        //printf("\n\n File is opened");

        //Player won with switching
        if(sw=='s' && win==1)
        {
            fprintf(fp,"%d ",++noOfSwitchPlayers);
            fprintf(fp,"%d ",++switchWinCount);

            //Change percentage of winners
            percentSwitchWinCount = (float)(switchWinCount * 100) / noOfSwitchPlayers;
            fprintf(fp,"%0.2f ",percentSwitchWinCount);
            
            fprintf(fp,"\n");

            fprintf(fp,"%d ",noOfNotSwitchPlayers);
            fprintf(fp,"%d ",notSwitchWinCount);
            
            percentNotSwitchWinCount = (float)(notSwitchWinCount * 100) / noOfNotSwitchPlayers;
            fprintf(fp,"%0.2f ",percentNotSwitchWinCount);
        }

        //Players lost with switching
        else if(sw=='s' && win==0)
        {
            fprintf(fp,"%d ",++noOfSwitchPlayers);
            fprintf(fp,"%d ",switchWinCount);

            //Change percentage of winners
            percentSwitchWinCount = (float)(switchWinCount * 100) / noOfSwitchPlayers;
            fprintf(fp,"%0.2f\n",percentSwitchWinCount);
                

            fprintf(fp,"\n");
            fprintf(fp,"%d ",noOfNotSwitchPlayers);
            fprintf(fp,"%d ",notSwitchWinCount);
            
            //Change percentage of winners
            percentNotSwitchWinCount = (float)(notSwitchWinCount * 100) / noOfNotSwitchPlayers;
            fprintf(fp,"%0.2f ",percentNotSwitchWinCount);
        }

        //Players won without switching
        else if(sw=='d' && win==1)
        {
            fprintf(fp,"%d ",noOfSwitchPlayers);
            fprintf(fp,"%d ",switchWinCount);
            
            //Change percentage of winners
            percentSwitchWinCount = (float)(switchWinCount * 100) / noOfSwitchPlayers;
            fprintf(fp,"%0.2f ",percentSwitchWinCount);
            
            fprintf(fp,"\n");
            
            fprintf(fp,"%d ",++noOfNotSwitchPlayers);
            fprintf(fp,"%d ",++notSwitchWinCount);

            //Change percentage of winners
            percentNotSwitchWinCount = (float)(notSwitchWinCount * 100) / noOfNotSwitchPlayers;           
            fprintf(fp,"%0.2f ",percentNotSwitchWinCount);
        }

        //Players lost without switching
        else if(sw=='d' && win==0)
        {
            fprintf(fp,"%d ",noOfSwitchPlayers);
            fprintf(fp,"%d ",switchWinCount);

            //Change percentage of winners
            percentSwitchWinCount = (float)(switchWinCount * 100) / noOfSwitchPlayers;
            fprintf(fp,"%0.2f ",percentSwitchWinCount);
            
            fprintf(fp,"\n");

            fprintf(fp,"%d ",++noOfNotSwitchPlayers);
            fprintf(fp,"%d ",notSwitchWinCount);
            
            //Change percentage of winners
            percentNotSwitchWinCount = (float)(notSwitchWinCount * 100) / noOfNotSwitchPlayers;
            fprintf(fp,"%0.2f ",percentNotSwitchWinCount);
        }
    }
    fclose(fp);

    //printf("\n\n  Results were recorded. \n");
}

void summaryTable()
{
    //THIS FUNCTION WILL PRINT WINNING RECORDS FROM THE FILE
    int time=10;

    
    system("clear");

    readRecord();

    //printf("\033[0;32m"); //GREEN
    // *** GREEN COLORED BORDER ***

    printf("\n\n  \033[0;32m______________________________________________________________________________________________________________________ ");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                                      \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                                      \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                                      \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                            *********\033[0;32m MONTY HALL GAME \033[0m********                                        \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                                      \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                                      \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                                      \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m             Here is a summary of how previous contestants have fared                                                 \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                                      \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m             ___________________ ____________________________ _________________ _________________________             \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m            |                   |                            |                 |                         |            \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m            |                   |     Number of Players      |     Winners     |     Percent Winners     |            \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m            |___________________|____________________________|_________________|_________________________|            \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m            |                   |                            |                 |                         |            \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m            |    Switched       |             %d                      %d                   %0.2f                       ",noOfSwitchPlayers,switchWinCount,percentSwitchWinCount);delay(time);
    printf("\n \033[0;32m|\033[0m            |___________________|____________________________|_________________|_________________________|            \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m            |                   |                            |                 |                         |            \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m            |    Didn't Switch  |             %d                      %d                   %0.2f                       ",noOfNotSwitchPlayers,notSwitchWinCount,percentNotSwitchWinCount);delay(time);
    printf("\n \033[0;32m|\033[0m            |___________________|____________________________|_________________|_________________________|            \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                                      \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                                      \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|\033[0m                                                                                                                      \033[0;32m|\033[0m");delay(time);
    printf("\n \033[0;32m|______________________________________________________________________________________________________________________|\033[0m");delay(time);
    //printf("\n ------------------------------------------------------------------------------------------------------------------------");delay(time);

    printf("\n\n Press any key to go back \n\n");
    getch();
}

void montyHallExplanation()
{
    system("clear");

    int time = 10;
    

    printf("\n\n  _________________________________________________________________________________________________________________________________________________ ");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                         *********\033[0;32m MONTY HALL GAME \033[0m********                                                      |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        I can only assume Monty Hall's game show Let's Make A Deal took place sometime during the sixties and/or seventies.                      |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        Information on this particular game show has somehow eluded the internet and my less than vivid memory sometimes fails me,               |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        but the basic setup for the game is as follows. Pretty much the entire audience dresses up like a complete loon                          |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        (Raggedy Ann and Andy were fairly popular costumes) hoping that Monty Hall would select them out of the crowd and offer them a           |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        chance to win a fabulous prize. For instance, he might offer you $100 for every paper clip that you have in your posession or            |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        he might give you $500, but then ask you if you would like to keep the money or trade it for what's in a particular box.                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        Of course there could be $1000 in the box or a single can of dog food.                                                                   |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        Anyway, I'm digressing and hopefully you get the basic gist of the game.                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        The particular game that we are concerned with here is where Monty Hall offers you the opportunity to win what is                        |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        behind one of three doors. Typically there was a really nice prize (i.e., a car) behind one of the doors and a not-so-nice prize         |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        (i.e., a goat) behind the other two. After selecting a door, Monty would then proceed to open one of the doors you didn't select.        |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        It is important to note here that Monty would NOT open the door that concealed the car.                                                  |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        At this point, he would then ask you if you wanted to switch to the other door before revealing what you had won.                        |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                               Source - \033[0;34mhttps://www.math.ucsd.edu/~crypto/Monty/montybg.html \033[0m    |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        The Monty Hall problem is a brain teaser, in the form of a probability puzzle, loosely based on the American television game             |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        show Let's Make a Deal and named after its original host, Monty Hall. The problem was originally posed (and solved) in a letter          |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        by Steve Selvin to the American Statistician in 1975.[1][2] It became famous as a question from reader Craig F. Whitaker's letter        |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        quoted in Marilyn vos Savant's 'Ask Marilyn' column in Parade magazine in 1990 :                                                         |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                Suppose you're on a game show, and you're given the choice of three doors: Behind one door is a car; behind the                  |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                others, goats. You pick a door, say No. 1, and the host, who knows what's behind the doors, opens another door,                  |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                say No. 3, which has a goat. He then says to you, 'Do you want to pick door No. 2?' Is it to your advantage to                   |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                switch your choice ?                                                                                                             |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        Vos Savant's response was that the contestant should switch to the other door. Under the standard assumptions, contestants who           |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        switch have a 2/3 chance of winning the car, while contestants who stick to their initial choice have only a 1/3 chance.                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        \033[0;32m ** STANDARD ASSUMPTIONS ** \033[0m                                                                                                              |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        Under the standard assumptions, the probability of winning the car after switching is 2/3. The key to this solution is the behavior      |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        of the host. Ambiguities in the Parade version do not explicitly define the protocol of the host.                                        |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        The role of the host as follows:                                                                                                         |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        1.  The host must always open a door that was not picked by the contestant.                                                              |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        2.  The host must always open a door to reveal a goat and never the car.                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        3.  The host must always offer the chance to switch between the originally chosen door and the remaining closed door.                    |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        It is also typically presumed that the car is initially hidden randomly behind the doors and that, if the player initially picks         |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        the car, then the host's choice of which goat-hiding door to open is random. Some authors, independently or inclusively, assume that     |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        the player's initial choice is random as well.                                                                                           |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        Well, looking at the numbers from out online experiment, it would appear that those who switched doors won about 2/3 of the time         |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        and those who didn't switch won about 1/3 of the time. Why is there such a large difference? I mean, once Monty shows you what's         |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        behind one of the doors, there are only two doors left. Right? Right. And the car is behind one of those two doors with equal            |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        probability. Right? WRONG!                                                                                                               |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        \033[0;32m** SIMPLE SOLUTIONS ** \033[0m                                                                                                                  |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        The solution presented by vos Savant in Parade shows the three possible arrangements of one car and two goats behind three doors and     |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        the result of staying or switching after initially picking door 1 in each case:                                                          |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |             ___________________ ___________________ ___________________ ___________________________ _________________________                   |");delay(time);
    printf("\n |            |                   |                   |                   |                           |                         |                  |");delay(time);
    printf("\n |            |   Behind door 1   |   Behind door 1   |   Behind door 3   |      Result if staying    |   Result if switching   |                  |");delay(time);
    printf("\n |            |                   |                   |                   |        at Door no. 1      |   to the door offered   |                  |");delay(time);
    printf("\n |            |___________________|___________________|___________________|___________________________|_________________________|                  |");delay(time);
    printf("\n |            |                   |                   |                   |                           |                         |                  |");delay(time);
    printf("\n |            |        Goat       |        Goat       |      * Car *      |          Wins Goat        |       * Wins Car *      |                  |");delay(time);
    printf("\n |            |___________________|___________________|___________________|___________________________|_________________________|                  |");delay(time);
    printf("\n |            |                   |                   |                   |                           |                         |                  |");delay(time);
    printf("\n |            |        Goat       |       * Car *     |        Goat       |          Wins Goat        |       * Wins Car *      |                  |");delay(time);
    printf("\n |            |___________________|___________________|___________________|___________________________|_________________________|                  |");delay(time);
    printf("\n |            |                   |                   |                   |                           |                         |                  |");delay(time);
    printf("\n |            |      * Car *      |        Goat       |        Goat       |        * Wins Car *       |        Wins Goat        |                  |");delay(time);
    printf("\n |            |___________________|___________________|___________________|___________________________|_________________________|                  |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |         A player who stays with the initial choice wins in only one out of three of these equally likely possibilities, while a player who      |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |         switches wins in two out of three.                                                                                                      |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |         \033[0;32mProbabilities of winning and losing in both scenarios \033[0m                                                                                  |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                  ___________________________                              ___________________________                                           |");delay(time);
    printf("\n |                 |                           |                            |                           |                                          |");delay(time);
    printf("\n |                 |       Don't Switch        |                            |        Always Switch      |                                          |");delay(time); 
    printf("\n |                 |___________________________|                            |___________________________|                                          |");delay(time);
    printf("\n |                 |                           |                            |                           |                                          |");delay(time); 
    printf("\n |                 |  Probability(Win)  = 1/3  |                            |  Probability(win)  = 2/3  |                                          |");delay(time);
    printf("\n |                 |                           |                            |                           |                                          |");delay(time);
    printf("\n |                 |  Probability(Lose) = 2/3  |                            |  Probability(Lose) = 1/3  |                                          |");delay(time);
    printf("\n |                 |___________________________|                            |___________________________|                                          |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |         \033[0;36mIt is more likely that you have selected the wrong choice in 1st go as probability of losing in initial pick is more than of winning\033[0m    |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |         \033[0;36mHence if after Monty shows you a door with goat behind it, it is more likely that the car is behind the other door \033[0m                     |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |             ______________________________________________                 ______________________________________________                       |");delay(time);
    printf("\n |            |                                              |               |                                              |                      |");delay(time);
    printf("\n |            |                        P(W) = 2/3            |               |                        P(W) = 2/3            |                      |");delay(time);
    printf("\n |            |  P(W) =  1/3                                 |               |  P(W) =  1/3                                 |                      |");delay(time);
    printf("\n |            |                             |                |               |                             |                |                      |");delay(time);
    printf("\n |            |       |                     |                | ------------> |       |                     |                |                      |");delay(time);
    printf("\n |            |       |        _____________|____________    |  Monty Opens  |       |        _____________|____________    |                      |");delay(time);
    printf("\n |            |    ___|___    |    _______    _______    |   |  a door that  |    ___|___    |    _______    _______    |   |                      |");delay(time);
    printf("\n |            |   |       |   |   |       |  |       |   |   |  has a goat   |   |       |   |   |       |  |       |   |   |                      |");delay(time);
    printf("\n |            |   |       |   |   |       |  |       |   |   |  behind it    |   |       |   |   |       |  |   *   |   |   |                      |");delay(time);
    printf("\n |            |   |  D-1  |   |   |  D-2  |  |  D-3  |   |   | ------------> |   |  D-1  |   |   |  D-2  |  |  Goat |   |   |                      |");delay(time);
    printf("\n |            |   |       |   |   |       |  |       |   |   |               |   |       |   |   |       |  |   *   |   |   |                      |");delay(time);
    printf("\n |            |   |_______|   |   |_______|  |_______|   |   |               |   |_______|   |   |_______|  |_______|   |   |                      |");delay(time);
    printf("\n |            |               |__________________________|   |               |               |_______|__________|_______|   |                      |");delay(time);
    printf("\n |            |                                              |               |                       |          |           |                      |");delay(time);
    printf("\n |            |______________________________________________|               |                       |          |           |                      |");delay(time);
    printf("\n |                                                                           |                   P(W) = 2/3    P(W) = 0     |                      |");delay(time);
    printf("\n |              Car has a 1/3 chance of being behind the                     |                                              |                      |");delay(time);
    printf("\n |              player's initial pick and a 2/3 chance of                    |______________________________________________|                      |");delay(time);
    printf("\n |              being behind one of the other two doors                                                                                            |");delay(time);
    printf("\n |                                                                             The host opens a door, the odds of the two sets                     |");delay(time);
    printf("\n |                                                                             don't change but the odds move to 0 for the                         |");delay(time);
    printf("\n |                                                                             open door and 2/3 for the close door                                |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |           This solution is quite counter-intuitive                                                                                              |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |           You're more likely to win after switching the door each time than not switching. When a door which has goat behind it is revealed     |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |           the other door capture that 2/3 probability all by itself while probability of winning with initial pick still remains 1/3.           |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                            ---------x--x--------                                                                |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        References :                                                                                                                             |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |        1.  Solution explanation          -  \033[0;34mhttps://www.youtube.com/watch?v=Xp6V_lO1ZKA \033[0m                                                        |");delay(time);
    printf("\n |        2.  Monty Hall Problem wikipedia  -  \033[0;34mhttps://en.wikipedia.org/wiki/Monty_Hall_problem \033[0m                                                   |");delay(time);
    printf("\n |        3.  Monty Hall wikipedia          -  \033[0;34mhttps://en.wikipedia.org/wiki/Monty_Hall \033[0m                                                           |");delay(time);
    printf("\n |        4.  Marilyn Vos Savant wikipedia  -  \033[0;34mhttps://en.wikipedia.org/wiki/Marilyn_vos_Savant \033[0m                                                   |");delay(time);
    printf("\n |        5.  Monty Hall Browser Game       -  \033[0;34mhttps://www.math.ucsd.edu/~crypto/Monty/montybg.html \033[0m                                               |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |                                                                                                                                                 |");delay(time);
    printf("\n |_________________________________________________________________________________________________________________________________________________|");delay(time);

    printf("\n\n Press any key to go back \n\n");
    getch();

}

void drawDoors(int open)
{
    printf("\n");
    system("clear");

    int time = 10;
    int doorNo = i+1;

    if(open == 0)
    {
        printf("\n __________________________________________________________________________________________________");delay(time);
        printf("\n|                                                                                                  |");delay(time);
        printf("\n|                                                                                                  |");delay(time);
        printf("\n|\t       Door - 1     \t\t       Door - 2     \t\t      Door - 3      \t   |");delay(time);
        printf("\n|                                                                                                  |");delay(time);
        printf("\n|\t********************\t\t********************\t\t********************\t   |");delay(time);
        printf("\n|\t1  --------------- 1\t\t2  --------------- 2\t\t3  --------------- 3\t   |");delay(time);
    //printf("\n\t1  |1234567890123| 1\t\t2  |1234567890123| 2\t\t3  |1234567890123| 3");
        printf("\n|\t1  |xxxxxxxxxxxxx| 1\t\t2  |xxxxxxxxxxxxx| 2\t\t3  |xxxxxxxxxxxxx| 3\t   |");delay(time);
        printf("\n|\t1  |xxxxx   xxxxx| 1\t\t2  |xxx       xxx| 2\t\t3  |xxx        xx| 3\t   |");delay(time);
        printf("\n|\t1{x}xxxx    xxxxx| 1\t\t2{x}xxxxxxxx  xxx| 2\t\t3{x}xxxxxxxxx  xx| 3\t   |");delay(time);
        printf("\n|\t1  |xxx  x  xxxxx| 1\t\t2  |xxxxxxxx  xxx| 2\t\t3  |xxxxxxxxx  xx| 3\t   |");delay(time);
        printf("\n|\t1  |xx  xx  xxxxx| 1\t\t2  |xxx       xxx| 2\t\t3  |xxx        xx| 3\t   |");delay(time);
        printf("\n|\t1  |xxxxxx  xxxxx| 1\t\t2  |xxx  xxxxxxxx| 2\t\t3  |xxxxxxxxx  xx| 3\t   |");delay(time);
        printf("\n|\t1  |xxxxxx  xxxxx| 1\t\t2  |xxx  xxxxxxxx| 2\t\t3  |xxxxxxxxx  xx| 3\t   |");delay(time);
        printf("\n|\t1{x}xxxxxx  xxxxx| 1\t\t2{x}xxx       xxx| 2\t\t3{x}xxx        xx| 3\t   |");delay(time);
        printf("\n|\t1  |xxx       xxx| 1\t\t2  |xxxxxxxxxxxxx| 2\t\t3  |xxxxxxxxxxxxx| 3\t   |");delay(time);
        printf("\n|\t1  |xxxxxxxxxxxxx| 1\t\t2  |xxxxxxxxxxxxx| 2\t\t3  |xxxxxxxxxxxxx| 3\t   |");delay(time);
        printf("\n|\t1  --------------- 1\t\t2  --------------- 2\t\t3  --------------- 3\t   |");delay(time);
        printf("\n|\t********************\t\t********************\t\t********************\t   |");delay(time);
        printf("\n|                                                                                                  |");delay(time);
        printf("\n|                                                                                                  |");delay(time);
        printf("\n|__________________________________________________________________________________________________|");delay(time);
        //printf("\n----------------------------------------------------------------------------------------------------");delay(time);
        //printf("\n\t        Door 1      \t\t        Door 2      \t\t        Door 3\n");
    }

    else if(open == 1)
    {
        //When monty opens 1st door
        if(doorNo == 1)
        {
            printf("\n __________________________________________________________________________________________________");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|\t       Door - 1     \t\t       Door - 2     \t\t      Door - 3      \t   |");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|\t********************\t\t********************\t\t********************\t   |");delay(time);
            printf("\n|\t1  --------------- 1\t\t2  --------------- 2\t\t3  --------------- 3\t   |");delay(time);
          //printf("\n\t1  |1234567890123| 1\t\t2  |1234567890123| 2\t\t3  |1234567890123| 3");
            printf("\n|\t1  |             | 1\t\t2  |xxxxxxxxxxxxx| 2\t\t3  |xxxxxxxxxxxxx| 3\t   |");delay(time);
            printf("\n|\t1  |             | 1\t\t2  |xxx       xxx| 2\t\t3  |xxx        xx| 3\t   |");delay(time);
            printf("\n|\t1{x}             | 1\t\t2{x}xxxxxxxx  xxx| 2\t\t3{x}xxxxxxxxx  xx| 3\t   |");delay(time);
            printf("\n|\t1  |             | 1\t\t2  |xxxxxxxx  xxx| 2\t\t3  |xxxxxxxxx  xx| 3\t   |");delay(time);
            printf("\n|\t1  |     GOAT    | 1\t\t2  |xxx       xxx| 2\t\t3  |xxx        xx| 3\t   |");delay(time);
            printf("\n|\t1  |             | 1\t\t2  |xxx  xxxxxxxx| 2\t\t3  |xxxxxxxxx  xx| 3\t   |");delay(time);
            printf("\n|\t1  |             | 1\t\t2  |xxx  xxxxxxxx| 2\t\t3  |xxxxxxxxx  xx| 3\t   |");delay(time);
            printf("\n|\t1{x}             | 1\t\t2{x}xxx       xxx| 2\t\t3{x}xxx        xx| 3\t   |");delay(time);
            printf("\n|\t1  |             | 1\t\t2  |xxxxxxxxxxxxx| 2\t\t3  |xxxxxxxxxxxxx| 3\t   |");delay(time);
            printf("\n|\t1  |             | 1\t\t2  |xxxxxxxxxxxxx| 2\t\t3  |xxxxxxxxxxxxx| 3\t   |");delay(time);
            printf("\n|\t1  --------------- 1\t\t2  --------------- 2\t\t3  --------------- 3\t   |");delay(time);
            printf("\n|\t********************\t\t********************\t\t********************\t   |");delay(time);
            printf("\n|\t        GOAT        \t\t                    \t\t                    \t   |");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|__________________________________________________________________________________________________|");delay(time);
            //printf("\n----------------------------------------------------------------------------------------------------");delay(time);
        }
    
        //When monty opens 2nd door
        else if(doorNo == 2)
        {
            
            printf("\n __________________________________________________________________________________________________");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|\t       Door - 1     \t\t       Door - 2     \t\t      Door - 3      \t   |");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|\t********************\t\t********************\t\t********************\t   |");delay(time);
            printf("\n|\t1  --------------- 1\t\t2  --------------- 2\t\t3  --------------- 3\t   |");delay(time);
          //printf("\n\t1  |1234567890123| 1\t\t2  |1234567890123| 2\t\t3  |1234567890123| 3");
            printf("\n|\t1  |xxxxxxxxxxxxx| 1\t\t2  |             | 2\t\t3  |xxxxxxxxxxxxx| 3\t   |");delay(time);
            printf("\n|\t1  |xxxxx   xxxxx| 1\t\t2  |             | 2\t\t3  |xxx        xx| 3\t   |");delay(time);
            printf("\n|\t1{x}xxxx    xxxxx| 1\t\t2{x}             | 2\t\t3{x}xxxxxxxxx  xx| 3\t   |");delay(time);
            printf("\n|\t1  |xxx  x  xxxxx| 1\t\t2  |             | 2\t\t3  |xxxxxxxxx  xx| 3\t   |");delay(time);
            printf("\n|\t1  |xx  xx  xxxxx| 1\t\t2  |     GOAT    | 2\t\t3  |xxx        xx| 3\t   |");delay(time);
            printf("\n|\t1  |xxxxxx  xxxxx| 1\t\t2  |             | 2\t\t3  |xxxxxxxxx  xx| 3\t   |");delay(time);
            printf("\n|\t1  |xxxxxx  xxxxx| 1\t\t2  |             | 2\t\t3  |xxxxxxxxx  xx| 3\t   |");delay(time);
            printf("\n|\t1{x}xxxxxx  xxxxx| 1\t\t2{x}             | 2\t\t3{x}xxx        xx| 3\t   |");delay(time);
            printf("\n|\t1  |xxx       xxx| 1\t\t2  |             | 2\t\t3  |xxxxxxxxxxxxx| 3\t   |");delay(time);
            printf("\n|\t1  |xxxxxxxxxxxxx| 1\t\t2  |             | 2\t\t3  |xxxxxxxxxxxxx| 3\t   |");delay(time);
            printf("\n|\t1  --------------- 1\t\t2  --------------- 2\t\t3  --------------- 3\t   |");delay(time);
            printf("\n|\t********************\t\t********************\t\t********************\t   |");delay(time);
            printf("\n|\t                    \t\t         GOAT        \t\t                   \t   |");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|__________________________________________________________________________________________________|");delay(time);
            //printf("\n----------------------------------------------------------------------------------------------------");delay(time);
        }

        //When monty opens 3rd door
        else 
        {
            printf("\n __________________________________________________________________________________________________");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|\t       Door - 1     \t\t       Door - 2     \t\t      Door - 3     \t   |");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|\t********************\t\t********************\t\t********************\t   |");delay(time);
            printf("\n|\t1  --------------- 1\t\t2  --------------- 2\t\t3  --------------- 3\t   |");delay(time);
          //printf("\n\t1  |1234567890123| 1\t\t2  |1234567890123| 2\t\t3  |1234567890123| 3");
            printf("\n|\t1  |xxxxxxxxxxxxx| 1\t\t2  |xxxxxxxxxxxxx| 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1  |xxxxx   xxxxx| 1\t\t2  |xxx       xxx| 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1{x}xxxx    xxxxx| 1\t\t2{x}xxxxxxxx  xxx| 2\t\t3{x}             | 3\t   |");delay(time);
            printf("\n|\t1  |xxx  x  xxxxx| 1\t\t2  |xxxxxxxx  xxx| 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1  |xx  xx  xxxxx| 1\t\t2  |xxx       xxx| 2\t\t3  |     GOAT    | 3\t   |");delay(time);
            printf("\n|\t1  |xxxxxx  xxxxx| 1\t\t2  |xxx  xxxxxxxx| 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1  |xxxxxx  xxxxx| 1\t\t2  |xxx  xxxxxxxx| 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1{x}xxxxxx  xxxxx| 1\t\t2{x}xxx       xxx| 2\t\t3{x}             | 3\t   |");delay(time);
            printf("\n|\t1  |xxx       xxx| 1\t\t2  |xxxxxxxxxxxxx| 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1  |xxxxxxxxxxxxx| 1\t\t2  |xxxxxxxxxxxxx| 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1  --------------- 1\t\t2  --------------- 2\t\t3  --------------- 3\t   |");delay(time);
            printf("\n|\t********************\t\t********************\t\t********************\t   |");delay(time);
            printf("\n|\t                    \t\t                    \t\t         GOAT       \t   |");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|__________________________________________________________________________________________________|");delay(time);
            //printf("\n----------------------------------------------------------------------------------------------------");delay(time);
        }

        //**********************************************************************************************
    }

    else if(open == 2)
    {
        //*********** FOR LAST DOOR OPENED is 2 *********************************************
        if(carDoor == 2)
        {
            printf("\n __________________________________________________________________________________________________");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|\t       Door - 1     \t\t       Door - 2     \t\t      Door - 3     \t   |");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|\t********************\t\t********************\t\t********************\t   |");delay(time);
            printf("\n|\t1  --------------- 1\t\t2  --------------- 2\t\t3  --------------- 3\t   |");delay(time);
          //printf("\n\t1  |1234567890123| 1\t\t2  |1234567890123| 2\t\t3  |1234567890123| 3");
            printf("\n|\t1  |             | 1\t\t2  |             | 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1  |             | 1\t\t2  |             | 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1{x}             | 1\t\t2{x}             | 2\t\t3{x}             | 3\t   |");delay(time);
            printf("\n|\t1  |             | 1\t\t2  |  ---------  | 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1  |     GOAT    | 1\t\t2  |  |  CAR  |  | 2\t\t3  |     GOAT    | 3\t   |");delay(time);
            printf("\n|\t1  |             | 1\t\t2  |  ---------  | 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1  |             | 1\t\t2  |             | 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1{x}             | 1\t\t2{x}             | 2\t\t3{x}             | 3\t   |");delay(time);
            printf("\n|\t1  |             | 1\t\t2  |             | 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1  |             | 1\t\t2  |             | 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1  --------------- 1\t\t2  --------------- 2\t\t3  --------------- 3\t   |");delay(time);
            printf("\n|\t********************\t\t********************\t\t********************\t   |");delay(time);
            printf("\n|\t        GOAT        \t\t         CAR        \t\t        GOAT        \t   |");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|__________________________________________________________________________________________________|");delay(time);
            //printf("\n----------------------------------------------------------------------------------------------------");delay(time);
        }

        //**************** FOR LAST DOOR OPENED is 3 ******************************************
        else if(carDoor == 3)
        {
            printf("\n __________________________________________________________________________________________________");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|\t       Door - 1     \t\t       Door - 2     \t\t      Door - 3     \t   |");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|\t********************\t\t********************\t\t********************\t   |");delay(time);
            printf("\n|\t1  --------------- 1\t\t2  --------------- 2\t\t3  --------------- 3\t   |");delay(time);
          //printf("\n\t1  |1234567890123| 1\t\t2  |1234567890123| 2\t\t3  |1234567890123| 3");
            printf("\n|\t1  |             | 1\t\t2  |             | 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1  |             | 1\t\t2  |             | 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1{x}             | 1\t\t2{x}             | 2\t\t3{x}             | 3\t   |");delay(time);
            printf("\n|\t1  |             | 1\t\t2  |             | 2\t\t3  |  ---------  | 3\t   |");delay(time);
            printf("\n|\t1  |     GOAT    | 1\t\t2  |     GOAT    | 2\t\t3  |  |  CAR  |  | 3\t   |");delay(time);
            printf("\n|\t1  |             | 1\t\t2  |             | 2\t\t3  |  ---------  | 3\t   |");delay(time);
            printf("\n|\t1  |             | 1\t\t2  |             | 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1{x}             | 1\t\t2{x}             | 2\t\t3{x}             | 3\t   |");delay(time);
            printf("\n|\t1  |             | 1\t\t2  |             | 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1  |             | 1\t\t2  |             | 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1  --------------- 1\t\t2  --------------- 2\t\t3  --------------- 3\t   |");delay(time);
            printf("\n|\t********************\t\t********************\t\t********************\t");delay(time);
            printf("\n|\t        GOAT        \t\t        GOAT        \t\t         CAR        \t   |");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|__________________________________________________________________________________________________|");delay(time);
            //printf("\n----------------------------------------------------------------------------------------------------");delay(time);
        }

        //*********** FOR LAST DOOR OPENED is 1 *********************************************
        else 
        {
            printf("\n __________________________________________________________________________________________________");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|\t       Door - 1     \t\t       Door - 2     \t\t      Door - 3     \t   |");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|\t********************\t\t********************\t\t********************\t   |");delay(time);
            printf("\n|\t1  --------------- 1\t\t2  --------------- 2\t\t3  --------------- 3\t   |");delay(time);
          //printf("\n\t1  |1234567890123| 1\t\t2  |1234567890123| 2\t\t3  |1234567890123| 3");
            printf("\n|\t1  |             | 1\t\t2  |             | 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1  |             | 1\t\t2  |             | 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1{x}             | 1\t\t2{x}             | 2\t\t3{x}             | 3\t   |");delay(time);
            printf("\n|\t1  |  ---------  | 1\t\t2  |             | 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1  |  |  CAR  |  | 1\t\t2  |     GOAT    | 2\t\t3  |     GOAT    | 3\t   |");delay(time);
            printf("\n|\t1  |  ---------  | 1\t\t2  |             | 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1  |             | 1\t\t2  |             | 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1{x}             | 1\t\t2{x}             | 2\t\t3{x}             | 3\t   |");delay(time);
            printf("\n|\t1  |             | 1\t\t2  |             | 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1  |             | 1\t\t2  |             | 2\t\t3  |             | 3\t   |");delay(time);
            printf("\n|\t1  --------------- 1\t\t2  --------------- 2\t\t3  ------  ------- 3\t   |");delay(time);
            printf("\n|\t********************\t\t********************\t\t********************\t   |");delay(time);
            printf("\n|\t         CAR        \t\t        GOAT        \t\t        GOAT        \t   |");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|                                                                                                  |");delay(time);
            printf("\n|__________________________________________________________________________________________________|");delay(time);
            //printf("\n----------------------------------------------------------------------------------------------------");delay(time);
        }
    }
    /*
        if(doorNo == 2 && final == 3)
        {
            printf("\n\t********************\t\t********************\t\t********************\t");
            printf("\n\t1  --------------- 1\t\t2  --------------- 2\t\t3  --------------- 3");
          //printf("\n\t1  |1234567890123| 1\t\t2  |1234567890123| 2\t\t3  |1234567890123| 3");
            printf("\n\t1  |xxxxxxxxxxxxx| 1\t\t2  |xx xxxxxxx xx| 2\t\t3  |xxxxxxxxxxxxx| 3");
            printf("\n\t1  |xxxxx   xxxxx| 1\t\t2  |xxx xxxxx xxx| 2\t\t3  |xxxxxxxxxxxxx| 3");
            printf("\n\t1{x}xxxx    xxxxx| 1\t\t2{x}xxxx xxx xxxx| 2\t\t3{x}xxxxxxxxxxxxx| 3");
            printf("\n\t1  |xxx  x  xxxxx| 1\t\t2  |xx        xxx| 2\t\t3  |xxx   *   xxx| 3");
            printf("\n\t1  |xx  xx  xxxxx| 1\t\t2  |xxxxx  xxxxxx| 2\t\t3  |xxx xxxxx xxx| 3");
            printf("\n\t1  |xxxxxx  xxxxx| 1\t\t2  |xx        xxx| 2\t\t3  |xx  x   x  xx| 3");
            printf("\n\t1  |xxxxxx  xxxxx| 1\t\t2  |xxxxx  xxxxxx| 2\t\t3  |xx  xxxxx  xx| 3");
            printf("\n\t1{x}xxxxxx  xxxxx| 1\t\t2{x}x           x| 2\t\t3{x}xxxxxxxxxxxxx| 3");
            printf("\n\t1  |xxx       xxx| 1\t\t2  |xxxxx  xxxxxx| 2\t\t3  |xxxxxxxxxxxxx| 3");
            printf("\n\t1  |xxxxxxxxxxxxx| 1\t\t2  |xxxxx  xxxxxx| 2\t\t3  |xxxxxxxxxxxxx| 3");
            printf("\n\t1  --------------- 1\t\t2  ------  ------- 2\t\t3  --------------- 3");
            printf("\n\t********************\t\t********************\t\t********************\t");
            printf("\n\t        Door 1      \t\t        GOAT        \t\t        Door 3\n");
        }

        //*********** FOR GOAT on 3 and CAR on 1,2 *********************************************
        if(doorNo == 3 && final == 1)
        {
            printf("\n\t********************\t\t********************\t\t********************\t");
            printf("\n\t1  --------------- 1\t\t2  --------------- 2\t\t3  --------------- 3");
          //printf("\n\t1  |1234567890123| 1\t\t2  |1234567890123| 2\t\t3  |1234567890123| 3");
            printf("\n\t1  |xxxxxxxxxxxxx| 1\t\t2  |xxxxxxxxxxxxx| 2\t\t3  |xx xxxxxxx xx| 3");
            printf("\n\t1  |xxxxxxxxxxxxx| 1\t\t2  |xxx       xxx| 2\t\t3  |xxx xxxxx xxx| 3");
            printf("\n\t1{x}xxxxxxxxxxxxx| 1\t\t2{x}xxxxxxxx  xxx| 2\t\t3{x}xxxx xxx xxxx| 3");
            printf("\n\t1  |xxx   *   xxx| 1\t\t2  |xxxxxxxx  xxx| 2\t\t3  |xx        xxx| 3");
            printf("\n\t1  |xxx xxxxx xxx| 1\t\t2  |xxx       xxx| 2\t\t3  |xxxxx  xxxxxx| 3");
            printf("\n\t1  |xx  x   x  xx| 1\t\t2  |xxx  xxxxxxxx| 2\t\t3  |xx        xxx| 3");
            printf("\n\t1  |xx  xxxxx  xx| 1\t\t2  |xxx  xxxxxxxx| 2\t\t3  |xxxxx  xxxxxx| 3");
            printf("\n\t1{x}xxxxxxxxxxxxx| 1\t\t2{x}xxx       xxx| 2\t\t3{x}x           x| 3");
            printf("\n\t1  |xxxxxxxxxxxxx| 1\t\t2  |xxxxxxxxxxxxx| 2\t\t3  |xxxxx  xxxxxx| 3");
            printf("\n\t1  |xxxxxxxxxxxxx| 1\t\t2  |xxxxxxxxxxxxx| 2\t\t3  |xxxxx  xxxxxx| 3");
            printf("\n\t1  --------------- 1\t\t2  --------------- 2\t\t3  ------  ------- 3");
            printf("\n\t********************\t\t********************\t\t********************\t");
            printf("\n\t        Door 1      \t\t        Door 2      \t\t         GOAT \n");
        }

        if(doorNo == 3 && final == 2)
        {
            printf("\n\t********************\t\t********************\t\t********************\t");
            printf("\n\t1  --------------- 1\t\t2  --------------- 2\t\t3  --------------- 3");
          //printf("\n\t1  |1234567890123| 1\t\t2  |1234567890123| 2\t\t3  |1234567890123| 3");
            printf("\n\t1  |xxxxxxxxxxxxx| 1\t\t2  |xxxxxxxxxxxxx| 2\t\t3  |xx xxxxxxx xx| 3");
            printf("\n\t1  |xxxxx   xxxxx| 1\t\t2  |xxxxxxxxxxxxx| 2\t\t3  |xxx xxxxx xxx| 3");
            printf("\n\t1{x}xxxx    xxxxx| 1\t\t2{x}xxxxxxxxxxxxx| 2\t\t3{x}xxxx xxx xxxx| 3");
            printf("\n\t1  |xxx  x  xxxxx| 1\t\t2  |xxx   *   xxx| 2\t\t3  |xx        xxx| 3");
            printf("\n\t1  |xx  xx  xxxxx| 1\t\t2  |xxx xxxxx xxx| 2\t\t3  |xxxxx  xxxxxx| 3");
            printf("\n\t1  |xxxxxx  xxxxx| 1\t\t2  |xx  x   x  xx| 2\t\t3  |xx        xxx| 3");
            printf("\n\t1  |xxxxxx  xxxxx| 1\t\t2  |xx  xxxxx  xx| 2\t\t3  |xxxxx  xxxxxx| 3");
            printf("\n\t1{x}xxxxxx  xxxxx| 1\t\t2{x}xxxxxxxxxxxxx| 2\t\t3{x}x           x| 3");
            printf("\n\t1  |xxx       xxx| 1\t\t2  |xxxxxxxxxxxxx| 2\t\t3  |xxxxx  xxxxxx| 3");
            printf("\n\t1  |xxxxxxxxxxxxx| 1\t\t2  |xxxxxxxxxxxxx| 2\t\t3  |xxxxx  xxxxxx| 3");
            printf("\n\t1  --------------- 1\t\t2  --------------- 2\t\t3  ------  ------- 3");
            printf("\n\t********************\t\t********************\t\t********************\t");
            printf("\n\t        Door 1      \t\t        Door 2      \t\t         GOAT \n");
        }

    }*/
}

