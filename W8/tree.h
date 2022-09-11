#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct tagNode Node;

struct tagNode
{
	int value;
	Node* leftChild;
	Node* rightChild;
};

typedef struct tagBinTree
{
	Node* root;
	int count;
}BinTree;

BinTree* createBinTree();
void destroyBinTree(BinTree* aTree);
Node* createNode(int aValue);
void destroyNode(Node* aNode);
Node* destroyTreeNode(Node* treeRoot, int aValue);
Node* getSuccessor(Node* treeRoot);
void addNode(BinTree* aTree, int aValue);
Node* findNode(BinTree* aTree, int aValue);
int deleteValueFromTree(BinTree* aTree, int aValue);

void printBinTree(Node* aNode);
void debugTree(BinTree* ATree);

#endif // TREE_H_INCLUDED