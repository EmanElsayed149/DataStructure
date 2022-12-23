#ifndef TREE_H
#define TREE_H

// global inclusion
#include "global.h"
#include "queue.h"
typedef struct treenode
{
	TreeEntry entry;
	struct treenode *left;
	struct treenode *right;
}TreeNode;

typedef TreeNode *Tree;

// if tree is pointer to treenode 
void CreateTree(Tree *pt);
u8 TreeEmpty(Tree *pt);
u8 TreeFull(Tree *pt);
int TreeSize (Tree *pt);
int TreeLeaves(Tree *pt);
int TreeDepth(Tree *pt);
void ClearTree(Tree *pt);
void InorderRec (Tree *pt, void (*visit)(TreeEntry e));
void Inorder (Tree *pt, void (*visit)(TreeEntry e));
void InsertTree(Tree *pt,TreeEntry *pe);
int FindItemRec(Tree *pt ,TreeEntry *pe,TreeEntry key); 
int FindItem(Tree *pt ,TreeEntry *pe,TreeEntry key); 
int DeletItemTree(Tree *pt,TreeEntry *pe,TreeEntry key);
void DeletNodeTree(Tree *pt);
void TreeCopy(Tree *pt,Tree **newcopy);
void TreeCopyAux(Tree *pt,Tree *newcopy);
void DoupleOrder(Tree *pt,void(*visit)(TreeEntry e));
void TraveseLevel(Tree *pt,void(*visit)(TreeEntry e));
int TreeWidth(Tree *pt);
#endif