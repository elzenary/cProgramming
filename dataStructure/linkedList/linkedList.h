struct node
{
int data;
struct node* prev;
struct node* next;
};
typedef struct node node_t;

typedef struct linkedList
{
	node_t* start;
	node_t* end;
}linkedList_t;

node_t* linkedList_createNode(int data);
void linkedListInit(linkedList_t*);
void append_linkedList(linkedList_t* linked,int data);
void printLinkedList(linkedList_t* linked);