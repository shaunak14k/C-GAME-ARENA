#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	
	int ch;

	//printf("\033[0;35m"); //PURPLE
    // *** PURPLE COLORED BORDER ***

	system("cls");

	printf("\n\n \033[0;35m ____________________________________________________ ");
    printf("\n \033[0;35m|\033[0m                                                    \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                                                    \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                                                    \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m         *********\033[0;35m QUIZ GAME \033[0m********               \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                                                    \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                                                    \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                                                    \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m         1.    Start the Game                       \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                                                    \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m         2.    How to Play                          \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                                                    \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m         3.    Back to Main Menu                    \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                                                    \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                                                    \033[0;35m|\033[0m");
    printf("\n \033[0;35m|____________________________________________________|\033[0m\n");
    //printf("\n ------------------------------------------------------ ");
	
	printf("\n\n Enter your choice : ");
	scanf("%d",&ch);
	switch (ch)
  	{
  	case 1:
		system("cls");
		main1();
    	break;
  	case 2:
  			system("cls");

  	
       
	//printf("\033[0;35m"); //PURPLE
    // *** PURPLE COLORED BORDER ***
	printf("\n\n  \033[0;35m__________________________________________________________________________________________________");
    printf("\n \033[0;35m|\033[0m                                                                                                  \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                                                                                                  \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                                                                                                  \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                                    *********\033[0;35m HOW TO PLAY \033[0m********                                \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                                                                                                  \033[0;35m|\033[0m");
	printf("\n \033[0;35m|\033[0m                                                                                                  \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                                                                                                  \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m              Here are some tips you might wanna know before playing:                             \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                                                                                                  \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m              >> There are 3 Subjects- Verbal, General Knowledge, Computer Minds                  \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                                                                                                  \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m              >> Once your game starts, you will be asked with 10 questions of                    \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                 the subject you've selected                                                      \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                                                                                                  \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m              >> Total of 10 questions. Each right answer will be awarded 1 point!                \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                                                                                                  \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m              >> You will be given 4 options and you have to press A, B ,C or D for the           \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                 right option.                                                                    \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                                                                                                  \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m              >> No negative marking for wrong answers                                            \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                                                                                                  \033[0;35m|\033[0m");
	printf("\n \033[0;35m|\033[0m                                                                                                  \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                                                                                                  \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                            !!!!!!!!!!!!!\033[0;35m ALL THE BEST \033[0m!!!!!!!!!!!!!                              \033[0;35m|\033[0m");
    printf("\n \033[0;35m|\033[0m                                                                                                  \033[0;35m|\033[0m");
	printf("\n \033[0;35m|\033[0m                                                                                                  \033[0;35m|\033[0m");
    printf("\n \033[0;35m|__________________________________________________________________________________________________|\033[0m");
   
		
		printf("\n\n  Press any key to go back  \n\n");
		getch();
    	system("cls");
		main();
		break;
  	case 3:
    	printf("\n\n\n\tBACK TO MAIN MENU");
		exit(0);
    	break;
  case 4:
    	exit(0);
    	break;
  	}  
 	return 0;
}


