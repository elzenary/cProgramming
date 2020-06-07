#include<stdio.h>
#include<string.h>

/*define new string*/
char definedStr[100]={"abc"};
char str1[100];
char str2[100];
void main()
{
  printf("enter first name");
  gets(str1);
  printf("enter second name");
  gets(str2);
  
  
  strcat(str1, (const char *)str2);
  
  
  if(strcmp(str1,(const char *)definedStr)==0)
  {
    printf("yes");
  }
  else
  {
    printf("no");
  }
  
  
}