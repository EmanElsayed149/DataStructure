#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "app.h"
void main()
{
    Queue q;
    createQueueNode(&q);
    Queue q2;
    createQueueNode(&q2);
    u8 mode ;
    for(int i=0;i<11;i++)
    {
        printf("1. Add a process\n2. Serve a process\n3. How many waiting processes?\n4. Display information of waiting processes (Input Order)\n5. Display information of waiting processes (Served Order)\n6. Display total CPU burst time\n7. Exit (Save in a file)\n");
        fflush(stdout);
        scanf("%d",&mode); fflush(stdin);
        if(mode==1){
            AddProcess(&q,&q2);
        }else if(mode==2)
        {
            u8 id;
            serveProcess(&q,&q2,&id);
        }else if(mode==3)
        {
            howManyWaitingProcess(&q);
        }else if(mode==4)
        {
            displayInputOrder(&q2);
        }
        else if(mode==5)
        {
            displayServedOrder(&q);
        }else if(mode==6)
        {
            cpuTotalBurstTime(&q);
        }else{
            break;
        }
       
    }
    
}