void main1()
{
	int ch;
	char playername[20];
    char temp1;	

    //printf("\033[0;35m"); //PURPLE
    // *** PURPLE COLORED BORDER ***

	system("cls");

	do
	{    
    	printf("\n\n\t  \033[0;35m____________________________________________________ ");
    	printf("\n\t \033[0;35m|\033[0m                                                    \033[0;35m|\033[0m");
    	printf("\n\t \033[0;35m|\033[0m                                                    \033[0;35m|\033[0m");
    	printf("\n\t \033[0;35m|\033[0m                                                    \033[0;35m|\033[0m");
    	printf("\n\t \033[0;35m|\033[0m          ******\033[0;35m QUIZ MASTERS LEAGUE \033[0m******         \033[0;35m|\033[0m");
    	printf("\n\t \033[0;35m|\033[0m                                                    \033[0;35m|\033[0m");
	    printf("\n\t \033[0;35m|\033[0m                                                    \033[0;35m|\033[0m");
	    printf("\n\t \033[0;35m|\033[0m                                                    \033[0;35m|\033[0m");
	    printf("\n\t \033[0;35m|\033[0m         1.    VERBAL                               \033[0;35m|\033[0m");
	    printf("\n\t \033[0;35m|\033[0m                                                    \033[0;35m|\033[0m");
	    printf("\n\t \033[0;35m|\033[0m         2.    GENERAL KNOWLEDGE                    \033[0;35m|\033[0m");
	    printf("\n\t \033[0;35m|\033[0m                                                    \033[0;35m|\033[0m");
	    printf("\n\t \033[0;35m|\033[0m         3.    COMPUTING MINDS                      \033[0;35m|\033[0m");
	    printf("\n\t \033[0;35m|\033[0m                                                    \033[0;35m|\033[0m");
	    printf("\n\t \033[0;35m|\033[0m         4.    QUIT                                 \033[0;35m|\033[0m");
	    printf("\n\t \033[0;35m|\033[0m                                                    \033[0;35m|\033[0m");
		 printf("\n\t \033[0;35m|\033[0m                                                    \033[0;35m|\033[0m");
	    printf("\n\t \033[0;35m|____________________________________________________|\033[0m");
	    //printf("\n\t ------------------------------------------------------ ");

	label1:
		printf("\n\n\t Select your Quiz Subject : ");
 		scanf("%d", &ch);
		if(ch==4)
		{
			main();
		}
		if (ch < 1 || ch > 4)
 		{
    		printf("Please Select a Valid Input\n\n");
    		goto label1;
  		}
		  
  		printf("\n\t Enter your name : ");
 		scanf("%s", playername);
  		
  		system("cls");

 	switch (ch)
  	{
		case 1:
			printf("\n\n\n\t \033[0;35m Congratulations %s! \033[0m \n\n\t MARKS OBTAINED IN VERBAL ABILITY ARE :\033[0;35m %d \033[0m", playername, verbal());
			break;

		case 2:
			printf("\n\n\n\t \033[0;35m Congratulations %s! \033[0m \n\n\t MARKS OBTAINED IN GENERAL KNOWLEDGE ARE :\033[0;35m %d \033[0m",playername, gk());
			break;

		case 3:
			printf("\n\n\n\t \033[0;35m Congratulations %s! \033[0m \n\n\t MARKS OBTAINED IN  COMPUTER MINDS ARE :\033[0;35m %d \033[0m", playername, comp());
			break;

		case 4:
			main();
			break;
   	} 		
  
  	printf("\n\n  Press any key to go back  \n\n");
		getch();
		system("cls");
		main();
	}
	while(temp1=='y');
}




