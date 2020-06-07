#include<Stdio.h>

int arr[10]={1,2,3,4,5,6,7,8,9,10};
int low=0;
int high=9;
int mid;
int num;
int found=0;
void main()
{
	/*user input value to search*/
	scanf("%d",&num);
	
	while((low<=high)&&(found==0))
	{
		mid=(high+low)/2;
		/*check value > or < or ==*/
		if(arr[mid]>num)
		{
			high=mid-1;
		}
		else if(arr[mid]<num)
		{
			low=mid+1;
		}
		else if(arr[mid]==num)
		{
			found=1;
		}
	}
	/*print num*/
	if(found==0)
	{printf("not found");}
	else if(found==1)
	{printf("found");}

}