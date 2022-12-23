#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#ifdef ARRAY_BASED
/*****************array_based list  implementation************/

void CreateList(List *pl)
{
	pl->size=0;
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
	return pl->size==MaxList;
}

void DeleteList(int pos,ListEntry *pe,List *pl)
{
	*pe=pl->entry[pos];
	for(int i=pos+1;i<=pl->size-1;i++)
	{
		pl->entry[i-1]=pl->entry[i];
	}
	pl->size--;
}

void InsertList(int pos,ListEntry e,List *pl)
{
	for(int i=pl->size-1;i>=pos;i--)
	{
		pl->entry[i+1]=pl->entry[i];
	}
	pl->entry[pos]= e;
	pl->size++;
}

void DestroyList(List *pl)
{
	pl->size=0;
}

void TraverseList(List *pl,void (*fun)(ListEntry ))
{
	for(int i=0;i<=pl->size-1;i++)
	{
		fun(pl->entry[i]);
	}
}

void ReplaceList(int pos,ListEntry e, List *pl)
{
	pl->entry[pos]=e;
}

void RetrieveList(int pos,ListEntry *pe,List *pl)
{
	*pe=pl->entry[pos];
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
		pe->calltype=pl->head->entry.calltype;
		pe->callingparty=pl->head->entry.callingparty;
		pe->calledparty=pl->head->entry.calledparty;
		pe->numberofpackets=pl->head->entry.numberofpackets;
		pe->showingid=pl->head->entry.showingid;
		pe->roaming=pl->head->entry.roaming;
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
		pe->calltype=pn->next->entry.calltype;
		pe->callingparty=pn->next->entry.callingparty;
		pe->calledparty=pn->next->entry.calledparty;
		pe->numberofpackets=pn->next->entry.numberofpackets;
		pe->showingid=pn->next->entry.showingid;
		pe->roaming=pn->next->entry.roaming;
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
		node->entry.calltype = e.calltype;
		node->entry.callingparty = e.callingparty;
		node->entry.calledparty = e.calledparty;
		node->entry.numberofpackets = e.numberofpackets;
		node->entry.showingid = e.showingid;
		node->entry.roaming = e.roaming;
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
		(*fun)(pn->entry);
	}
}

void ReplaceList(int pos,ListEntry e, List *pl)
{
	ListNode *pn;
	int i;
	for(i=0,pn=pl->head;i<pos;i++){pn=pn->next;}
	pn->entry.calltype = e.calltype;
	pn->entry.callingparty = e.callingparty;
	pn->entry.calledparty = e.calledparty;
	pn->entry.numberofpackets = e.numberofpackets;
	pn->entry.showingid = e.showingid;
	pn->entry.roaming = e.roaming;
}

void RetrieveList(int pos,ListEntry *pe,List *pl)
{
	ListNode *pn=pl->head;
	int i;
	for(i=0,pn=pl->head;i<pos;i++){pn=pn->next;}
	pe->calltype=pn->entry.calltype;
	pe->callingparty=pn->entry.callingparty;
	pe->calledparty=pn->entry.calledparty;
	pe->numberofpackets=pn->entry.numberofpackets;
	pe->showingid=pn->entry.showingid;
	pe->roaming=pn->entry.roaming;
}
#endif