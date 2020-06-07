#include<Stdio.h>

int arr[10]={5,1,6,7,8,2,3,11,15,10};
/*function to swap*/

void swap(int* a, int*b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}











void main()
{
	int i;
	int counter=0;
	int sorted=0;
	while(sorted==0)
	{
		counter++;
		sorted=1;
		for(i=9;i>0;i--)
		{
			if(arr[i]<arr[i-1])
			{
			swap(&arr[i],&arr[i-1]);
			sorted=0;
			}
		}
	}
	
	for(i=0;i<10;i++)
		printf("%d ",arr[i]);
}