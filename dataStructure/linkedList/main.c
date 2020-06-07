#include<stdio.h>
#include"linkedList.h"

linkedList_t l1;
node_t* n1;

void main()
{
	linkedListInit(&l1);
	append_linkedList(&l1,5);
	append_linkedList(&l1,7);
	append_linkedList(&l1,8);
	printLinkedList(&l1);
	//printf("%d  %d  ", l1.start->data,l1.end->data);
}