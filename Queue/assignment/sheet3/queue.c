//inclusions
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
/********impementation of Queue functions****/

#ifdef LinkedBased 
void CreateQueue (Queue *pq)
{
	pq->rear=NULL;
	pq->front=NULL;
	pq->size=0;
}
void Append (QueueEntry e,Queue *pq)
{
	QueueNode *node=(QueueNode*)malloc(sizeof(QueueNode));
	node->next=NULL;
	node->entry.id =e.id;
	node->entry.modelyear=e.modelyear;
	strcpy(node->entry.name,e.name);
	if(!pq->front) pq->front=node;
	else pq->rear->next=node;
	pq->rear=node;
	pq->size++;
}
void Serve (QueueEntry *pe , Queue *pq)
{
	pe->id=pq->front->entry.id;
	pe->modelyear=pq->front->entry.modelyear;
	strcpy(pe->name,pq->front->entry.name);
	QueueNode *first=pq->front->next;
	free(pq->front);
	pq->front = first ;
	if(!pq->front){pq->rear=NULL;}
	pq->size--;
}
void QueueFront(QueueEntry *pe , Queue *pq) 
{
	pe->id=pq->front->entry.id;
	pe->modelyear=pq->front->entry.modelyear;
	strcpy(pe->name,pq->front->entry.name); 
}
u8 QueueEmpty(Queue *pq){
	return (!pq->front);
}
u8 QueueFull(Queue *pq){
	return(0);
}
u8 QueueSize (Queue *pq)
{
	return (pq->size);
}
void ClearQueue(Queue *pq){
	while(pq->front){
		pq->rear=pq->front->next;
		free(pq->front);
		pq->front=pq->rear;
	}
	pq->size=0;
}
void Traverse(Queue *pq,void (*pf)(QueueEntry))
{
	for(QueueNode *pn=pq->front;pn;pn=pn->next)
	{
		(*pf)(pn->entry);
	}
	
}
#else
void CreateQueue (Queue *pq)
{
	pq->rear=-1;
	pq->front=0;
	pq->size=0;
}
void Append (QueueEntry e,Queue *pq)
{
	u8 pos=(++pq->rear)%MaxQueueSize;
	pq->entry[pos].id=e.id;
	pq->entry[pos].modelyear=e.modelyear;
	strcpy(pq->entry[pos].name,e.name);
	pq->size++;
}
void Serve (QueueEntry *pe , Queue *pq)
{
	pe->id=pq->entry[pq->front].id;
	pe->modelyear=pq->entry[pq->front].modelyear;
	strcpy(pe->name,pq->entry[pq->front].name);
	pq->front =(pq->front +1)%MaxQueueSize;
	pq->size --;
}
void QueueFront(QueueEntry *pe , Queue *pq)
{
	pe->id=pq->entry[pq->front].id;
	pe->modelyear=pq->entry[pq->front].modelyear;
	strcpy(pe->name,pq->entry[pq->front].name);
}
u8 QueueEmpty(Queue *pq){
	return (!pq->size);
}
u8 QueueFull(Queue *pq){
	return(pq->size ==MaxQueueSize);
}
u8 QueueSize (Queue *pq)
{
	return (pq->size);
}
void ClearQueue(Queue *pq){
	pq->front=0;
	pq->rear=-1;
	pq->size=0;
}
void Traverse(Queue *pq,void (*pf)(QueueEntry))
{
	u8 s;
	QueueEntry e;
	for(int i=pq->front,s=0;s<pq->size;s++)
	{
		(*pf)(pq->entry[i++%MaxQueueSize]);
	}
	
}
#endif