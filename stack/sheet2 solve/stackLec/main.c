#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
void Display(StackEntry item);
 int main()
 {
	Stack s;
	StackEntry e;
	initStack(&s);
	printf("enter element: ");  fflush(stdout);
	scanf("%c",&e);
	if(!StackFull(&s))
	{
		push(e,&s);	
	}
	push(e+1,&s);
	push(e+1,&s);
	pop(&e,&s);
	printf("stack size is: %d",StackSize(&s));
	printf("\ntop element is : %c",e);
	return 0;
 }
 void Display(StackEntry item)
 {
	printf("%c",item);
 }
 /*u8 StackSize(Stack *ps)
{
	StackEntry e;
	u8 counter=0;
	u8 size;
	while(!StackFull(ps))
	{
		push('1',ps);
		counter++;
	}
	size=Maxsize-counter;
	while(counter)
	{
		pop(&e,ps);
		counter--;
	}
	return size;
}*/