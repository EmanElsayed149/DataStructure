#ifndef LIST_H
#define LIST_H
#include "global.h"

//#define DoublyLinkedList
#ifdef DoublyLinkedList

typedef struct listnode {
	ListEntry entry;
	struct listnode *next;
	struct listnode *previous;
}ListNode;
typedef struct list{
	ListNode *head;
	int size;
}List;
#else
//listnode to include data of list and location for next node	
typedef struct listnode
{
	ListEntry entry;
	struct listnode *next;
}ListNode;
// list struct to include location of head of listnodes and size 
// may be include anthor data to improve performance 
typedef struct list{
	ListNode *head;
	int size;
}List;

#endif
/*****declarationn of function*******/
void CreateList(List *pl);
u8 ListSize(List *pl);
u8 ListEmpty(List *pl);
u8 ListFull(List *pl);
/* preconditions 
1- list should be created 
2- 0=<pos<=size-1
3- list not empty
*/
/*postcondition
1- data at pos stored in e 
2- all position > pos become p-1
3- size decrease by one
*/
void DeleteList(int pos,ListEntry *pe,List *pl);
/* preconditions 
1- list should be created 
2- 0=<pos<=size
3- list not full
*/
/*postcondition
1- data at e stored in pos  
2- all position >= pos become p+1
3- size increase by one
*/
u8 InsertList(int pos,ListEntry e,List *pl);
/* preconditions 
1- list should be created 
*/
/*postcondition
1- all data are deleted 
2- size become zero
*/
void DestroyList(List *pl);
/* preconditions 
1- list should be created 
*/
/*postcondition
1- prints all elements in list
*/
void TraverseList(List *pl,void (*fun)(ListEntry ));
/* preconditions 
1- list should be created 
2- 0=<pos<=size-1
3- list not empty
*/
/*postcondition
1- data at pos replaced by ele e
*/
void ReplaceList(int pos,ListEntry e, List *pl);
/* preconditions 
1- list should be created 
2- 0=<pos<=size-1
3- list not empty
*/
/*postcondition
1- data at pos stored in e 
*/
void RetrieveList(int pos,ListEntry *pe,List *pl);
/*******to copy list1 in list2****/
/* preconditions 
1- list1 and list2 should be created 
*/
/*postcondition
1- copy all elements in list1 and put it in list2
*/
void JoinList(List *pl1,List *pl2);
/**helper function to arrive at pos *******/
ListNode* position(ListNode *pn,int i,int pos);
u8 InsertListRecursivly(int pos,ListEntry e,List *pl);
void DeleteListRecursivly(int pos,ListEntry *pe,List *pl);
#endif