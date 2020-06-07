/*
  SWITCHCH.C
	author aRaaft
	lastEdit 14/10/2017

  ask user to input character of his first track
  then print the track name
  implementation using switch case
*/

//libraries include
#include<stdio.h>  //for printf/scanf functions
#include<conio.h>  //for getch/clrScr function


void main(void)
{
 char ch;//variable to hold user input character
 int terminate=0;//change it to 1 if a valid data is entered

 do{//looping until getting valid character
	clrscr();//clear the output screen
	//ask user to enter char and getting the char storing it ch var
	printf("pleas enter valid char ");
	ch=getch();

	//switch case to check input letter and print the appropiate track
	switch(ch)
	{
		case 'E':
		case 'e':
			printf("embedded");	terminate=1;  break;
		case 's':
		case 'S':
			printf("sd");	terminate=1;  break;
		case 'o':
		case 'O':
			printf("openSource");	terminate=1;   break;
	}
 }while(!terminate);//keep looping until terminate condition happens

   getch();//to wait user input to be able to see the output screen

}  //main end curly braces