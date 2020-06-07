/*
  SUM.C
	author aRaafat

  ask the user to enter numbers until reaching 100
  if the sum exceds 100 don't accept the num
  continue looping until getting the specified target

*/

//libraries inluding
#include<stdio.h>//dealing with printf scanf functions
#include<conio.h>//dealing with getch/clrscr function

void main(void)
{
	int temp; //temp variable to store the user input num
	int sum=0;//counter variable to get the sum

	clrscr();//clear the output screen

  do{
	 //ask the user to enter num and scan it
	 printf("please enter num");
	 scanf("%d",&temp);

	 //make counter for the user entered numbers
	 sum+=temp;

	 //check if sum exceds 100 don't accept it and ignore last input
	 if(sum>100)
	  {
		printf("num not accepted sum exceds 100 \n");
		sum-=temp;//if you sub the last input from sum then you ignore it
	  }
	  //print the current accepted sum for the user
	 printf("accepted sum: %d\n",sum);
  }while(sum!=100);//loop until getting the target sum=100

	printf("\n target is reached \n");//target achieving user messege
	getch();//wait character to end the program to see the screen
}