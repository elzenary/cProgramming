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
//use one of these options depending on your needs
//#define MODULARITY
#define PERFORMANCE
//entry point
void main(void)
{
 //variables decleration
 char firstName[NUM_USERS][MAX_LEN];
 char secondName[NUM_USERS][MAX_LEN];
 char fullName[NUM_USERS][2*MAX_LEN];
 int i,j;//loop counters




/*
 in performance approach the purpose is
 solving the problem with the minimum number of loops
*/

 #ifdef PERFORMANCE
 //performence approach
 for(i=0;i< NUM_USERS;i++)
 {

   /*
	ask user to enter values
	copy them and concatenate them in the big array
	number of iterations equal the number of users
   */

	//getting first array input
	printf("please enter first name of user %d",i+1);
	gets(firstName[i]);

	//getting second array input
	printf("please enter second name of user %d",i+1);
	gets(secondName[i]);

	//processing part copying and concatenating in the big array
	strcpy(fullName[i],firstName[i]);
	strcat(fullName[i]," ");
	strcat(fullName[i],secondName[i]);

	//printing the big array elements
	printf("name of user %d: ",i+1);
	puts(fullName[i]);
	printf("\n");
 }
#endif



/*
 in modularity approach the code is divided into different blocks
 input processing output
*/

#ifdef MODULARITY

 //input block
 for(i=0;i< NUM_USERS;i++)
 {
	//getting first array input
	printf("please enter first name of user %d",i+1);
	gets(firstName[i]);
	//getting second array input
	printf("please enter second name of user %d",i+1);
	gets(secondName[i]);
 }

 //processing block
   for(i=0;i< NUM_USERS;i++)
 {
	//processing part copying and concatenating in the big array
	strcpy(fullName[i],firstName[i]);
	strcat(fullName[i]," ");
	strcat(fullName[i],secondName[i]);
 }


 //print the big array
  for(i=0;i< NUM_USERS;i++)
 {
	printf("name of user %d: ",i+1);
	puts(fullName[i]);
	printf("\n");
 }

#endif//end of modularity aproach precompilation condition


 getch();//hold the screen

}//end of main