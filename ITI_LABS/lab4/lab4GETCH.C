/*
	getch.c

	ask user to input character
	find out if it is normal or extended key
	and find out its ascii representation
	*/

//include libraries
#include<stdio.h>
#include<conio.h>

//definitions
#define ESC 27

void main(void)
{
	char ch;//variable to hold input character

	//looping to get characters
	do{
		ch= getch();//get first character

		//check if the input character is null or not
		if(ch==0)
		{
		//extended key condition
			printf("extended");
			ch=getch();
		}
		else
		{
		//normal key condition
		 printf("normal");
		}

		printf("%d\n",ch); //print the character ascii

		 }while(ch!=ESC);//loop until getting ESC key pressed
}//main end