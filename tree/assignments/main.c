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
	Tree t,newcopy;
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
	e=8;
	InsertTree(&t,&e);
	// *****************************for testing treecopy
	/*Tree *pNewcopy=&newcopy;   
	CreateTree(&newcopy);
	TreeCopy(&t,&pNewcopy); 
	InorderRec(&newcopy,visit);*/
	InorderRec(&t,visit);
	
	// to test doupleorder
	/*printf("\n");
	DoupleOrder(&t,visit);*/
	printf("\n");
	//TraveseLevel(&t,visit);
	printf("%d",TreeWidth(&t));
}