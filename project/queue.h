#ifndef QUEUE_H_
#define QUEUE_H_

typedef char u8;
// node of process contain it's id and burst time 
typedef struct processnode
{
    u8 id;
    u8 burstTime;
}ProcessNode;
// cotain processNode and adress of next process
typedef struct queuenode 
{
    struct queuenode *next;
    ProcessNode p;
}QueueNode;
 
// queue struct contain 1-adress of first process in list and 2-size(number of process to be served) 3-total cpu burst time
typedef struct queue
{
    u8 size;
    QueueNode* head;
    QueueNode* tail;
    u8 totalBurstTime;
}Queue;

void createQueueNode(Queue* pq);
//insert new process in list according to burst time order
void insertWithSorting(Queue* pq,ProcessNode p);
// insert new process in list according to input order 
void insertWithoutSorting(Queue* pq,ProcessNode p);
void serveFromSorting (Queue *pq,u8* pid);
void serveFromInputOrder(Queue* pq,u8* pid);
u8 size(Queue *pq);
u8 totalBurstTime(Queue *pq);
void display(Queue *pq,void(*fun)(ProcessNode));
#endif