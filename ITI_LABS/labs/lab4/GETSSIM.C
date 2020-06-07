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
 int quitFlag=0;
 int counter=0;
 char str[MAX_STR] ;
 char ch;

 printf("please enter string: ");
 while(!quitFlag){

	flushall();
	ch=getche();

	if(ch==ENTER)
		quitFlag=1;

	if(counter++==MAX_STR-1)
		quitFlag=1;

	if(!quitFlag)
		str[counter]=ch;
	else
		str[counter]='\0';


 }
 printf("\nyour name is: ");
 puts(str);

getch();//hold the screen

}