#include <stdio.h>
#include <stdlib.h>
#include "comparsion.h"
#include "tree.h"
#include "stack.h"
void CreateTree(Tree *pt)
{
	*pt=NULL;
}
u8 TreeEmpty(Tree *pt)
{
	return (!*pt);
}
u8 TreeFull(Tree *pt)
{
	return 0;
}
void InorderRec (Tree *pt, void (*visit)(TreeEntry e))
{
	if(*pt)
	{
		InorderRec(&(*pt)->left,visit);
		(*visit)((*pt)->entry);
		InorderRec(&(*pt)->right,visit);
	}
}
/*******************E7*******************/
void ClearTreeAux(Tree *pt)
{
	if(*pt)
	{
		ClearTreeAux(&(*pt)->left);
		ClearTreeAux(&(*pt)->right);
		free(*pt);
	}
}
void ClearTree(Tree *pt)
{
	ClearTreeAux(pt);
	*pt=NULL;
}
void Inorder (Tree *pt, void (*visit)(TreeEntry e))
{
	Stack s;
	void *p= (void *)(*pt);  // adress of first tree node 
	if(p) // if tree not empty
	{
		initStack(&s);
		do{
			while(p)
			{
				push(p,&s);
				p=(void *)(((TreeNode *)p)->left);
			}
			pop(&p,&s);
			(*visit)(((TreeNode *)p)->entry);
			p=(void *)(((TreeNode *)p)->right);
		}while(!StackEmpty(&s) || p);
	}
	
}
void InsertTree(Tree *pt,TreeEntry *pe)
{
	if(!*pt)
	{
		*pt=(TreeNode *)malloc(sizeof(TreeNode));
		(*pt)->entry=*pe;
		(*pt)->right=NULL;
		(*pt)->left=NULL;
	}else if(LT(*pe,(*pt)->entry))
	{
		InsertTree(&(*pt)->left,pe);
	}else{
		InsertTree(&(*pt)->right,pe);
	}
}

/*********************E4***************/
int TreeSize (Tree *pt)
{
	if(!*pt) return 0;
	return (1+TreeSize(&(*pt)->left)+TreeSize(&(*pt)->right));
}
/******************E6****************/
int TreeDepth(Tree *pt)
{
	if(!*pt) return 0;
	int a=TreeDepth(&(*pt)->left);
	int b=TreeDepth(&(*pt)->right);
	return (a>b) ? 1+a : 1+b;
}
int FindItemRec(Tree *pt ,TreeEntry *pe,TreeEntry key)
{
	if(!(pt))
	{
		return 0;
	}
	if (EQ((*pt)->entry,key))
	{
		*pe=(*pt)->entry;
		return 1;
	}else if(LT((*pt)->entry,key))
	{
		FindItemRec(&(*pt)->right,pe,key);
	}else{
		FindItemRec(&(*pt)->left,pe,key);
	}
}
int FindItem(Tree *pt ,TreeEntry *pe,TreeEntry key)
{
	int found=0;
	TreeNode *p=*pt ;
	while(p && !(found=EQ(p->entry,key)))
	{
		if(LT(p->entry,key))
		{
			p= p->right;
		}else{
			p =p->left;
		}
	}
	if(found){*pe=p->entry;}
	return found;
}
int DeletItemTree(Tree *pt,TreeEntry *pe,TreeEntry key)
{
	int found =0;
	TreeNode *p=*pt;
	TreeNode *r=NULL;
	while(p && !(found=EQ(p->entry,key)))
	{
		r=p;
		if(LT(p->entry,key)){
			p=p->right;
		}else{
			p=p->left;
		}
	}
	if(found)
	{
		*pe=p->entry;
		if(!r)
		{
			DeletNodeTree(pt);
		}else if(LT(r->entry,key))
		{
			DeletNodeTree(&(r->right));
		}else{
			DeletNodeTree(&(r->left));
		}
	}
	return found;
}
void  DeletNodeTree(Tree *pt)
{
	TreeNode *p=*pt;
	TreeNode *r;
	if(!p->left)
	{
		(*pt)= (*pt)->right;
	}else if (! p->right)
	{
		(*pt) =(*pt)->left;
	}else{
		p=(*pt)->left ;
		if(! p->right){
			(*pt)-> entry = p->entry;
			(*pt)->left= p->left;
		}else{
			r=p->right;
			do
			{
				r=p;
				p=p->right;
				
			}while(p->right);
			(*pt)->entry=p->entry;
			r->right=p->left;
		}
	}
	free(p);
}
/******************E5*******************/
int TreeLeaves(Tree *pt)
{
	if(!*pt) {return 0;}
	else if(!(*pt)->right && !(*pt)->left)
	{
		
		return 1+TreeLeaves(&(*pt)->left)+TreeLeaves(&(*pt)->right);
	}
	else{
		return TreeLeaves(&(*pt)->left)+TreeLeaves(&(*pt)->right);
	}
}
/*******************E8*****************/
void TreeCopy(Tree *pt,Tree **newcopy)
{
	CreateTree(*newcopy);
	TreeCopyAux(pt,*newcopy);
	
}
void TreeCopyAux(Tree *pt,Tree *newcopy)
{
	if(*pt)
	{
		InsertTree(newcopy,&(*pt)->entry);
		TreeCopyAux(&(*pt)->left,newcopy);
		TreeCopyAux(&(*pt)->right,newcopy);
	}
}
/****************E9***************/
void DoupleOrder(Tree *pt,void(*visit)(TreeEntry e))
{
	if(*pt)
	{
		(*visit)((*pt)->entry);
		DoupleOrder(&(*pt)->left,visit);
		(*visit)((*pt)->entry);
		DoupleOrder(&(*pt)->right,visit);
	}
}
/****************************E13*****************************/
// make queue caryy void* because if it carry treeentry it should contain tree.h
// which it isn't perfect in code layers
void TraveseLevel(Tree *pt,void(*visit)(TreeEntry e))
{
	
	Queue q;
	Tree e;
	if(!*pt)
	{
		return;
	}else{
		
		CreateQueue(&q);
		Append(*pt,&q);
		Append(NULL,&q);
		while(QueueSize(&q)>1) //very important case because queue always not empty it cantain null 
		// so if size ==1 it will entire in infinte loop 
		{
			Serve((void*)&e,&q);
			if(e==NULL){
				//printf("yes\n");
				//break;
				Append(NULL,&q);
				printf("\n");
			}
			else{
				if(e->left){
			        Append(e->left,&q);
			    }
			    if(e->right)
			    { 
			        Append(e->right,&q);
		        }
				printf("%d ",e->entry);
			}	
		}
	}
}
/**************E14***********************/
int TreeWidth(Tree *pt)
{
	int counter=0,max=0;
	Queue q;
	Tree e;
	if(!*pt)
	{
		return 0;
	}else{
		
		CreateQueue(&q);
		Append(*pt,&q);
		Append(NULL,&q);
		while(QueueSize(&q)>1) //very important case because queue always not empty it cantain null 
		// so if size ==1 it will entire in infinte loop 
		{
			Serve((void*)&e,&q);
			if(e==NULL){
				if(counter>max){
					max=counter;
					counter=0;
				}
				Append(NULL,&q);
			}
			else{
				counter++;
				if(e->left){
			        Append(e->left,&q);
			    }
			    if(e->right)
			    { 
			        Append(e->right,&q);
		        }
			}	
		}
		if(counter>max){
			max=counter;
	    }
	}
	return max;
}