char getch1()
{
	char temp;
	label2:
	temp=getch();
	if(toupper(temp=='A'||temp=='B'||temp=='C'||temp=='D'||temp=='a'||temp=='b'||temp=='c'||temp=='d'))
	{
		return temp;
	}
	else
	{
		printf("Please Select Valid Choice\n");
		goto label2;
	}
}
int verbal()
{
 	int count = 0;
	printf("\n\n\n 1. Read the sentence to find out whether there is any grammatical error in it. \n");
	printf("\n\n \033[0;32mA) \033[0m We discussed about the problem so thoroughly.	\n\n \033[0;35mB) \033[0m on the eve of the examination \n\n \033[0;36mC) \033[0m that I found it very easy to work it out. \n\n \033[0;33mD) \033[0m No error.\n\n");
	printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='A')
	{
		count++;
	}  
  	system("cls");

	printf("\n\n\n 2. In the following the questions choose the word which best expresses the meaning of the given word.\n\t\t BRIEF");
	printf("\n\n\033[0;32mA) \033[0m Limited\t\t\033[0;35mB) \033[0m Small\n\n\033[0;36mC) \033[0m Little\t\t\033[0;33mD) \033[0m Short\n\n");
	printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='D')
	{
		count++;
	}
  	system("cls");
  	printf("\n\n\n 3. Choose the correct meaning of proverb/idiom: ");
  	printf("\n\n\033[0;32mA) \033[0m To keeps one's temper\t\033[0;35mB) \033[0m To be in good mood\n\n\033[0;36mC) \033[0m To preserve ones energy\t\033[0;33mD) \033[0m To be aloof from\n\n");
  	printf("\n\n Enter the correct option : ");
	  if(toupper(getch1())=='B')
  	{
    	count++;
  	}
  	system("cls");
  	printf("\n\n\n 4. Find correct meaning of idiom: To have an axe to grind ");
  	printf("\n\n\033[0;32mA) \033[0m private end to serve\t\t\t\033[0;35mB) \033[0m To fail to arouse interest\n\n\033[0;36mC) \033[0m To have no result \t\t\t\033[0;33mD) \033[0m To work for both sides \n\n");
  	printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='A')
 	{
 	   count++;
  	}
  	system("cls");
  	printf("\n\n\n 5. Choose the one which can be substituted for the given word/sentence.\n	'Extreme old age when a man behaves like a fool'");
  	printf("\n\n\033[0;32mA) \033[0m Imbecility\t\t\033[0;35mB) \033[0m Senility \n\n\033[0;36mC) \033[0m Dotage\t\t\033[0;33mD) \033[0m Superannuation\n\n");
  	printf("\n\n Enter the correct option : ");
	  if(toupper(getch1())=='C')
  	{
    	count++;
  	}
  	system("cls");
  	printf("\n\n\n 6. Choose the one which best expresses the given sentence in Indirect/Direct speech.\n\n\n Question: 'If you don't keep quiet I shall shoot you, he said to her in a calm voice.'");
	printf("\n\n\033[0;32mA) \033[0m He warned her to shoot if she didnt keep quiet calmly.\n\n\033[0;35mB) \033[0m He said calmly that I shall shoot you if you dont be quiet.\n\n\033[0;36mC) \033[0m He warned her calmly that he would shoot her if she didnt keep quiet. \n\n\033[0;33mD) \033[0m Calmly he warned her that be quiet or else he will have to shoot her.\n\n");
	printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='C')
	{
		count++;
  	}
	system("cls");
  	printf("\n\n\n 7. Select the pair which has the same relationship: INDIGENT:WEALTHY");
    printf("\n\n\033[0;32mA) \033[0m angry:rich	\t\t\033[0;35mB) \033[0m native:affluent\n\n\033[0;36mC) \033[0m gauche:graceful \t\t\033[0;33mD) \033[0m scholarly:erudite\n\n");
    printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='C')
    {
    	count++;
    }
    system("cls");
    printf("\n\n\n 8. Find the correctly spelt words:");
    printf("\n\n\033[0;32mA) \033[0m Efficient\t\t\033[0;35mB) \033[0mTreatmeant\n\n\033[0;36mC) \033[0mBeterment\t\t\033[0;33mD) \033[0mEmployee\n\n");
    printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='A')
    {
    	count++;
    }
    system("cls");
    printf("\n\n\n 9. Join these parts to make a meaningful sentence.\n\n\n 1. I  2. immediately  3. salary  4. my  5. want");
    printf("\n\n\033[0;32mA) \033[0m 43152\t\t\033[0;35mB) \033[0m15432\n\n\033[0;36mC) \033[0m25143\t\t\033[0;33mD) \033[0m42351\n\n");
    printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='B')
  	{
    	count++;
  	}	
  	system("cls");
  	printf("\n\n\n 10. Choose the word which is the exact OPPOSITE of the given words:ENORMOUS");
  	printf("\n\n\033[0;32mA) \033[0m Soft\t\t\033[0;35mB) \033[0m Average\n\n\033[0;36mC) \033[0m Tiny\t\t\033[0;33mD) \033[0m Weak\n\n");
  	printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='C')
  	{
    	count++;
  	}
  	system("cls");
  	return count;
}

