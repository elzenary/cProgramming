
/*
  struct.c
  author ahmedRaafat
  last edit 14/10/2017

	build struct has
	ID      salary
	name    bonus
	age		reduction

	in this array for n number of users
	then print it with
	ID
	Name
	net salary=salary+bonus-reduction
*/

//include libraries
#include<stdio.h>
#include<conio.h>
#include<string.h>

//define
#define NAME_LEN 10
#define USERS 3
#define COL1 15
#define COL2 30
#define ROW 10
#define STRUCT_ELEMENTS 6


 //definee sturcture elements
 struct Employee
 {
  int id;
  char name[NAME_LEN];
  int age;
  float salary;
  float bonus;
  float reduction;
 };

//functions prototypes
void addEmployees(struct Employee [],int size);

//void addEmployees(struct Employee emp[],int size)
void displayEmployees(struct Employee [],int size);

//entry point
void main(void)
{

 //define array of structure
  struct Employee emp[USERS];

  //add  empployees
  addEmployees(emp,USERS);

  //display employees
  displayEmployees(emp,USERS);

 getch();//hold the screen

}//end of main

void addEmployees(struct Employee emp[],int size)
{


 //define variables
 int i;//loop counter
 int tempInt=0;
 float tempFloat=0.0;//temp variable

 //asking user to enter input
 for(i=0;i<size;i++)
 {

	//printing labels
	clrscr();
	gotoxy(1,1);
	printf("user %d",i+1);

	gotoxy(COL1,ROW);
	printf("ID: ");

	gotoxy(COL1,ROW+2);
	printf("name: ");

	gotoxy(COL1,ROW+4);
	printf("age: ");

	gotoxy(COL2,ROW);
	printf("salary: ");

	gotoxy(COL2,ROW+2);
	printf("bonus: ");

	gotoxy(COL2,ROW+4);
	printf("deduction: ");

	//go to cursor to input positions
	//scaning user inputs
	gotoxy(COL1+7,ROW);
	flushall();
	scanf("%d",&tempInt);
	emp[i].id=tempInt;

	gotoxy(COL1+7,ROW+2);
	flushall();
	gets(emp[i].name);

	gotoxy(COL1+7,ROW+4);
	flushall();
	scanf("%d",&tempInt);
	emp[i].age=tempInt;

	gotoxy(COL2+7,ROW);
	flushall();
	scanf("%f",&tempFloat);
	emp[i].salary=tempFloat;

	gotoxy(COL2+7,ROW+2);
	flushall();
	scanf("%f",&tempFloat);
	emp[i].bonus=tempFloat;

	gotoxy(COL2+10,ROW+4);
	flushall();
	scanf("%f",&tempFloat);
	emp[i].reduction=tempFloat;

 }//end of getting struct inputs

}



 void displayEmployees(struct Employee emp[],int size)
{


 //define variables
 int i;//loop counter

 //print the output
  for(i=0;i<size;i++)
 {
	clrscr();
	gotoxy(COL1,ROW);
	printf("emp no:%d ",i+1);
	gotoxy(COL1,ROW+1);
	printf("ID:%d ",emp[i].id);
	gotoxy(COL1,ROW+2);
	printf("name:%s",emp[i].name);
	gotoxy(COL1,ROW+3);
	printf("net salary %f",(emp[i].salary+emp[i].bonus-emp[i].reduction));
	printf("\n\n\npress any key to get the next employee num: %d",i+1);
	getch();
 }



}
