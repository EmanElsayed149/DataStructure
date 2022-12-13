#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
	Stack s;
	initStack(&s);
	StackEntry e;
	push('w',&s);
	push('e',&s);
	push('l',&s);
	push('l',&s);
	push('c',&s);
	pop(&e,&s);
	StackMin(&e,&s);
	printf("%c",e);    fflush(stdout);
}