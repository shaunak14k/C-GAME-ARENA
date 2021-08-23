#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

void sectionCards();
void sectionCardsReverse();
int deal_cards();
void generateRandom();

int cards[21];
int cards1[7];
int cards2[7];
int cards3[7];
int n=21;

int main()
{
    int i,j,k,choice;
    char charChoice;
    
    //Random numbers for array
    generateRandom();
   
    printf("\n\n");

    printf("**************************************************************************************************************\n\n");
    //Printing all numbers in array
    for(i=0;i<n;i++)
    {
        printf("%5d",cards[i]);
    }

    printf("\n\n");

    printf("   Pick any number from above and remember it.\n\n");
    printf("**************************************************************************************************************\n");
    
    printf("\n Press any key to conitnue..\n");

    

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

    printf(" \n\n\n****** The number you picked was : '%d' ******\n\n\n",cards[10]);

    printf("\n Do you want to play again ? (Y/N) : ");
    scanf(" %c",&charChoice);
    
    if(charChoice=='Y' || charChoice=='y')
        main();

    printf("\n\n Exited from the game \n\n\n");

    return 0;
}

int deal_cards()
{
    int i,j,k,choice;

    //Display numbers to user in 3 columns
    printf("\n\n\t______________________________________________\n");
    printf("\n\t    column 1 \t   column 2 \t column 3\n");
    printf("\t______________________________________________\n\n");
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
                printf("      %d      |",cards[k]);
            else if(dig==1)
                printf("      %d       |",cards[k]);

            
            k++;
        }
        if(i==6)
            continue;

        // 14 spaces
        printf("\n\t|              |              |              |\n\t|");
    }

    //Loop to ensure correct inputs are given
    do
    {
        printf("\n\n\n In which column is your number ? : ");
        scanf("%d",&choice);

        if(choice<1 || choice>3)
        {
            printf("\n\n ** Please enter a valid column number **\n");
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