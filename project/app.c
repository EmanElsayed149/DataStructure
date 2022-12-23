#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "app.h"

#ifdef shortedJobFirstScheduling   //to choose which alghorithm you want 

void fun(ProcessNode p) // helper fun to print data of process
{
    printf("id = %d , burst time= %d \n",p.id,p.burstTime);  fflush(stdout);
}
// add new process in two queues (first queuw contain served order process , second contain input order process )
void AddProcess(Queue* pq,Queue* pq2) 
{
    int time; 
    ProcessNode p;
    p.id=size(pq)+1;  // id increase by one when you insert new process so , user needn't to enter id 
    printf("Enter burst time for this process : ");  fflush(stdout);
    scanf(" %d",&time);
    p.burstTime=time;
    //printf("id is=%d, burst =%d\n",p.id,p.burstTime);
    insertWithSorting(pq,p);
    insertWithoutSorting(pq2,p);
    printf("*********Process with id= %d are added successfully*********\n",p.id); fflush(stdout);
    
}
// serving process from to queueus 
// you pass pointer to id to know which process will be served from input_order queue 
void serveProcess(Queue* pq,Queue* pq2,u8* pid)
{
    serveFromSorting(pq,pid);
    serveFromInputOrder(pq2,pid);
    printf("Process served successfully\n");  fflush(stdout);
}
u8 howManyWaitingProcess(Queue *pq)
{
    u8 s=size(pq);
    printf("there are %d processes to be served\n",s); fflush(stdout);
    return s;
}
void displayServedOrder(Queue *pq)
{
    display(pq,fun);
}
void displayInputOrder(Queue *pq)
{
    display(pq,fun);
}
u8 cpuTotalBurstTime(Queue *pq)
{
    printf("Cpu total Burst time for all processes is %d\n",totalBurstTime(pq));  fflush(stdout);
    return (totalBurstTime(pq));
}
#else
#endif
