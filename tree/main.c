#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "tree.h"
void visit(TreeEntry e)
{
	printf("%d ",e);
}

int main()
{
	Tree t;
	TreeEntry e;
	e=9;
	CreateTree(&t);
	InsertTree(&t,&e);
	e=7;
	InsertTree(&t,&e);
	e=10;
	InsertTree(&t,&e);
	e=11;
	InsertTree(&t,&e);
	e=6;
	InsertTree(&t,&e);
	DeletItemTree(&t,&e,11);
	
	InorderRec(&t,visit);
	
}