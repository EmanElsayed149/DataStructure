#ifndef GLOBAL_H
#define GLOBAL_H
#include <string.h>
typedef char 
u8;
#define MaxStackSize 30              //size of satck 
#define MaxQueueSize 30

typedef struct elementtype
{
	char name[10];
	int id;
	int modelyear;
}ElementType;

#define StackEntry ElementType
#define QueueEntry ElementType

#endif