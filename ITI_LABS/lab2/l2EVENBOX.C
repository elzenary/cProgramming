
/*
Even magic square
	author ahmedRaafat
	lastedit 15/10/2014

	applying double even algorithm
	for n numbers which are divided by 4 only


*/

#include<stdio.h>
#include<conio.h>

#define SQUARE_ORDER 4

void main (void)
{
	//variables decleration
	int i,j;
	int counter=0;
	int N=SQUARE_ORDER;
	int square[SQUARE_ORDER][SQUARE_ORDER]={0};
	int usedNums[SQUARE_ORDER*SQUARE_ORDER];

	clrscr();
	//initialize usedNums arrays with numbers from 1 to N*N
	for(i=0;i<SQUARE_ORDER*SQUARE_ORDER;i++)
		usedNums[i]=i+1;

	//loop on the N*N square
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			/*if the elements are within corner or middle square
			fill them with an increaseing order
			update used numbers array to equal zero
			*/

			if
			(

			/*
			  this conditions are based on the position range of conrner
			  and middles squares in x y positions
			  consider that i represents y cordinate first array dimension
			  and j represents x cordinate second array dimension
			*/

			( (i>=0) && (i<N/4) && (j>=0) && (j<N/4) )//1st corner range
			||
			( (i>=3*N/4) && (i<N) && (j>=0) && (j<N/4)  )//2nd corner range
			||
			( (i>=3*N/4) && (i<N) && (j>=3*N/4) && (j<N) )//3rd corner range
			||
			( (i>=0) && (i<N/4) && (j>=3*N/4) && (j<N) )//4th corner range
			||
			( (i>=N/4) && (i<3*N/4) && (j>=N/4) && (j<3*N/4)  )//middle square
			)
				{
					//put the values in the square
					square[i][j]=counter+1;

					/*
					mark the used numbers to equal zero to avoid using
					them again in the next algorithm step
					*/
					usedNums[counter]=0;


				}
			counter++;//increase the counter once every iteration

		}//second j for loop end
	}//first i for loop end


	  /*
	  fill the rest of the zeroed array value
	  make the filling in decreasing order
	  based on the available usedNums array

	  */


		//loop on the N*N square to fill the rest
		counter= 63;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
		//logic goes here
		while(square[i][j]==0)
		{

			if(usedNums[counter]==0)
			{
				counter--;
			}
			else {
				square[i][j]=usedNums[counter--];
				 break;
				}

		}///end while
		}//end second j array

	}//end first i array



	//print the N*N square
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
		printf("%d\t",square[i][j]);
		}//end second j array
		printf("\n");

	}//end first i array


	getch();
}