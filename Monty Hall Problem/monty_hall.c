#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<windows.h>
#include <unistd.h>

int switchDoor();
void drawDoors(int);
void delay(int);
void printDelay(char[],int);
void winLose(bool);

int carDoor;
int i,j;
int door[3] = {0,0,0};
char ch;
int choice;
int optionDoor;
char str[200];
int c;

//bool n = false;

int main()
{
    int upper=2,lower=0;

    i=0,j=0,door[0]=0,door[1]=0,door[2]=0;
    

    //Generate random variable from 0 to 2 to assign car(1) at index of door[]
    srand(time(0));
    i = (rand()% (upper-lower+1)) + lower;

    //Assign car to a door
    door[i] = 1;
    carDoor = i+1;
    
    printf("\n");
    for(i=0;i<3;i++)
    {
        printf("\t%d",door[i]);
    }

    //Draw the doors
    drawDoors(0);
   
    strcpy(str,"\n\n\n Which door do you want to open : ");
    repeat:
    
    //To print the string with delay on every character
    for (c = 0; str[c] != '\0'; c++) 
    {    
        printf("%c", str[c]);   
        fflush(stdout); 
        delay(30);    
    }   
    scanf("%d",&choice);

    if(choice<1 || choice>3)
    {
        //printf("\n\n Please enter appropriate values ");
        strcpy(str,"\n\n Please enter appropriate values ");
        printDelay(str,40);
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
            printDelay(str,40);

            strcpy(str,"\n\n****************************************************************");
            printDelay(str,10);      

            strcpy(str,"\n\nPress any key to continue .. \n\n");
            printDelay(str,40);   
            getch();

            //Draw the doors
            //Sleep(2000);
            drawDoors(1);

            //printf("\n\n****************************************************************");
            printf("\n");
            strcpy(str,"\n\n Car is definitely not behind Door ");
            printDelay(str,40);   
            printf("'%d",i+1);//Door number
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

    strcpy(str,"\n\n Before I open Door No.");
    printDelay(str,40);
    printf("%d ",choice);//Print door number

    strcpy(str,", the door that you have selected\n\n I'm going to let you switch to another door if you like");
    printDelay(str,40);

    strcpy(str,"\n\n****************************************************************");
    printDelay(str,10);     
    

    /*printf("\n\n****************************************************************");
    printf("\n\n Before I open Door No.'%d', the door that you have selected\n\n I'm going to let you switch to another door if you like",choice);
    printf("\n\n****************************************************************");
    */
    switchDoor();
    
    printf("\n\n");

    return 0;
}

int switchDoor()
{
    strcpy(str,"\n\n Your original choice was 'Door-");
    printDelay(str,40); 
    printf("%d'",choice);//Print door number
    strcpy(str,", Do you want to switch to 'Door-");
    printDelay(str,40); 
    printf("%d'",optionDoor);//Print door number
    strcpy(str," ? (Y/N) : ");
    printDelay(str,40); 
    
    scanf(" %c",&ch);

    if(ch=='y' || ch=='Y')
    {
        //printf("\n\n You decided to Switch to -> 'Door-%d",optionDoor);
        strcpy(str,"\n\n You decided to Switch to -> 'Door-");
        printDelay(str,40); 
        printf("%d",optionDoor);

        //printf("\n\n\n *** Press any key to Open the 'Door-%d'  ***",optionDoor);
        strcpy(str,"\n\n\n *** Press any key to Open the 'Door-");
        printDelay(str,40); 
        printf("%d'  ***",optionDoor);

        getch();

        //Traverse all doors
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
                }
                else
                {
                    //Game Lost
                    winLose(false);
                }
                break;
            }
        }
    }
    else if(ch=='n' || ch=='N')
    {
        //printf("\n\n You decided to stick to your original choice -> 'Door-%d",choice);
        strcpy(str,"\n\n You decided to stick to your original choice -> 'Door-");
        printDelay(str,40); 
        printf("%d'",choice);
        
        //printf("\n\n\n *** Press any key to Open the 'Door-%d' ***",choice);
        strcpy(str,"\n\n\n *** Press any key to Open the 'Door-");
        printDelay(str,40); 
        printf("%d'  ***",choice);
        
        getch();

        //Sleep(2000);
        //Draw doors
        drawDoors(2);

        if(door[choice-1] == 1)
        {
            //Game won
            winLose(true);
        }
        else
        {
            //Game Lost
            winLose(false);
        }
        
    }
    else
    {
        //printf("\n\n Please enter 'Y' or 'N' \n");
        strcpy(str,"\n\n Please enter 'Y' or 'N' \n");
        printDelay(str,40); 
        
        switchDoor();
    }

    repeat1:    
    //printf("\n\n Do you want to play again ? (Y/N) : ");
    strcpy(str,"\n\n Do you want to play again ? (Y/N) : ");
    printDelay(str,40); 
    
    scanf(" %c",&ch);
    if(ch=='Y' || ch=='y')
        main();
    else if(ch=='n' || ch=='N')
        printf("\n\n EXIT \n\n");
    else
        goto repeat1;
    

    return 0;
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
    for (c = 0; str1[c] != '\0'; c++) 
    {    
        printf("%c", str1[c]);   
        fflush(stdout); 
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

        //printf("\n\n |   Congratulations ! You Win a Car!   |");
        strcpy(str,"\n\n |   Congratulations ! You Win a Car!   |");
        printDelay(str,40);

        //printf("\n\n ***************************************");
        strcpy(str,"\n\n ***************************************");
        printDelay(str,10);
    }
    else
    {
        //printf("\n\n ****************");
        strcpy(str,"\n\n ****************");
        printDelay(str,10);

        //printf("\n\n |   You Lose   |");
        strcpy(str,"\n\n |   You Lose   |");
        printDelay(str,40);
        
        //printf("\n\n ****************");
        strcpy(str,"\n\n ****************");
        printDelay(str,10);
    }
}

