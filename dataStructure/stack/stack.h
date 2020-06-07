typedef struct stack 
{
int* data;
int tos;
int size;
}stack_t;

int stack_init(stack_t* s,int size);
void push_stack(int,stack_t*);
int pop_stack(stack_t* s);
int isFull(stack_t* s);
int isEmpty(stack_t* s);
void freeStack(stack_t* s);
