#include"Stack.h"
#include<stdlib.h>

int stack_init(stack_t* s,int size)
{
	s->tos=0;
	s->data=(int*)malloc(size*sizeof(int));
	if(!s->data)
			return 0;
	s->size=size;
	return 1;
}

void push_stack(int data,stack_t* s)
{
		s->data[s->tos]=data;
		s->tos++;
}

int pop_stack(stack_t* s)
{
	int data= s->data[(--s->tos)];
	return data;
}

int isFull(stack_t* s)
{
	return (s->tos==s->size);
}
int isEmpty(stack_t* s)
{
	return ((*s).tos==0);
}
void freeStack(stack_t* s)
{
	s->tos=0;
}