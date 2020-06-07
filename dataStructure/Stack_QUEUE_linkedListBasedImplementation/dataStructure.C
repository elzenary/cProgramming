/*
  stack and queue modules
  linked list based implementation
    author ahmed Raafat
*/

//include libraries
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//linked list difinitions

//define sturct of node
struct Node
{
 struct Node* next;
 struct Node* prev;
 int data;

};

//define struct of linked list struct
struct linkedList
{
struct Node* start;
struct Node* end;
} ;




//functions prototypes
void createLinkedList(struct linkedList* ll);//create empty linked list
struct Node* createNode(int record);//create new node and fill it with data
void appendElement(struct linkedList* ll,struct Node* node);
void insertElementHead(struct linkedList* ll,struct Node* node);
void printList(struct linkedList* ll);
struct Node* searchList(struct linkedList* ll,int record);//take ll* data return node addess or  null if not found
void freeList(struct linkedList* ll);//take ll* and free the list
int deleteElement(struct linkedList* ll,int record); //deleter certain element which is identified by its record or data
void insertElement(struct linkedList* ll,struct Node* node);
int deleteTail(struct linkedList* ll,int* record);
int deleteTail(struct linkedList* ll,int* record);

//stack structure definition

struct stack
{
linkedList* stk;
int size;
int top;
} ;

//function protoptypes
void createStack(struct stack* s);
int stackIsFull(struct stack* s);
int stackIsEmpty(struct stack* s);
int push(struct stack* s,int data);
int pop(struct stack* s,int* data);
void printStack(struct stack*);




//queue structure definition
struct queue
{
linkedList* q;
int size;
} ;

//function protoptypeq
int createQueue(struct queue* q);
int queueIsFull(struct  queue* q);
int queueIsEmpty(struct  queue* q);
int enQueue(struct  queue* q,int data);
int deQueue(struct  queue* q,int* data);
void printQueue(struct  queue*);

int main()
{

//define variables
struct stack STACK;
struct queue q;
int data;
int i;

createStack(&STACK);
printf("empty %d,  full %d\n",stackIsEmpty(&STACK),stackIsFull(&STACK));

//fill all the stack elements
for(i=0;i<13;i++)
	push(&STACK,i);

printStack(&STACK);


//pop the data from the stack
pop(&STACK,&data);
printf("pop %d\n",data);
pop(&STACK,&data);
printf("pop %d\n",data);

printStack(&STACK);

printf("empty %d,  full %d\n",stackIsEmpty(&STACK),stackIsFull(&STACK));

/********************************************************************************/
printf("endOfStackCode\nLet'sBeginWorkingWithQueues\n");
/********************************************************************************/


//queue test code

createQueue(&q);


printf("empty %d,  full %d\n",queueIsEmpty(&q),queueIsFull(&q));

//fill all the qtack elementq
for(i=1;i<13;i++)
	enQueue(&q,i);


printQueue(&q);

printf("empty %d,  queueIsfull %d\n",queueIsEmpty(&q),queueIsFull(&q));

deQueue(&q,&data);
printf("deQueue %d\n",data);
deQueue(&q,&data);
printf("deQueue %d\n",data);

printQueue(&q);

printf("empty %d,  full %d\n",queueIsEmpty(&q),queueIsFull(&q));


getch();//hold the screen

return 0;
}

//functions definition


//function protoptypes
/*
  initialize size top of the stack
  dynamic allocation of the size
  return 1 if created 0 otherwise

*/
void createStack(struct stack* s)
 {
 //create new linkedlist for the stack
  linkedList* ll=(linkedList*)malloc(sizeof(linkedList));
  createLinkedList(ll);
  s->stk=ll;
 }

 /*
   for comptability generic code only
   return 0 alwyays
 */

int stackIsFull(struct stack* s)
{
 return 0;
}

/*
  is empty

*/
int stackIsEmpty(struct stack* s)
{
 return s->stk->start==NULL;
}


