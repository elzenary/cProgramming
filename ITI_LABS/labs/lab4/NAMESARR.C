/*
nameArr.c
	ask n users to enter first second names
	store them in  2 different arrays
	concatinate them in a big array
	print it
*/

//include libraries
#include<stdio.h>
#include<conio.h>
#include<string.h>

//definitions
#define MAX_LEN 10
#define NUM_USERS 4
//entry point
void main(void)
{
 //variables decleration
 char firstName[NUM_USERS][MAX_LEN];
 char secondName[NUM_USERS][MAX_LEN];
 char fullName[NUM_USERS][2*MAX_LEN];
 int i,j;//loop counters

 /*
 ask user to enter values
 copy them and concatenate them in the big array
 number of iterations equal the number of users
 */
 //input and processing block
 for(i=0;i< NUM_USERS;i++)
 {
	printf("please enter first name of user %d",i+1);
	gets(firstName[i]);
	printf("please enter second name of user %d",i+1);
	gets(secondName[i]);
	strcpy(fullName[i],firstName[i]);
	strcat(fullName[i]," ");
	strcat(fullName[i],secondName[i]);
 }

 //print the big array
  for(i=0;i< NUM_USERS;i++)
 {
	printf("name of user %d: ",i);
	puts(fullName[i]);
	printf("\n");
 }

 getch();//hold the screen
}