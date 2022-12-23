#ifndef STACK_H
#define STACK_H
/*******user definition***********/
typedef char    u8;
typedef char     StackEntry ;     //type of elements stored in satck
#define Maxsize 30              //size of satck 
#define ARRAY_BASED_STACK
#ifdef ARRAY_BASED_STACK

/**stack component **/
typedef struct stack{
	StackEntry Entry[Maxsize];
	u8 top;
}Stack;
#else
typedef struct stacknode
{
	StackEntry Entry;
	struct stacknode *next;
}StackNode;
typedef struct stack{
	StackNode *top;
	u8 size;
}Stack;
#endif


/******************functions declaration*****************/
/**to initialize stack*******/
void initStack(Stack *ps);

/**to push new element in the stack***/
void push(StackEntry e,Stack *ps);

/***to return the last element in the stack*****/ 
void pop (StackEntry *e,Stack *ps);

/***check if stack is empty return true*******/
u8   StackEmpty(Stack *ps);

/***check if stack is Full return true***/
u8   StackFull(Stack *ps);

/**to clear stack ***/
void ClearStack(Stack *ps);

/****to return last element in stack***/
void StackTop(StackEntry *pe,Stack *ps);

/**to return how many elementin the stack***/
u8   StackSize(Stack *ps);

/***to display all element in stack****/
/*used callback definition because implementer doesn't know what is the 
*type of data stored in stack 
*in printf function he can't determine what is format specifier
*so implement of display done by user 
*then pass adress of this func to implementer*/

void DisplayStack(Stack *ps,void (*pf)(StackEntry item));

//pe ps  -> void
/***to return last element in the stack***/
//pre : stack mustn't be empty
//post: return last element in the stack
void StackEnd(StackEntry *pe,Stack *ps);

//ps ps -> void
// make first is copy of second stack 
//pre : two satcks are initialize 
void StackCopy(Stack *ps1,Stack *ps);

#endif