#ifndef TREE_H
#define TREE_H

// global inclusion
#include "global.h"

typedef struct treenode
{
	TreeEntry entry;
	struct treenode *left;
	struct treenode *right;
}TreeNode;

typedef TreeNode *Tree;
typedef struct tree
{
	TreeNode *root;
	u8 size;
	u8 depth;
}Tree2;

// if tree is pointer to treenode 
void CreateTree(Tree *pt);
u8 TreeEmpty(Tree *pt);
u8 TreeFull(Tree *pt);
int TreeSize (Tree *pt);
int TreeDepth(Tree *pt);
void ClearTree(Tree *pt);
void Preorder(Tree *pt, void (*visit)(TreeEntry e));
void Postorder(Tree *pt, void (*visit)(TreeEntry e));
void InorderRec (Tree *pt, void (*visit)(TreeEntry e));
void Inorder (Tree *pt, void (*visit)(TreeEntry e));
void InsertTree(Tree *pt,TreeEntry *pe);
int FindItemRec(Tree *pt ,TreeEntry *pe,TreeEntry key); 
int FindItem(Tree *pt ,TreeEntry *pe,TreeEntry key); 
int DeletItemTree(Tree *pt,TreeEntry *pe,TreeEntry key);
void DeletNodeTree(Tree *pt);
// if tree is struct include pointer to treenode

void CreateTree2(Tree2 *pt);
u8 TreeEmpty2(Tree2 *pt);
u8 TreeFull2(Tree2 *pt);
int TreeSize2 (Tree2 *pt);
int TreeDepth2(Tree2 *pt);
void ClearTree2(Tree2 *pt);
void Preorder2(Tree2 *pt, void (*visit)(TreeEntry e));
void Postorder2(Tree2 *pt, void (*visit)(TreeEntry e));
void InorderRec2 (Tree2 *pt, void (*visit)(TreeEntry e));
void InsertTree2Aux(Tree *pt,TreeEntry *pe,int *pdepth);
void InsertTree2(Tree2 *pt,TreeEntry *pe);
int FindItemRec2(Tree2 *pt ,TreeEntry *pe,TreeEntry key); 
int FindItem2(Tree2 *pt ,TreeEntry *pe,TreeEntry key); 
#endif