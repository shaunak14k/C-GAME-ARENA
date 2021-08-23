#include<stdio.h>
#include<string.h>
#include <windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>


char menu()
{
    char choice;
    int time=15;
    system("cls");
    
  
    //printf("\033[0;36m"); //CYAN
    // *** CYAN COLORED BORDER ***

    printf("\n\n  \033[0;36m__________________________________________________________ ");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                          \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                          \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                          \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m         *********\033[0;36m WORD SEARCH GAME \033[0m********              \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                          \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                          \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                          \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m         1.    Start the Game                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                          \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m         2.    How to play                                \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                          \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m         3.    Back to Main Menu                          \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                          \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                          \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|__________________________________________________________|\033[0m");Sleep(time);
    //printf("\n ------------------------------------------------------------ ");Sleep(time);

    menuLabel:
    printf("\n\n Enter your choice : ");
    scanf(" %c",&choice);

    // if a character is entered or a number is entered that's not in given choices
    if(choice!='1' && choice!='2' && choice!='3')
    {
        printf("\n\n Please enter appropriate values. Press any key to continue ");
        goto menuLabel;
    }
    system("cls");

    return choice;
}




void howToPlay()
{
    int time = 20;

    system("cls");

    //printf("\033[0;36m"); //CYAN
    // *** CYAN COLORED BORDER ***

    printf("\n\n \033[0;36m _____________________________________________________________________________________________________________ ");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                        *********\033[0;36m HOW TO PLAY \033[0m********                                       \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m          The Word search puzzle is a word game consist of the letters of  words  placed in a grid.          \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m          The objective of the game is to find all the words hidden inside word puzzle                       \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m          These word may be placed horizontallly,vertically or diagonally,                                   \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m          Either from left to right or right to left.                                                        \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m          Many word search puzzles provides list of of words, but as this is complex puzzle                  \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m          it will not provide you any list.                                                                  \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m          These words are related to \"C POGRAMMING\" Language                                                 \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m          Puzzle Consist of some words which are keyword's in  C Language                                    \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m          \033[0;36m** STRATEGY ** \033[0m                                                                                    \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m          For this game, you should be aware about keywords in C Language                                    \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m          A strategy to find all the words is to go through the puzzle (left to right or right to left)      \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m          and look for the first letter of the word                                                          \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m          Another Way to find words is to go row by row.First, all the horizontal rows should be             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m          read both backwards and forwards,then vertical and diagonal and so on.                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m          \033[0;36m** RULES ** \033[0m                                                                                       \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m          1) - Player Will have 10 attempts in hand.                                                         \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m          2) - In 10 attempt he will find 7 keywords which are hidden in puzzle                              \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m          3) - If he fails to locate keywords in 10 attempts, he will be out of the game automatically       \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m          4) - Score of the player will be displayed once the game is finished                               \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|\033[0m                                                                                                             \033[0;36m|\033[0m");Sleep(time);
    printf("\n \033[0;36m|_____________________________________________________________________________________________________________|\033[0m");Sleep(time);
    //printf("\n ---------------------------------------------------------------------------------------------------------------");Sleep(time);

    printf("\n\n  Press any key to go back  \n\n");
    getch();
}





void main()
{
    
    int i=0,score=0,j=0,k,attempt=1;
    int flag=0;
    int a[7] = {0,0,0,0,0,0,0};
    char input[7][20] = {"K N Z M C S D","S L R A J I S","H U S E O Q I","O E V V T N G","R E N U M X N","T G O T O Q E","N D W B O E D"};
    char ans[7][10] = {"case","enum","extern","goto","short","signed","void"};
    char str[30];
     char menuChoice;

    system("cls");
    menuChoice = menu();
    fflush(stdin);
    if(menuChoice=='1') {
    
    printf("\n\n");
    printf("\n\t\t\tIdentify the keyword in c language Located in above puzzle\n\n");
     for(k=0;k<7;k++) {
        printf("\t\t\t\t\t");
        for( j = 0; j < 13; ++j) {
           
             printf(" %c",input[k][j]);
             
        }
          printf("\n");      
    }

     printf("\n\t\t\t\t     Type Your Answers (Press '0'to Exit)\n");
    while(1)
    {     
         if(score==7 || attempt==10)
         break;
         printf("\n\t\t\t\t %d\t\t",attempt);
         gets(str);
         attempt++;
         system("cls");
         if(strcmp(str,"0")==0)
         break;
         for(i=0;i<7;i++)
         {
             flag=0;
             if(strcmp(str,ans[i])==0) 
                { 
                score++;
                 flag =1; Sleep(15);
                 if(a[i]==1) { printf("\n\n\t\t\t\t  Already Entered!(You have wasted 1 Move)");}
                 a[i]=1;
                 break;
                }
                
         }
         
             if(flag==1)
             {
                 printf("\n\n\t\t|--------------Perfect....! This is what you found Right?------------|\n\n\n ");
                for(k=0;k<7;k++) { 
                    
                    printf("\t\t\t\t\t"); Sleep(25);
                    for( j = 0; j < 13; ++j) {

                        if(  (a[6]==1) && ((k==0 && j==12) || (k==1 && j==10)   || (k==2 && j==8)  || (k==3 && j==6))) //void-RED
                        {
                            printf("\033[0;31m %c\033[0m",input[k][j]);
                        }
                        else if(  (a[4]==1) && ( (k==1 && j==0)   || (k==2 && j==0)  || (k==3 && j==0) || (k==4 && j==0) || (k==5 && j==0)))
                        {
                            printf("\033[0;36m %c\033[0m",input[k][j]);
                        }
                        else if(  (a[5]==1) && ((k==1 && j==12) || (k==2 && j==12)   || (k==3 && j==12)  || (k==4 && j==12) || (k==5 && j==12) || (k==6 && j==12)))
                        {
                            printf("\033[0;36m %c\033[0m",input[k][j]);
                        }
                        else if(  (a[3]==1) && ((k==5 && j==2) || (k==5 && j==4)   || (k==5 && j==6)  || (k==5 && j==8)))
                        {
                            printf("\033[0;35m %c\033[0m",input[k][j]);
                        }
/*extern-green   */     else if(  (a[2]==1) && ((k==5 && j==12) || (k==4 && j==10)   || (k==3 && j==8)  || (k==2 && j==6) || (k==1 && j==4)  || (k==0 && j==2)))
                        {
                            printf("\033[0;32m %c\033[0m",input[k][j]);
                        }
                        else if(  (a[1]==1) && ((k==4 && j==2) || (k==4 && j==4)   || (k==4 && j==6)  || (k==4 && j==8)))
                        {
                            printf("\033[0;34m %c\033[0m",input[k][j]);
                        }
                        else  if(  (a[0]==1) && ((k==0 && j==8) || (k==1 && j==6)   || (k==2 && j==4)  || (k==3 && j==2)))
                        {
                            printf("\033[0;33m %c\033[0m",input[k][j]);
                        }
                        else
                        {
                            printf(" %c",input[k][j]);
                        }

                        
             
                    }
                    printf("\n");      
                 }
                
             }
             else
             {
                printf("\n\n\t\t\t|-------------Oops...! You guessed it wrong!------------|\n\n\n ");

                  for(k=0;k<7;k++) { 
                    
                    printf("\t\t\t\t\t");   
                    for( j = 0; j < 13; ++j) {

                        if(  (a[6]==1) && ((k==0 && j==12) || (k==1 && j==10)   || (k==2 && j==8)  || (k==3 && j==6))) //void-RED
                        {
                            printf("\033[0;31m %c\033[0m",input[k][j]);
                        }
                        else if(  (a[4]==1) && ( (k==1 && j==0)   || (k==2 && j==0)  || (k==3 && j==0) || (k==4 && j==0) || (k==5 && j==0)))
                        {
                            printf("\033[0;36m %c\033[0m",input[k][j]);
                        }
                        else if(  (a[5]==1) && ((k==1 && j==12) || (k==2 && j==12)   || (k==3 && j==12)  || (k==4 && j==12) || (k==5 && j==12) || (k==6 && j==12)))
                        {
                            printf("\033[0;36m %c\033[0m",input[k][j]);
                        }
                        else if(  (a[3]==1) && ((k==5 && j==2) || (k==5 && j==4)   || (k==5 && j==6)  || (k==5 && j==8)))
                        {
                            printf("\033[0;35m %c\033[0m",input[k][j]);
                        }
/*extern-green   */     else if(  (a[2]==1) && ((k==5 && j==12) || (k==4 && j==10)   || (k==3 && j==8)  || (k==2 && j==6) || (k==1 && j==4)  || (k==0 && j==2)))
                        {
                            printf("\033[0;32m %c\033[0m",input[k][j]);
                        }
                        else if(  (a[1]==1) && ((k==4 && j==2) || (k==4 && j==4)   || (k==4 && j==6)  || (k==4 && j==8)))
                        {
                            printf("\033[0;34m %c\033[0m",input[k][j]);
                        }
                        else  if(  (a[0]==1) && ((k==0 && j==8) || (k==1 && j==6)   || (k==2 && j==4)  || (k==3 && j==2)))
                        {
                            printf("\033[0;33m %c\033[0m",input[k][j]);
                        }
                        else
                        {
                            printf(" %c",input[k][j]);
                        }

                        
             
                    }
                    printf("\n");      
                 }

                 
             }
                if(attempt == 10)
                {
                    printf("\n\n\t\t\t\tYou Have reached the maximum attempts\n\n");
                }
             if(score!=7 && (attempt!=10))
         printf("\n\n\t\t\tDid You find something...! Else Press 0 to exit.....\n");
    }
    if(score<=2)
    printf("\n\n\t\t\t\t\033[0;36mUmmm, it seems you havent studied \"C\" Language  \033[0m\n\n" );
    else if(score>2 && score <=5)
    printf("\n\n\t\t\t\033[0;36mGreat,still you can study more to become master in \"C\"  \033[0m\n\n");
    else
    printf("\n\t\t\tCongratulations..!, You have very good command on C Language\n");
    printf("\n\n\t\t\t\t  \033[0;33m*** You Have Scored %d out of 7 ***\033[0m\n\n\n",score);

     printf("\n\n\t\t\t\t     Press any key to go back  \n\n");
    if(getch())
    main();
    }
    
    else 
    if(menuChoice=='2') {
        howToPlay(); 
                    main();
    }
}