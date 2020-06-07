#include<stdio.h>

int arr[3][3]={{55,6,7},{4,8,1},{7,3,2}};


void main()
{
  int i,j;
  int maxArr[3]={arr[0][0],arr[1][0],arr[2][0]};


  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      if(arr[i][j]>maxArr[i])
        maxArr[i]=arr[i][j];
    }
  }
  
   for(i=0;i<3;i++)
  {
    printf("%d ",maxArr[i]);
  }
}