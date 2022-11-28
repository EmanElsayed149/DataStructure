#include <stdio.h>
#include <stdlib.h>
#include "comparsion.h"
#include "tree.h"
#include "stack.h"
void CreateTree(Tree *pt)
{
	*pt=NULL;
}
void CreateTree2(Tree2 *pt)
{
	pt->root =NULL;
	pt->size=0;
	pt->depth=0;
}
u8 TreeEmpty(Tree *pt)
{
	return (!*pt);
}
u8 TreeEmpty2(Tree2 *pt)
{
	return (!pt->root);
}
u8 TreeFull(Tree *pt)
{
	return 0;
}
u8 TreeFull2(Tree2 *pt)
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
void InorderRec2(Tree2 *pt, void (*visit)(TreeEntry e))
{
	InorderRec(&pt->root,visit);
}
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
void InsertTree2Aux(Tree *pt,TreeEntry *pe,int *pdepth)
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
	(*pdepth)++;
}
void InsertTree2(Tree2 *pt,TreeEntry *pe)
{
	//if(!pt->root)  can't do this because recursion will then use adress of left or right 
	// to solve use &(pt->root)
	int d=0;
	InsertTree2Aux(&(pt->root),pe,&d);
	if(pt->depth < d)
	{
		pt->depth=d;
	}
	pt->size++;
}
int TreeSize2 (Tree2 *pt)
{
	return pt->size;
}
int TreeDepth2(Tree2 *pt)
{
	return pt->depth;
}

int TreeSize (Tree *pt)
{
	if(!*pt) return 0;
	return (1+TreeSize(&(*pt)->left)+TreeSize(&(*pt)->right));
}
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
int FindItemRec2(Tree2 *pt ,TreeEntry *pe,TreeEntry key)
{
	FindItemRec(& pt->root,pe,key);
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
int FindItem2(Tree2 *pt ,TreeEntry *pe,TreeEntry key)
{
	int found=0;
	TreeNode *p=pt->root ;
	while(p && !(found=EQ(p->entry,key)))
	{
		if(LT(p->entry,key))
		{
			p= p->right;
		}else{
			p =p->left;
		}
	}
	if(found){*pe=p->entry; }
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
void Preorder(Tree *pt, void (*visit)(TreeEntry e))
{
	
}
void Postorder(Tree *pt, void (*visit)(TreeEntry e))
{
	
}
