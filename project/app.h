#ifndef APP_H_
#define APP_H_


#define shortedJobFirstScheduling 
void fun(ProcessNode p);
void AddProcess(Queue* pq,Queue* pq2);
void serveProcess(Queue* pq,Queue* pq2,u8* pid);
u8 howManyWaitingProcess(Queue *pq);
void displayServedOrder(Queue *pq);
void displayInputOrder(Queue *pq);
u8 cpuTotalBurstTime(Queue *pq);

#endif