/***************************************************************************************************************************************/
int gk()
{
	int count = 0;
  	printf("\n\n\n 1. National Income estimates in India are prepared by ");
  	printf("\n\n\033[0;32mA) \033[0m Planning Commission	\t\t\033[0;35mB) \033[0m Reserve Bank of India \n\n\033[0;36mC) \033[0m Central statistical organisation \t\033[0;33mD) \033[0m Indian statistical Institute");
  	printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='C')
  	{  	
   		count++;
  	}
  	system("cls");

  	printf("\n\n\n 2. The purest form of Iron is \n ");
  	printf("\n\n\033[0;32mA) \033[0m Wrought Iron \t\033[0;35mB) \033[0m Steel\n\n\033[0;36mC) \033[0m Pig Iron\t\t\033[0;33mD) \033[0m Nickel Steel\n\n");
  	printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='A')
  	{
    	count++;
  	}
  	system("cls");

  	printf("\n\n\n 3. Fathometer is used to measure: ");
  	printf("\n\n\033[0;32mA) \033[0m Earthquakes\t\t\033[0;35mB) \033[0m Rainfall\n\n\033[0;36mC) \033[0m Ocean depth\t\t\033[0;33mD) \033[0m Sound intensity\n\n");
  	printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='C')
  	{
   		count++;
  	}
  	system("cls");

  	printf("\n\n\n 4. Who is the author of the book Freedom Behind Bars  ");
  	printf("\n\n\033[0;32mA) \033[0m Kiran Bedi\t\t\033[0;35mB) \033[0m Jawaharlal Nehru\n\n\033[0;36mC) \033[0m Nelson Mandela\t\033[0;33mD) \033[0m Sheikh Abdullah \n\n");
  	printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='A') 
  	{
    	count++;
  	}
  	system("cls");
  	printf("\n\n\n 5. Which river of India is called Vridha Ganga?");
  	printf("\n\n\033[0;32mA) \033[0m Krishna\t\t\033[0;35mB) \033[0m Godavari \n\n\033[0;36mC) \033[0m Kaveri\t\t\033[0;33mD) \033[0m Narmada\n\n");
  	printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='B')
  	{
   		count++;
  	}
  	system("cls");
  	printf("\n\n\n 6. Golf player Vijay Singh belongs to which country?");
  	printf("\n\n\033[0;32mA) \033[0m USA\t\t\033[0;35mB) \033[0m Fiji \n\n\033[0;36mC) \033[0m India \t\033[0;33mD) \033[0m UK\n\n");
  	printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='B')
 	{
    	count++;
  	}
  	system("cls");
  	printf("\n\n\n 7. 'One People, One State, One leader' was the policy of");
  	printf("\n\n\033[0;32mA) \033[0m Stalin \t\t\033[0;35mB) \033[0m Hitler \n\n\033[0;36mC) \033[0m Lenin \t\t\033[0;33mD) \033[0m Mussolin\n\n");
  	printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='B')
 	{
   		count++;
  	}
  	system("cls");
  	printf("\n\n\n 8. Who is known as 'The Father of Indian Missile Technology'?");
  	printf("\n\n\033[0;32mA) \033[0m Dr. U.R. Rao\t\t\033[0;35mB) \033[0m Dr. A.P.J. Abdul Kalam \n\n\033[0;36mC) \033[0m Dr. Chidambaram\t\033[0;33mD) \033[0m Dr. Homi Bhabha\n\n");
  	printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='B')
 	{
    	count++;
  	}
  	system("cls");
  	printf("\n\n\n 9. DRDL stands for");
  	printf("\n\n\033[0;32mA) \033[0m Defence Research and Development Laboratory \n\n\033[0;35mB) \033[0m Department of Research and Development Laboratory\n\n\033[0;36mC) \033[0m Differential Research and Documentation Laboratory\n\n\033[0;33mD) \033[0m None of the above\n\n");
  	printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='A')
 	{
    	count++;
  	}
  	system("cls");
  	printf("\n\n\n 10. Who said 'Inflation is unjust but deflation is inexpedient. Of the two, deflation is worse' ?");
  	printf("\n\n\033[0;32mA) \033[0m J.M Keynes \t\t\033[0;35mB) \033[0m Amartya Sen\n\n\033[0;36mC) \033[0m J.G Gurlay\t\t\033[0;33mD) \033[0m J.N Bhagwati\n\n");
  	printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='A')
   	{
    	count++;
  	}
  	system("cls"); 	
  	return count;
}

