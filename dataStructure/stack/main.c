#include<Stdio.h>
#include"Stack.h"

stack_t s1,s2;

void main()
{
	int val1,val2,val3;
if(stack_init(&s1,10)==0)
{
	printf("error s1");
}
if(stack_init(&s2,5)==0)
{
	printf("error s2");
}
if(!isFull(&s2))
{
push_stack(11,&s2);
push_stack(22,&s2);
push_stack(33,&s2);
push_stack(44,&s2);
}

if(!isFull(&s1))
{push_stack(1,&s1);
push_stack(2,&s1);
push_stack(3,&s1);
}
//freeStack();
if(!isEmpty(&s2))
{
val3=pop_stack(&s2);
}

if(!isEmpty(&s1))
{
val1=pop_stack(&s1);
val2=pop_stack(&s1);
}
else
{
	printf("stack empty\n");
}
printf("%d  %d\n %d",val1,val2,val3);/*3 2*/ /*22*/

}