/*
  push on the stack
*/

int push(struct stack* s,int data)
{
  if(stackIsFull(s))
	return 0;

  struct Node* temp;
  temp=createNode(data);//create new node and fill it with data

  if(temp==NULL)
	return 0;

  appendElement(s->stk,temp);
  return 1;
}

/*
  take struct stack* and * data
  if stack empty return 0 other wise return 1
  minus top then put stk[top] int the content of what data refers to
*/
int pop(struct stack* s,int* data)
{
    int x;
    if(stackIsEmpty(s))
        return 0;

	deleteTail(s->stk,&x);
	*data=x;
    return 1;
}

/*
  print the content of current stact from 0 to its top
*/
void printStack(struct stack* s)
{
 printList(s->stk);
 printf("\n");
}

//queue function definition
/*
  initialize size in of the q =0
  dynamic allocation of the size
  return 1 if created 0 otherwise

*/
int createQueue(struct queue* q)
 {
 //create new linkedlist for the stack
  linkedList* ll=(linkedList*)malloc(sizeof(linkedList));
  createLinkedList(ll);
  q->q=ll;
  q->size=0;//initialize size
 if(q->q)
	return 1;
 else
	return 0;
 }


 /*
   for comptability
   return 0 a
 */
int queueIsFull(struct queue* q)
{
 return 0;
}


/*
  is empty
*/
int queueIsEmpty(struct queue* q)
{
  return q->q->start==NULL;
}


/*
  enqueue

*/
int enQueue(struct queue* q,int data)
{
  if(queueIsFull(q))
	return 0;

  struct Node* temp;
  temp=createNode(data);//create new node and fill it with data

  if(temp==NULL)
	return 0;
//insert in the begin then delete will be from tail
  insertElementHead(q->q,temp);
  return 1;
}

/*
  take struct queue* and * data
  if q empty return 0 other wise return 1
*/
int deQueue(struct queue* q,int* data)
{
 if(queueIsEmpty(q))
	return 0;

 *data= deleteTail(q->q,data);

 return 1;

}

/*
  print the content of the queue
*/

void printQueue(struct queue* q)
{
 printList(q->q);
 printf("\n");
}


//linkedlist part

/*
  create linked list function
  initialize start end to equal NULL
*/
void createLinkedList(struct linkedList* ll)
{
 ll->start=NULL;
 ll->end=NULL;
}


/*
  function to make node and fill data
  it return adress
  take the data as a parameter
*/
struct Node* createNode(int record)
{
//pointer definition
struct Node* ptr;

//dynamic allocation
ptr=(struct Node*)malloc(sizeof(struct Node));
/*
make next previous null
fill the data
be sure the ptr isn't null
*/

if(ptr)
{
	ptr->data=record;
	ptr->next=NULL;
	ptr->prev=NULL;
}

return ptr;
}



/*
  create element function take linked list and node adresses
  append node to the end of the linked list
*/
void appendElement(struct linkedList* ll,struct Node* node)
{
//different conditions

//empty list start ==NULL
if(ll->start==NULL)
{

 ll->start=node;//start points to new node
 ll->end=node;//end points to new node

 //be sure node points to null
 node->next=NULL;
 node->prev=NULL;

}
/*
second
many elements of
or
last element in the list
as append to the end so both are one contion
this will be any other condition
*/
else
{

//make last node next points to new node
ll->end->next=node;

//make new node prev point to last node
node->prev=ll->end;

//make end point to new node
ll->end=node;

//make new node next point to null
node->next=NULL;

}

}


 /*
   insert element on the head of the linked list
 */
void insertElementHead(struct linkedList* ll,struct Node* node)
{
  //check different coditions
  //if empty list
  if(ll->start==NULL)
  {
   ll->start=node;
   ll->end=node;
   node->next=NULL;
   node->prev=NULL;
  }
  /*
  case list has one element
  or many elements
  insert in the begining in 2 cases so no difference
  */
  else
  {
	node->prev=NULL;
	node->next=ll->start;
	ll->start->prev=node;
	ll->start=node;
  }


}

