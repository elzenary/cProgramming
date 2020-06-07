#include<stdio.h>
#include<string.h>

/*define new string*/
char str1[100]={'a','b','c','\0'};
char str2[100]= {"hello"};

void strCpy2(char* dest, char* src)
{
  int i=0;
  while(src[i]!='\0')
  {
    dest[i]=src[i];
    i++;
  }
  dest[i]='\0';
}
int str_len2(char* str)
{
  int counter=0;
  while(str[counter]!='\0')
  {
    counter++;
  }
 
return counter; 
}

/*
 	char *strcat(char *dest, const char *src)
Appends the string pointed to,
 by src to the end of the string pointed to by dest.
*/

/*
 	int strcmp(const char *str1, const char *str2)
0 equal
not zero not equal
Compares the string pointed to,
 by str1 to the string pointed to by str2.
*/

/*
define string with our full name
char str[]="ahmedRaafat"
ask the user to input first name
ask the user to input second name
concatenate the names
compare user input with predefined value
print equal or not


*/

void main()
{
  /*
   	size_t strlen(const char *str)
  */
  
  /*
  char *strcpy(char *dest, const char *src)

Copies the string pointed to, by src to dest.
  */
  
  //strcpy(str2, (const char *)str1);
  strCpy2(str2,str1);
  printf("%s",str1);
  printf("\n%s",str2);
  
  //printf("\n%d",str_len2( (char *) str2));
}