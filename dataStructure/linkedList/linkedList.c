#include"linkedList.h"
#include<stdlib.h>
#include<stdio.h>

node_t* linkedList_createNode(int data)
{
	node_t* temp;
	temp= (node_t*)malloc(sizeof(node_t));
	if(temp)
	{
		temp->data=data;
		temp->prev=NULL;
		temp->next=NULL;
	}
	return temp;
}

void linkedListInit(linkedList_t* linked)
{
	linked->start=NULL;
	linked->end=NULL;
}

void append_linkedList(linkedList_t* linked,int data)
{
	/*create node*/
	node_t* node=linkedList_createNode(data);
	/*check if linked list is empty*/
	if(linked->start==NULL)
	{
		linked->start=node;
		linked->end=node;
	}
	{
		node_t* temp=linked->end;
		node->prev=temp;
		temp->next=node;
		linked->end=node;
	}
}

void printLinkedList(linkedList_t* linked)
{
	node_t* temp=linked->start;
	while(temp)
	{
		printf("%d ",temp->data);
		if(temp->next!=NULL)
		{
			temp=temp->next;
		}
		else
		{
			break;
		}
			
	}
}