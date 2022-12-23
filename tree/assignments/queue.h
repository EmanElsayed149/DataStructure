#ifndef QUEUE_H
#define  QUEUE_H
#include "global.h"
/**********user define *************/
typedef void* QueueEntry ;
#define MaxSize 2

/************array based or linked based ******/
#define LinkedBased
#ifdef  LinkedBased
typedef struct queuenode
{
	QueueEntry entry;
	struct queuenode *next;
}QueueNode;
typedef struct queue{
	QueueNode *rear;
	QueueNode *front;
	u8 size;
}Queue;

#else
// for ArrayBased 
/*******Queue component*******/
/* rear refer to last element in queue
   front refer to first element in queue  
   size to test if queue is empty or full
*/
typedef struct queue{
	u8 rear;
	u8 front;
	u8 size;
	QueueEntry entry[MaxSize];
}Queue;
#endif

/********decleration for function in queue*****/
void CreateQueue (Queue *pq);
void Append (QueueEntry e,Queue *pq);
void Serve (QueueEntry *pe , Queue *pq);
u8 QueueEmpty(Queue *pq);
u8 QueueFull(Queue *pq);
u8 QueueSize (Queue *pq);
void ClearQueue(Queue *pq);
void Traverse(Queue *pq,void (*pf)(QueueEntry));
#endif