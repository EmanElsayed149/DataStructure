#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
// you should call it before start prog to initialize data 
void createQueueNode(Queue* pq)
{
    pq->size=0;
    pq->totalBurstTime =0;
    pq->head=NULL;
    pq->tail=NULL;
}
//insert new process in list according to burst time order
void insertWithSorting(Queue* pq,ProcessNode p)
{
    QueueNode* node=(QueueNode*)malloc(sizeof(QueueNode));
    (node->p).id=p.id;
    (node->p).burstTime=p.burstTime;
    node->next=NULL;
    QueueNode* last;
    QueueNode* current;
    if (pq->size==0)
    {
        pq->head=node ;
        
    }else
    {
        last=pq->head;  
        current=last->next;
        // to insert process in sotrde queue 
        if(p.burstTime < last->p.burstTime)
        {
            node->next=pq->head;
            pq->head=node;
        }else{
            while(current && current->p.burstTime < p.burstTime)
            {
                last=current;
                current=current->next;
            }
            last->next=node;
            node->next=current;
        }
        
    }
    pq->size++;
    pq->totalBurstTime += p.burstTime;
    //printf("hellllllll\n");

}
// insert new process in list according to input order 
void insertWithoutSorting(Queue* pq,ProcessNode p)
{
    QueueNode *node =(QueueNode*)malloc(sizeof(QueueNode));
    node->p.id=p.id;
    node->p.burstTime=p.burstTime;
    node->next=NULL;
    if(pq->size==0)
    {
        pq->head=node;
        pq->tail=node;
    }
    else{
        pq->tail->next=node;
        pq->tail=node;
    }
    pq->size++;
    pq->totalBurstTime+=p.burstTime;
    
}
void serveFromSorting (Queue *pq,u8* pid)
{
    ProcessNode p;
    p.burstTime=pq->head->p.burstTime;
    *pid = pq->head->p.id;
    QueueNode* pn=pq->head->next;
    free(pq->head);
    pq->head = pn;
    pq->size --;
    pq->totalBurstTime -=p.burstTime;
    printf("served id %d\n",*pid);  fflush(stdout);
}
void serveFromInputOrder(Queue* pq,u8* pid)
{
    ProcessNode p;
    QueueNode* pn=pq->head;
    if(pn->p.id==*pid){
        if(pn->next == NULL){pq->tail=NULL;}
        p.burstTime=pn->p.burstTime;
        pq->head=pn->next;
        free(pn);
    }else{
        QueueNode* temp=pn;
        while(pn && pn->p.id!=*pid)
        {
            temp=pn;
            pn=pn->next;
            //printf(" pn burst %d pid %d\n",pn->p.burstTime,*pid);
        }
        if(pn->next == NULL){pq->tail=temp;}
        p.burstTime=pn->p.burstTime;
        temp->next=pn->next;
        free(pn);
    }
    pq->size --;
    pq->totalBurstTime -=p.burstTime;
}
u8 size(Queue *pq)
{
    return pq->size;
}
u8 totalBurstTime(Queue *pq)
{
    return pq->totalBurstTime;
}
void display(Queue *pq,void(*fun)(ProcessNode))
{
    QueueNode *pn=pq->head;
    while(pn)
    {
        fun(pn->p);
        pn=pn->next;
    }
}