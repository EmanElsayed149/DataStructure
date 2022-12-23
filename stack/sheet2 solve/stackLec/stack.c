/*****files inclusion******/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define ARRAY_BASED_STACK
#ifdef ARRAY_BASED_STACK

/*********************functions implementations*********/

/**to initialize stack*******/
//should initialize stack before first push to avoid garbage value in top
void initStack(Stack *ps)
{
	ps->top=0;
}



/**to push new element in the stack***/
/*preconditionds
*in first push init stack
*check if stack is not Full
*/
void push(StackEntry e,Stack *ps)
{
	ps->Entry[ps->top++]=e;
}


/***to return the last element in the stack*****/ 
/*preconditionds
*check if stack is not Empty
*/
void pop (StackEntry *pe,Stack *ps)
{
	*pe=ps->Entry[--ps->top];
}


/***check if stack is empty return true*******/
u8   StackEmpty(Stack *ps)
{
	return(ps->top==0);
}


/***check if stack is Full return true***/
u8   StackFull(Stack *ps)
{
	return(ps->top==Maxsize);
}

/**to clear stack ***/
void ClearStack(Stack *ps)
{
	ps->top=0;
}

/****to return last element in stack***/
void StackTop(Stack *ps,StackEntry *pe)
{
	*pe=ps->Entry[ps->top-1];
}

/**to return how many elementin the stack***/
u8   StackSize(Stack *ps)
{
	return ps->top;
}

/***to display all element in stack****/
/*used callback definition because implementer doesn't know what is the 
*type of data stored in stack 
*in printf function he can't determine what is format specifier
*so implement of display done by user 
*then pass adress of this func to implementer*/

void DisplayStack(Stack *ps,void (*pf)(StackEntry item))
{
	for(int i=0;i<=ps->top-1;i++)
	{
		(*pf)(ps->Entry[i]);
	}
}
#else
	

/**to initialize stack*******/
//should initialize stack before first push to avoid garbage value for top pointer
void initStack(Stack *ps)
{
	ps->top=NULL;
	ps->size=0;
}


/**to push new element in the stack***/
/*preconditionds
*in first push init stack
*/
void push(StackEntry e,Stack *ps)
{
	StackNode *pn=(StackNode *)malloc(sizeof(StackNode));
	pn->Entry=e;
	pn->next=ps->top;
	ps->top=pn;
	ps->size++;
}

/***to return the last element in the stack*****/ 
/*preconditionds
*check if stack is not Empty
*/
void pop (StackEntry *pe,Stack *ps)
{
	*pe=ps->top->Entry;
	StackNode *p=ps->top;
	ps->top=p->next;
	free(p);
	ps->size--;
}

/***check if stack is Full return true***/
//in linked stack there  is no limited size but we impement it for user 
/*because user don't no any information
*and if user write code for array based stack so no need to modify the code*/
u8   StackFull(Stack *ps)
{
	return 0;
}

u8   StackEmpty(Stack *ps)
{
	return !(ps->top);
}
/**to clear stack and free all stored nodes***/
void ClearStack(Stack *ps)
{
	StackNode *p=ps->top;
	while(p){
		ps->top=p->next;
		free(p);
		p=ps->top;
	}
	ps->size=0;
}

/****to return last element in stack***/
void StackTop(Stack *ps,StackEntry *pe)
{
	*pe=ps->top->Entry;
}

/**to return how many elementin the stack***/
u8   StackSize(Stack *ps)
{
	return ps->size;
}

/***to display all element in stack****/
/*used callback definition because implementer doesn't know what is the 
*type of data stored in stack 
*in printf function he can't determine what is format specifier
*so implement of display done by user 
*then pass adress of this func to implementer*/

void DisplayStack(Stack *ps,void (*pf)(StackEntry item))
{
	StackNode *p=ps->top;
	while(p)
	{
		(*pf)(p->Entry);
		p=p->next;
	}
}
#endif