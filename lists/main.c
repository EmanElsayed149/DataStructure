#include <stdio.h>
#include <stdlib.h>
#include "list.h"
void dis(ListEntry e)
{
	printf("%c",e);
}
int main()
{
	List l;
	ListEntry e;
	int x;
	CreateList(&l);
    InsertList(0,'A',&l);
	InsertList(1,'p',&l);
	InsertList(2,'l',&l);
	InsertList(1,'p',&l);
	InsertList(4,'e',&l);
	//DeleteList(3,&e,&l);
	ReplaceList(3,'S',&l);
	RetrieveList(3,&e,&l);
	TraverseList(&l,dis);
	//DestroyList(&l);
	printf("\nlist size = %d\nList empty? %d \nList full? %d\nLast ele %c",ListSize(&l),ListEmpty(&l),ListFull(&l),e);
	
}