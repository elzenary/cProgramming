#include<stdio.h>
#include<string.h>

struct student
{
  int id;
  char name[20];
  float grade;
};
struct subject
{
  int noSubj;
};
struct school
{
  struct student st[10];
  struct subject* sb;
  struct school* sc;
};
struct school s1,s2;
struct subject x={5};
void main()
{
  s1.st[3].id=5;
  s1.sb=&x;
  s1.sc=&s2;
  (*s1.sc).st[0].id=10;
  
  printf("%d",(*s1.sb).noSubj);
  
  
}