/*
 travers list and print it sequentil
 it takes linked list as parameter
 no return is needed
*/
void printList(struct linkedList* ll)
{

//begin temp with start adress of the list
struct Node* temp;
temp=ll->start;


//loop until getting the end of the list (null value)
while(temp)
{
 printf("%d, ",temp->data);
 temp=temp->next;
}


}//end of print list function



/*
search list function
take list , data
return adress of the found element
or
null if not found
*/

struct Node* searchList(struct linkedList* ll,int record)
{
 struct Node* temp; //temp pointer to traverse the list

 struct Node* flag;
 flag=NULL; //assume return null in case of not found element
 temp=ll->start;//temp equal the start of the list

 //keep looping until getting NULL
 while(temp)
 {
 /*
   incase of finding the data
   update the flag with the node adress
   break the loop
 */
 if(temp->data==record)
   {
		flag=temp;
		break;
	}
  temp=temp->next; //increase temp to the next element

 }
 return flag;
}//end search list function


/*
  free list function
  takes pointer to linked  list
  return void
*/

void freeList(struct linkedList* ll)
{
//temp var to hold start of list then traverse it
struct Node* temp,temp2;
temp=ll->start;

//free allocation
while (temp->next)//loop if temp next not null
{
temp=temp->next;
free(temp->prev);//free old not updated temp (temp2)
}
free(temp);//free the last one

//update start end
ll->start=NULL;
ll->end=NULL;

}//free list function end


/*
take list pointer and record data
delete the element if the record is found
return null if record not found
*/

int deleteElement(struct linkedList* ll,int record)
{
struct Node* tempNode;//temp node pointer
//case 0 empty or not found record
//search for the record if not found return null
tempNode= searchList(ll,record);

//if null return return null
if(!tempNode)
	return 0;


//case 1 delete first element when list has only one element
if(tempNode==ll->start&&ll->start==ll->end)
{
 ll->start=NULL;
 ll->end=NULL;
}
//case 2: first element which has many elements
else if( tempNode==ll->start)
{
ll->start=tempNode->next;
ll->start->prev=NULL;
}
//case 3 delete last element
else if(tempNode==ll->end)
{

ll->end=tempNode->prev;
ll->end->next=NULL;

}
//case 4 generic case
else
{
tempNode->prev->next=tempNode->next;
tempNode->next->prev=tempNode->prev;
}
//free founded element
free(tempNode);
 return 1;//assume element is found if not will return null in the begining

}

/*
insert new element
take linked list pointer and node pointer
insert the node in the linked list based on ascending order
*/


void insertElement(struct linkedList* ll,struct Node* node)
{
//define temp pointer to the struct node
struct Node* temp;

//case 0 check if the list is empty append the new node to the list
if(ll->start==NULL)
{
 appendElement(ll,node);
return;
}


//assign temp to the first element
temp=ll->start;
//check the position of insertion
//loop until getting the end of the list
while(temp!=NULL && temp->data < node->data)
{
//check ascending order to insert
temp=temp->next;
}

//check temp location to insert on it

//case first location for one element
if(ll->start==ll->end)
{
  insertElementHead(ll,node);

}
//case first location for many elements
else if(ll->start==temp&&ll->start!=ll->end)
{
	insertElementHead(ll,node);
}
//case end location
else if( temp==NULL)
{
	appendElement(ll,node);
}
//case in between generic case
else
{
node->prev=temp->prev;
node->next=temp;

temp->prev->next=node;
temp->prev=node;


}

}//insert function end

int deleteTail(struct linkedList* ll,int* data)
{
int ret;
Node* temp;
if(ll->start==NULL)
  return 0;

temp=ll->end;
temp->prev->next=NULL;
ll->end=temp->prev;
*data=temp->data;
free(temp);
return 1;

}
