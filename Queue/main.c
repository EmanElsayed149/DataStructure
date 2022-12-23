#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
void dip(QueueEntry e){
	printf("%c",e);
}
int main()
{
	Queue q;
	CreateQueue(&q);
	Append('A',&q);
	Append('B',&q);
	Traverse(&q,dip);
	QueueEntry e;
	Serve(&e,&q);
	//Traverse(&q,dip);
	//printf("\n%d %d %d",q.front,q.rear,q.size);
	Append('A',&q);
	Traverse(&q,dip);
	//printf("\n%c",e);
	printf("\n%c %c %d",q.front->entry,q.rear->entry,QueueFull(&q));
}