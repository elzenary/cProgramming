
/*

  le.c

	author ahmedRaafat
	last edit 13/10/2017

line editor example
ask user to enter data withing line editor field
you can move the arrow right and left to replace existed character 
or jump to the begin or end  position

*/

//library including
#include<stdio.h>
#include<conio.h>

//definitions
#define HIGLIHTED_MODE 0x70
#define NORMAL_MODE   0x07
#define FIRST_LOCATION 0
#define LAST_LOCATION 39
#define COL_OFFSET 5
#define ROW_OFFSEt 5

//ascii definitions
#define ENTER 13 //enter=carriage return
#define ESC 27
#define TAB 9

//exteded ascii charater keys definition
#define RIGHT_ARROW 77//use right arrow instead as keyboard doesn't have PGUP
#define LEFT_ARROW 75 //use left arrow instead as keyboaed doesn't have PGDOWN
#define UP_ARROW 72
#define DOWN_ARROW 80

//functions decleration
void drawEmptyText(void);//draw empty text at the begining or in case pressing ESC
char getCH1(void);//get char either normal or extended key
void drawText(char* arr,int size);//draw the text after pressing enter

//main function entry point
void main(void)
{
	

	//variables decleration
	char ch;//character holds the input change action characters
	char arr[LAST_LOCATION-FIRST_LOCATION];//array holds the input text
	int currentLocation=0,endLocation=0;//variable declares current and end positions
	char* startPtr,currentPtr,endPtr;//pointers to different parts of the text field
	//pointers access different parts of the array
	/*startPtr=arr;
	currentPTr=arr;
	endPtr=arr;*/

	//program main loop where all the logic goes
	//this code will  be excecuted at least once

	/*
		algorithm main steps
		1 draw the menu of highlighted line editor
		2 get the pressed key from the user
		3  take the suitable action depending on the presees key
	*/


	 /*********************************************************************/
	//1 draw empty highlighted line editor interface
		drawEmptyText();
	
	//program runs in this loop
	do
	{

	ch=getCH1();//get the user input character

	/**********************************************************************/
	//3 take the suitable action depending on the presees key

	/*
	inputCH has the user input character so switch it
	take actions based on its value
	*/
	
	//check the input character if it is printiable or not
	if(printchar(Ch))
	{
		//update the array if the input is printable character
		arr[currentLocation]=ch;
		//print the character in its right position
		gotoxy(COL_OFFSET+currentLocation);
		textattr(NORMAL_MODE);
		cprintf("%c",ch);
	}
	else
	{
	//if the input char isnot printable take different actions based on its value
	switch(inputCH)
	{

	//jump to first or end locations if the pressed char is arrow up or down
	 case UP_ARROW:
		currentLocation=FIRST_LOCATION;
		break;
	 case DOWN_ARROW:
		currentLocation=endLocation;	
		break;

		//update current location and end location if arrow right and left are used
	 case RIGHT_ARROW:
		currentLocation=(currentLocation>LAST_LOCATION)?
		LAST_LOCATION:currentLocation++;//circular last location boundary
		endLocation=currentLocation;
		break;
	 case LEFT_ARROW:
		currentLocation=(currentLocation<FIRST_LOCATION)?
		FIRST_LOCATION:currentLocation--;//circular first location boundary
		endLocation=currentLocation;
		break;

	 case ESC:
		terminateFlag=1;//ESC update terminate flag to exit program
		drawEmptyText();
		getch();
		break;

	 case ENTER:
		/*
		 if ENTER is pressed
		 put null character and print the array
		*/
		
		arr[++currentLocation]='\n';
		clrscr();
		drawText();
		terminateFlag=1;
	 break;//break of inputCH ENTER case
	} //end of inputCH switch


	/*********************************************************************/

	}//else end

	}while(!terminateFlag);//repeat the program if terminate status is false

//getch();//hold the screen
}//end of main

//functions definitions

void drawEmptyText(void)
{
	//clear screen before printing any thing with normal attributes
	textattr( NORMAL_MODE );//normal mode is the default
	clrscr();
	gotoxy(COL_OFFSET,RAW_OFFSET);
	for(i=0;i<39;i++)
	{	
	textattr( HIGLIHTED_MODE );
	//print the menu item based on the selected attribute
	cprintf("%s", " " );
	}

	}//end of for loop which traverse number of menu items
	//the end of drawing hilighted, (1st step in the algorithm)
	/********************************************************************/
}

void drawText(char* arr,int size)
{
int i;

gotoxy("COL_OFFSET,ROW_OFFSET
while(arr[i]!='\0');
{
printf("%c",arr[i++]);
}


}
char getCH1(void)
{
   /*********************************************************************/
	//2 get the pressed key from the user
	//2nd algorithm step

	/*
	this step purpose is to differentiate between normal and extended keys
	normal key we read the first character in the keyboard buffer using getch
	extended key the first character is null and the second has a value
	so we use getch 2 times
	*/

	//flush the keyboard buffer before getting any data
	flushall();

	//get the first character in  the keyboard buffer
	inputCH=getch();

	//check if it is an extended key
	if(inputCH==0)
	{
	//extended key handling
	inputCH=getch();//read again from the keyboard buffer
	}
	return inputCH;

	//now we have a variale inputCH contains the keyboard input
	//end of get pressed key from use (second algorithm step)
	/*********************************************************************/

}