/*************************************************************************************************************************************************/
int comp()
{  
	int count = 0;
  	printf("\n\n\n 1. Name of the screen that recognizes touch input is :");
  	printf("\n\n\033[0;32mA) \033[0m Recog Screen	\t\t\033[0;35mB) \033[0m Point Screen \n\n\033[0;36mC) \033[0m Touch Screen \t\t\033[0;33mD) \033[0m Android Screen\n");
 	printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='C')
  	{
    	count++;
  	}
  	system("cls");

  	printf("\n\n\n 2. Identify the device through which data and instructions are entered into a computer ,\n");
  	printf("\n\n\033[0;32mA) \033[0m Software \t\t\033[0;35mB) \033[0m Output Device\n\n\033[0;36mC) \033[0m Input Device\t\t\033[0;33mD) \033[0m Memory\n\n");
  	printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='C')
 	{
    	count++;
  	}
  	system("cls");

  	printf("\n\n\n 3. Computer Moniter is also known as : ");
  	printf("\n\n\033[0;32mA) \033[0m DVU\t\t\033[0;35mB) \033[0m UVD\n\n\033[0;36mC) \033[0m VDU\t\t\033[0;33mD) \033[0m CCTV\n\n");
  	printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='C')
 	{
    	count++;
  	}
  	system("cls");

  	printf("\n\n\n 4. Arrange in ascending order the units of memory TB, KB, GB, MB  ");
  	printf("\n\n\033[0;32mA) \033[0m TB>GB>MB>KB \t\t\033[0;35mB) \033[0m TB>MB>GB>KB\n\n\033[0;36mC) \033[0m MB>GB>TB>KB\t\t\033[0;33mD) \033[0m GB>MB>KB>TB\n\n");
  	printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='A')
  	{
    	count++;
  	}
  	system("cls");
  	printf("\n\n\n 5. Which one of these stores more data than a DVD ?");
  	printf("\n\n\033[0;32mA) \033[0m CD ROM\t\t\033[0;35mB) \033[0m Blue Ray Disk \n\n\033[0;36mC) \033[0m Floppy\t\t\033[0;33mD) \033[0m Red Ray Disk\n\n");
  	printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='B')
 	{
    	count++;
  	}
  	system("cls");
  	printf("\n\n\n 6. Eight Bits make up a");
  	printf("\n\n\033[0;32mA) \033[0m byte\t\t\033[0;35mB) \033[0m megabyte \n\n\033[0;36mC) \033[0m kilobyte\t\033[0;33mD) \033[0m None\n\n");
  	printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='A')
 	{
    	count++;
  	}
  	system("cls");
  	printf("\n\n\n 7. Which one is the result of the output given by a computer");
  	printf("\n\n\033[0;32mA) \033[0m Instruction \t\t\033[0;35mB) \033[0m Excursion \n\n\033[0;36mC) \033[0m Data \t\t\033[0;33mD) \033[0m Information\n\n");
  	printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='D')
 	{
    	count++;
  	}
  	system("cls");
  	printf("\n\n\n 8. The output shown on the computer monitor is called");
  	printf("\n\n\033[0;32mA) \033[0m VDU\t\t\033[0;35mB) \033[0m Screen Copy \n\n\033[0;36mC) \033[0m Soft Copy\t\033[0;33mD) \033[0m Hard Copy\n\n");
  	printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='C')
 	{
    	count++;
  	}
  	system("cls");
  	printf("\n\n\n 9. Which one of these also known as read/write memory ?");
  	printf("\n\n\033[0;32mA) \033[0m ROM \t\t\033[0;35mB) \033[0m RAM\n\n\033[0;36mC) \033[0m DVD\t\t\033[0;33mD) \033[0m None of the above\n\n");
  	printf("\n\n Enter the correct option : ");
	if(toupper(getch1())=='B')
  	{
    	count++;
  	}
  	system("cls");
  	printf("\n\n\n 10. The printed output from a computer is called");
  	printf("\n\n\033[0;32mA) \033[0m Copy \t\t\033[0;35mB) \033[0m Soft Copy \n\n\033[0;36mC) \033[0m Paper\t\t\033[0;33mD) \033[0m Hard Copy\n\n");
	printf("\n\n Enter the correct option : ");
  	if(toupper(getch1())=='D')
 	{
 		count++;
  	}
  	system("cls"); 
  	return count;
}


