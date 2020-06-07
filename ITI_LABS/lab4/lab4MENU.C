
/*

  MENU.c
	author ahmedRaafat
	last edit 13/10/2017


  build menu that has these options
		new
		display
		exit
  the user can make arrow up/down/right/left tab home/end operations
   Esc to end the program


   different messeges will appear when one item of the menu is Entered
   current selected item in the menu is highlihted

*/

//library including
#include<stdio.h>
#include<conio.h>

//definitions
#define HIGLIHTED_MODE 0x70
#define NORMAL_MODE   0x07
#define FIRST_LOCATION 0
#define LAST_LOCATION 2
#define NEW_ITEM_LOCATION FIRST_LOCATION
#define DISPLAY_ITEM_LOCATION FIRST_LOCATION+1
#define EXIT_ITEM_LOCATION LAST_LOCATION
#define NUMBER_OF_ITEMS (LAST_LOCATION - FIRST_LOCATION)+1
#define MAXIMUM_ITEM_LENGTH  8
#define MENU_COLUMN_START_POSITION 35
#define MENU_ROW_START_POSITION 10
#define MESSESGE_COLUMN_START_POSITION 15
#define MESSEGE_ROW_START_POSITION 10

//ascii definitions
#define ENTER 13 //enter=carriage return
#define ESC 27
#define TAB 9

//exteded ascii charater keys definition
#define RIGHT_ARROW 77//use right arrow instead as keyboard doesn't have PGUP
#define LEFT_ARROW 75 //use left arrow instead as keyboaed doesn't have PGDOWN
#define UP_ARROW 72
#define DOWN_ARROW 80
#define HOME 71
#define END  79


//main function entry point
void main(void)
{
	//variable decleration/definition
	//current menu locations  0 for new, 1 for display,  2 for exit
	const char menuOptions[NUMBER_OF_ITEMS][MAXIMUM_ITEM_LENGTH]=
	{
	"  new  ",
	"display",
	" exit  "
	};//menu options strings

	char inputCH;//store user input character
	int currentLocation=FIRST_LOCATION;//set current location to firstLocation
	int terminateFlag=0;//if want to terminate the program change flag to 1
	int i=0;//counter to be used in for loops


	//program main loop where all the logic goes
	//this code will  be excecuted at least once
	do
	{

	/*
		algorithm main steps
		1 draw the menu of highlighted items interface
		2 get the pressed key from the user
		3  take the suitable action depending on the presees key
	*/


	 /*********************************************************************/
	//1 draw the menu of highlighted items interface
	//clear screen before printing any thing with normal attributes
	textattr( NORMAL_MODE );//normal mode is the default
	clrscr();
	/*
	for loop with number of iterations equal the number of menu items
	every item will be printed either in higlighted or normal modes
	depeding on the current selected location
	which is the only highlighted item
	*/

	for(i=FIRST_LOCATION;i<LAST_LOCATION+1;i++)
	{

		//return the attribute to the normal mode
		textattr( NORMAL_MODE );//normal mode is the default

		//go to the right x y position using gotoxy fn and col,row variables
		gotoxy(MENU_COLUMN_START_POSITION,MENU_ROW_START_POSITION+2*i);

		//check if the current location is the selected item
		if(i==currentLocation)
		{
		 //change the attribute to the hilighted mode
		 textattr( HIGLIHTED_MODE );
		}

		//print the menu item based on the selected attribute
		cprintf("%s", menuOptions[i] );


	}//end of for loop which traverse number of menu items
	//the end of drawing menu, (1st step in the algorithm)
	/********************************************************************/




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

	//now we have a variale inputCH contains the keyboard input
	//end of get pressed key from use (second algorithm step)
	/*********************************************************************/




	/**********************************************************************/
	//3 take the suitable action depending on the presees key

	/*
	inputCH has the user input character so switch it
	take actions based on its value
	*/

	switch(inputCH)
	{

	/*
	update current location:
		home go to first location
		end go to last location
		Arrow up decrease current location and remain if circular
		arrow down increase current location and remain if circular
		arrowright increase and circular
		arrowleft / tab decrease and circular
	*/
	 case HOME:
		currentLocation=FIRST_LOCATION;
		break;
	 case END:
		currentLocation=LAST_LOCATION;
		break;
	 case LEFT_ARROW:
	 case TAB:
		currentLocation+=1;//increase current location by 1
		currentLocation=(currentLocation>LAST_LOCATION)?
		FIRST_LOCATION:currentLocation;//circular last location boundary
		break;
	 case RIGHT_ARROW:
		currentLocation-=1;//decrease current location by 1
		currentLocation=(currentLocation<FIRST_LOCATION)?
		LAST_LOCATION:currentLocation;//circular first location boundary
		break;
	 case DOWN_ARROW:
		currentLocation+=1;//increase current location by 1
		currentLocation=(currentLocation>LAST_LOCATION)?
		LAST_LOCATION:currentLocation;//circular last location boundary
		break;
	 case UP_ARROW:
		currentLocation-=1;//decrease current location by 1
		currentLocation=(currentLocation<FIRST_LOCATION)?
		FIRST_LOCATION:currentLocation;//circular first location boundary
		break;

	 case ESC:
		terminateFlag=1;//ESC update terminate flag to exit program
		break;

	 case ENTER:
		/*
		 if ENTER is pressed
		 the program takes different actions based of the currentLocation val
		 we use switch case to check the curren location
		*/
		switch(currentLocation)
		{
			/*
			 NEW_ITEM_LOCATION
			 DISPLAY_ITEM_LOCATION
					 clear the screen
					 prints different messeges to the user

			  EXIT_ITEM_LOCATION
					update terminate flag equals 1 to exit the program
			*/

			case NEW_ITEM_LOCATION :
				textattr( NORMAL_MODE );//normal mode is the default
				clrscr();//clear screen
				//go to the certain x y posotion
				gotoxy(MESSESGE_COLUMN_START_POSITION,MESSEGE_ROW_START_POSITION);
				cprintf("NEW screen");//screen messege
				printf(" ,press any key to cont.");
				getch();//the program will wait unil pressing character
				break;

			case DISPLAY_ITEM_LOCATION:
				textattr( NORMAL_MODE );//normal mode is the default
				clrscr();//clear screen
				//go to the certain x y posotion
				gotoxy(MESSESGE_COLUMN_START_POSITION,MESSEGE_ROW_START_POSITION);
				cprintf("DISPLAY screen");//screen messege
				printf("  ,press any key to cont.");
				getch();//the program will wait unil pressing character
				break;

			case EXIT_ITEM_LOCATION:
				terminateFlag=1;//update terminate to exit program
				break;

		}

	 break;//break of inputCH ENTER case
	} //end of inputCH switch


	/*********************************************************************/



	}while(!terminateFlag);//repeat the program if terminate status is false

}//end of main