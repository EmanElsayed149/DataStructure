#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
void Display(StackEntry item);
 int main()
 {
	Stack s;
	Stack s2;
	StackEntry e;
	initStack(&s);
	printf("enter element: ");  fflush(stdout);
	scanf("%c",&e);
	if(!StackFull(&s))
	{
		push(e,&s);	
	}
	push(e+1,&s);
	StackCopy(&s2,&s);
	DisplayStack(&s2,Display);
	StackEnd(&e,&s2);
	printf("top element in this stack is: %c",e);
	return 0;
 }
 void Display(StackEntry item)
 {
	printf("%c\n",item);
 }