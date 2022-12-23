/*****files inclusion******/
#include <stdio.h>
#include <stdlib.h>
#include "app.h"

Queue q;
Stack s;
void dis(StackEntry e){
	printf("name is: %s id: %d modelyear: %d\n",e.name,e.id,e.modelyear); fflush(stdout);
}
void AddCustomer()
{
	QueueEntry e;
	printf("Please enter customer data ?\n"); fflush(stdout);
	printf("Name: "); fflush(stdout);
	scanf("%s",e.name); fflush(stdin);
	printf("ID: ");     fflush(stdout);
	scanf("%d",&e.id);   fflush(stdin);
	printf("Model Year: "); fflush(stdout);
	scanf("%d",&e.modelyear);  fflush(stdin);
	Append(e,&q);
}
void ServeCustomer()
{
	QueueEntry e;
	Serve(&e,&q);
	printf("Custumer %s served successfuly\n",e.name);  fflush(stdout);
}
void countCustumer()
{
	int count =QueueSize(&q);
	printf("there are %d waiting customers\n",count);  fflush(stdout);
}
void DisplayCustomer()
{
	Traverse(&q,dis);
}
void DisplayRecent()
{
	QueueEntry e;
	initStack(&s);
	for(QueueNode *pn=q.front;pn;pn=pn->next)
	{
		e.id=pn->entry.id;
		e.modelyear=pn->entry.modelyear;
		strcpy(e.name,pn->entry.name);
	    push(e,&s);
	}
	DisplayStack(&s,dis);
	ClearStack(&s);	
}

