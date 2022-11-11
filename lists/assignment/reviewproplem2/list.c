#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#ifdef DoublyLinkedList
/*****************DoublyLinkedList list  implementation************/

void CreateList(List *pl)
{
	pl->size=0;
	pl->head=NULL;
}
u8 ListSize(List *pl)
{
	return pl->size;
}
u8 ListEmpty(List *pl)
{
	return !pl->size;
}
u8 ListFull(List *pl)
{
	return 0;
}

void DeleteList(int pos,ListEntry *pe,List *pl)
{
	ListNode *pn, *temp;
	if(pos ==0)   // for only deleting first ele in list 
	{
		*pe=pl->head->entry;
		temp=pl->head->next;
		free(pl->head); 
		pl->head=temp;
		temp->previous=NULL;
	}
	else{
		int i;
		for(i=0,pn=pl->head;i<pos-1;i++)
	    {
			pn=pn->next;
	    }
		// pn now qual to node which before you want (delete pn->next)
		*pe=pn->next->entry;
		temp=pn->next->next;
		free(pn->next);
		temp->previous=pn;
		pn->next=temp;
	}
	// size will decrease by one 
	pl->size--;
}
void DeleteListRecursivly(int pos,ListEntry *pe,List *pl)
{
	ListNode *pn, *temp;
	if(pos ==0)   // for only deleting first ele in list 
	{
		*pe=pl->head->entry;
		temp=pl->head->next;
		free(pl->head); 
		pl->head=temp;
		temp->previous=NULL;
	}
	else{
		pn=position(pl->head,0,pos);
		// pn now qual to node which before you want (delete pn->next)
		*pe=pn->next->entry;
		temp=pn->next->next;
		free(pn->next);
		temp->previous=pn;
		pn->next=temp;
	}
	// size will decrease by one 
	pl->size--;
}

u8 InsertList(int pos,ListEntry e,List *pl)
{
	ListNode *pn;
	ListNode *node=(ListNode *)malloc(sizeof(ListNode));
	if(node)
	{
		node->entry = e;
		node->next=NULL;
		// if pos ==0 
		if(pos==0)
		{
			node->previous=NULL;
			node->next=pl->head;
			pl->head=node;
		}else{
			// pn now qual to node which before you want (delete pn->next)
			int i;
			for( i=0,pn=pl->head;i<pos-1;i++){pn=pn->next;}
			node->next=pn->next;
			pn->next->previous=node;
			pn->next=node;
			node->previous=pn;
		}
		// size will increase by one
		pl->size++;
		return 1;
	}
	return 0;
}

void DestroyList(List *pl)
{
	ListNode *pn;
	while(pl->head)
	{
		pn=pl->head->next;
		free(pl->head);
		pl->head=pn;
	}
	pl->size=0;
}
void TraverseList(List *pl,void (*fun)(ListEntry ))
{
	ListNode *pn=pl->head;
	for(;pn;pn=pn->next)
	{
		(*fun)(pn->entry);
	}
}

void ReplaceList(int pos,ListEntry e, List *pl)
{
	ListNode *pn;
	int i;
	for(i=0,pn=pl->head;i<pos;i++){pn=pn->next;}
	pn->entry=e;
}

void RetrieveList(int pos,ListEntry *pe,List *pl)
{
	ListNode *pn=pl->head;
	int i;
	for(i=0,pn=pl->head;i<pos;i++){pn=pn->next;}
	*pe=pn->entry;
}
void JoinList(List *pl1,List *pl2)
{
	ListNode *pn=pl1->head;
	int pos=0;
	while(pn)
	{
		InsertList(pos,pn->entry,pl2);
		pn=pn->next;
		pos++;
	}
}

/*****insert recursivly***************/
/**helper function to arrive at pos *******/
ListNode* position(ListNode *pn,int i,int pos)
{
	if(i<pos-1){
		return position(pn->next,i+1,pos);
		
	}else{
		return pn;
	}
}
u8 InsertListRecursivly(int pos,ListEntry e,List *pl)
{
	ListNode *pn=pl->head;
	ListNode *node=(ListNode *)malloc(sizeof(ListNode));
	if(node)
	{
		node->entry = e;
		node->next=NULL;
		// if pos ==0 
		if(pos==0)
		{
			node->previous=NULL;
			node->next=pl->head;
			pl->head=node;
		}else{
			// pn now qual to node which before you want (delete pn->next)
			pn=position(pl->head,0,pos);
			node->next=pn->next;
			if(pn->next)
			{
				pn->next->previous=node;
			}
			pn->next=node;
			node->previous=pn;
		}
		// size will increase by one
		pl->size++;
		return 1;
	}
	return 0;
}
#else
/*****************Linked list implementation************/


void CreateList(List *pl)
{
	pl->size=0;
	pl->head=NULL;
}
u8 ListSize(List *pl)
{
	return pl->size;
}
u8 ListEmpty(List *pl)
{
	return !pl->size;
}
u8 ListFull(List *pl)
{
	return 0;
}

void DeleteList(int pos,ListEntry *pe,List *pl)
{
	ListNode *pn, *temp;
	if(pos ==0)   // for only deleting first ele in list 
	{
		*pe=pl->head->entry;
		temp=pl->head->next;
		free(pl->head); 
		pl->head=temp;
	}
	else{
		int i;
		for(i=0,pn=pl->head;i<pos-1;i++)
	    {
			pn=pn->next;
	    }
		// pn now qual to node which before you want (delete pn->next)
		*pe=pn->next->entry;
		temp=pn->next->next;
		free(pn->next);
		pn->next=temp;
	}
	// size will decrease by one 
	pl->size--;
}

u8 InsertList(int pos,ListEntry e,List *pl)
{
	ListNode *pn;
	ListNode *node=(ListNode *)malloc(sizeof(ListNode));
	if(node)
	{
		node->entry=e;
		node->next=NULL;
		// if pos ==0 
		if(pos==0)
		{
			node->next=pl->head;
			pl->head=node;
		}else{
			// pn now qual to node which before you want (delete pn->next)
			int i;
			for( i=0,pn=pl->head;i<pos-1;i++){pn=pn->next;}
			node->next=pn->next;
			pn->next=node;
		}
		// size will increase by one
		pl->size++;
		return 1;
	}
	return 0;
}

void DestroyList(List *pl)
{
	ListNode *pn;
	while(pl->head)
	{
		pn=pl->head->next;
		free(pl->head);
		pl->head=pn;
	}
	pl->size=0;
}

void TraverseList(List *pl,void (*fun)(ListEntry ))
{
	ListNode *pn=pl->head;
	
	for(;pn;pn=pn->next)
	{
		
		fun(pn->entry);
		//printf("%d\n",pn->entry.value.s.degree); fflush(stdout);
	}
}

void ReplaceList(int pos,ListEntry e, List *pl)
{
	ListNode *pn;
	int i;
	for(i=0,pn=pl->head;i<pos;i++){pn=pn->next;}
	pn->entry=e;
}

void RetrieveList(int pos,ListEntry *pe,List *pl)
{
	ListNode *pn=pl->head;
	int i;
	for(i=0,pn=pl->head;i<pos;i++){pn=pn->next;}
	*pe=pn->entry;
}
void JoinList(List *pl1,List *pl2)
{
	ListNode *pn=pl1->head;
	int pos=0;
	while(pn)
	{
		InsertList(pos,pn->entry,pl2);
		pn=pn->next;
		pos++;
	}
}
#endif