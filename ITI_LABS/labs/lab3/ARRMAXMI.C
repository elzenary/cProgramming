/*
  take 10 integer values from the user
  calcoulat the sum
  calculate the average

*/
#include<stdio.h>
#include<conio.h>
#define size 10
void main(void)
{
	//variables decleration
	int arr[10];
	int max;
	int min;
	int i;

	//getting input from user
	for(i=0;i<size;i++)
	{
		printf("please enter element no %d:  ",i);
		scanf("%d",&arr[i]);

	}
	//assume max min the first element at begining
	max=arr[0];
	min=arr[0];

	//getting maximum / minimum algorithm
	 for(i=1;i<size;i++)
	 {
	  if(arr[i]>max)
			max=arr[i];
	  if(arr[i]<min)
			min=arr[i];
	 }

	 //printing maximum minimum values
	 printf("max is:%d\nmin is:%d\n",max,min);
	 getch();//wait to see the screen
}