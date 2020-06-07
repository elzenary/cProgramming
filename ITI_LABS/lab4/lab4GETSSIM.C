/*
getsSimulation.c

  gets sumulation using getch
  continue getting values until pressing enter
  or
  until reaching the maximum length of the array

*/
//library include
#include<stdio.h>
#include<conio.h>
#include<string.h>

//definitions
#define MAX_STR 10
#define ENTER 13
void main(void)
{
 //variables decleration and definition
 int quitFlag=0;
 int counter=0;
 char str[MAX_STR] ;
 char ch;

 printf("please enter string: ");

 //looping during getting word until quit flag is updated
 while(!quitFlag){

	//read the input char and print it on screen immediately
	flushall();
	ch=getche();

	 //update terminate flag is enter is pressesd
	if(ch==ENTER)
		quitFlag=1;

	 //update terminate flag if user get maximum
	//after that increase the counter
	if(counter++==MAX_STR-1)
		quitFlag=1;

	//update str if quit flag equals 0
	//other wise put the null terminator
	if(!quitFlag)
		str[counter]=ch;
	else
		str[counter]='\0';


 }//while end

 //print the string
 puts("\nyour name is: ");
 puts(str);

getch();//hold the screen

}//main end