void drawDoors(int open)
{
    printf("\n");

    int time =40;
    int doorNo = i+1;

    if(open == 0)
    {
        printf("\n----------------------------------------------------------------------------------------------------");delay(time);
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
        printf("\n----------------------------------------------------------------------------------------------------");delay(time);
        //printf("\n\t        Door 1      \t\t        Door 2      \t\t        Door 3\n");
    }

    else if(open == 1)
    {
        //When monty opens 1st door
        if(doorNo == 1)
        {
            printf("\n----------------------------------------------------------------------------------------------------");delay(time);
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
            printf("\n----------------------------------------------------------------------------------------------------");delay(time);
        }
    
        //When monty opens 2nd door
        else if(doorNo == 2)
        {
            
            printf("\n----------------------------------------------------------------------------------------------------");delay(time);
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
            printf("\n----------------------------------------------------------------------------------------------------");delay(time);
        }

        //When monty opens 3rd door
        else 
        {
            printf("\n----------------------------------------------------------------------------------------------------");delay(time);
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
            printf("\n----------------------------------------------------------------------------------------------------");delay(time);
        }

        //**********************************************************************************************
    }

    else if(open == 2)
    {
        //*********** FOR LAST DOOR OPENED is 2 *********************************************
        if(carDoor == 2)
        {
            printf("\n----------------------------------------------------------------------------------------------------");delay(time);
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
            printf("\n----------------------------------------------------------------------------------------------------");delay(time);
        }

        //**************** FOR LAST DOOR OPENED is 3 ******************************************
        else if(carDoor == 3)
        {
            printf("\n----------------------------------------------------------------------------------------------------");delay(time);
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
            printf("\n----------------------------------------------------------------------------------------------------");delay(time);
        }

        //*********** FOR LAST DOOR OPENED is 1 *********************************************
        else 
        {
            printf("\n----------------------------------------------------------------------------------------------------");delay(time);
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
            printf("\n----------------------------------------------------------------------------------------------------");delay(time);
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

