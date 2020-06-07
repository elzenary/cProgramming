/*

array has 7 elements input  from user
display the array

*/

#include<stdio.h>
#include<conio.h>
#define size 7
void main(void)
{

//variables declerations
int arr[size];//declare array
int i; //declare loop counter

//getting input from the uswr
for(i=0;i< size;i++)
{
printf("please enter element no%d:  ",i+1);
scanf("%d",&arr[i]);
}

//displaying output in reverse order
for(i=size-1;i>-1;i--)
printf("%d, ",arr[i]);

//new line and getch for viewing screen
printf("\n");
getch();

}