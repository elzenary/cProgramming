#include<stdio.h>

int arr[10]={5,1,6,7,8,2,3,11,15,10};
/*function to swap*/

void swap(int* a, int*b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int minIndx;
void main()
{
	int i,j;
	for(i=0;i<9;i++)
	{
		minIndx=i;
		for(j=i+1;j<10;j++)
		{
			if(arr[j]< arr[minIndx])
				minIndx=j;
		}
		swap(&arr[minIndx],&arr[i]);
	}
	
	/*print the sorted array*/
	for(i=0;i<10;i++)
		printf("%d ",arr[i]);
}