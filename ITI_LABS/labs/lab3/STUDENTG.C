
/*
  STUDENTG.c
	author ahmedRaafat
	last edit 13/10/2017

  in this world exists 3 students every one takes 4 subject
  get the total score for every student
  the averge of each subject
*/


//pre processor block

//include required libraries
#include<stdio.h>
#include<conio.h>

//definintions
#define students 3
#define subjects 4

//configuration block
/*coniguration option to choose either
 performance to solve the problem in the minimum num of looping
 or
 modularity to divide the problem into different blocks
 comment one of them
 */
//#define PerformenceAproach
#define modularityApproach


//main function entry point
void main(void)
{
	//variables and arrays declerations/definitions
	int i,j;//counters for loops
	int studentTotal[students]={0};//counter for total score of each students in each subject
	int subjectTotal[subjects]={0};//counter for total score in each subject for all students
	float subjectAvg[subjects]={0.0};//array to hold the average score in each subject from all students
	int studentGrades[students][subjects];//array of students holds another array of their score in different subjects



	 //performance consideration approach

	 #ifdef PerformenceAproach

	 /*
	steps
	ask user to enter inputs
	count the total student score
	count the total subject score to get the average later
	print the total student score
	*/

	for(i=0;i<students;i++)
	{
		for(j=0;j<subjects;j++)
		{
		printf("pleas enter the data of student %d subject %d :  ",i+1,j+1);
		scanf("%d",&studentGrades[i][j]);
		studentTotal[i]+=studentGrades[i][j];
		subjectTotal[j]+=studentGrades[i][j];
		}
		printf("total score of student no%d:   %d\n",i+1,studentTotal[i]);
	}

	 //getting each subject average and printing them
	 for(i=0;i<subjects;i++)
	 {
	  subjectAvg[i]=subjectTotal[i]/3;
	  printf("the avg of subject %d:  %f subject total :  %d\n",i+1,subjectAvg[i],subjectTotal[i]);
	 }

	#endif//end performance approach option





	//modularity approach
	#ifdef modularityApproach


	//input block

	//getting user input
	for(i=0;i<students;i++)
	{
		for(j=0;j<subjects;j++)
		{
		printf("pleas enter the data of student %d subject %d :  ",i+1,j+1);
		 scanf("%d",&studentGrades[i][j]);
		}
	}



	 //processing block

	// getting student/subjects totals
	for(i=0;i<students;i++)
	{
		for(j=0;j<subjects;j++)
		{
	 studentTotal[i]+=studentGrades[i][j];
	 subjectTotal[j]+=studentGrades[i][j];
		}
	}

	//getting each subject average
	 for(i=0;i<subjects;i++)
	 {
	  subjectAvg[i]=subjectTotal[i]/3;
	 }


		//output block

		//printing output of subject average
		for(j=0;j<subjects;j++)
		{
	   printf("the avg of subject %d:  %f subject total :  %d\n",j+1,subjectAvg[j],subjectTotal[j]);
		}

		//printing the output of student total score
	   for(j=0;j<students;j++)
		{
			printf("\ntotal score of student no%d:   %d\n",j+1,studentTotal[j]);
		}

		#endif//end of modularity approach


	getch();//hold the screen

}//end of main