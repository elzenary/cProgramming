
/*struct student*/
/*
id
name
grade
*/
#include<stdio.h>
#include<string.h>
struct student
{
  int id;
  char name[20];
  float grade;
};

struct student arr[3];

void main()
{
  int i;
  for(i=0;i<3;i++)
  {
    printf("enter id of student %d",i+1);
    scanf("%d",&arr[i].id);
    printf("enter name of student %d",i+1);
    //scanf("%s",arr[i].name);
    (void)gets(arr[i].name);
    printf("enter grade of student %d",i+1);
    scanf("%f",&arr[i].grade);
  }
  for(i=0;i<3;i++)
  { 
    printf("\nID:%d   name:%s   grade:%f\n",arr[i].id,arr[i].name,arr[i].grade);
  }
  
  
  
  
//strcpy(ahmed.name,(const char*)"mohammed");

//printf("%s",ahmed.name);


  }