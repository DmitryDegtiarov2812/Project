#include "tree.h"
#include <stdlib.h>
#include <string.h>

BinTree* createBinTree()
{
	BinTree* aTree = (BinTree*)malloc(sizeof(BinTree));
	if (NULL != aTree)
	{
		aTree->root = NULL;
		aTree->count = 0;
	}
	return aTree;
}

void destroyBinTree(BinTree* aTree)
{
	if (NULL != aTree)
	{
		free(aTree);
	}
}

void debugTree(BinTree* ATree)
{
	addNode(ATree, 1);
	addNode(ATree, 13);
	addNode(ATree, 9);
	addNode(ATree, 7);
	addNode(ATree, 15);
	addNode(ATree, 18);
	addNode(ATree, 20);
	addNode(ATree, 11);
	addNode(ATree, 12);
	addNode(ATree, 5);
}

Node* createNode(int aValue)
{
	Node* theNode = (Node*)malloc(sizeof(Node));

	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}

	return theNode;
}

void destroyNode(Node* aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
}

Node* destroyTreeNode(Node* treeRoot, int value)
{
	if (treeRoot == NULL) {
		return treeRoot;
	}
	if (value < treeRoot->value) {
		treeRoot->leftChild = destroyTreeNode(treeRoot->leftChild, value);
	}
	else if (value > treeRoot->value) {
		treeRoot->rightChild = destroyTreeNode(treeRoot->rightChild, value);
	}
	else
	{
		if (treeRoot->leftChild == NULL)
		{
			Node* tempNode = treeRoot->rightChild;
			destroyNode(treeRoot);
			return tempNode;
		}
		else if (treeRoot->rightChild == NULL)
		{
			Node* tempNode = treeRoot->leftChild;
			destroyNode(treeRoot);
			return tempNode;
		}
		Node* tempNode = getSuccessor(treeRoot->rightChild);
		treeRoot->value = tempNode->value;
		treeRoot->rightChild = destroyTreeNode(treeRoot->rightChild, tempNode->value);
	}
	return treeRoot;
}

Node* getSuccessor(Node* treeRoot)
{
	Node* theCurrent = treeRoot;
	while (theCurrent && theCurrent->leftChild != NULL) {
		theCurrent = theCurrent->leftChild;
	}
	return theCurrent;
}

void addNode(BinTree* aTree, int aValue)
{
	if (NULL == aTree)
	{
		return;
	}
	Node* theNode = createNode(aValue);
	if (NULL == theNode)
	{
		return;
	}
	if (NULL == aTree->root)
	{
		aTree->root = theNode;
		aTree->count++;
	}
	else
	{
		Node* theCurrent = aTree->root;
		Node* theParent = NULL;
		while (1)
		{
			theParent = theCurrent;
			if (aValue < theCurrent->value)
			{
				theCurrent = theCurrent->leftChild;
				if (NULL == theCurrent)
				{
					theParent->leftChild = theNode;
					break;
				}
			}
			else
			{
				theCurrent = theCurrent->rightChild;
				if (NULL == theCurrent)
				{
					theParent->rightChild = theNode;
					break;
				}
			}
		}

		aTree->count++;
	}
}

Node* findNode(BinTree* aTree, int aValue)
{
	Node* theCurrentNode = NULL;
	if (NULL != aTree->root)
	{
		theCurrentNode = aTree->root;
		while (aValue != theCurrentNode->value)
		{

			if (aValue < theCurrentNode->value) {
				theCurrentNode = theCurrentNode->leftChild;
			}
			else
				theCurrentNode = theCurrentNode->rightChild;

			if (NULL == theCurrentNode) {
				break;
			}
		}
	}

	return theCurrentNode;
}

void printBinTree(Node* aNode)
{
	if (NULL != aNode)
	{
		printBinTree(aNode->leftChild);
		printBinTree(aNode->rightChild);
		printf("[%d] ", aNode->value);
	}
}

int deleteValueFromTree(BinTree* aTree, int aValue)
{
	int theResult = 1;
	Node* theCurrentNode = aTree->root;
	Node* theParent = aTree->root;
	int LeftChild = 1;

	while (aValue != theCurrentNode->value)
	{
		theParent = theCurrentNode;
		if (aValue < theCurrentNode->value)
		{
			LeftChild = 1;
			theCurrentNode = theCurrentNode->leftChild;
		}
		else
		{
			LeftChild = 0;
			theCurrentNode = theCurrentNode->rightChild;
		}

		if (NULL == theCurrentNode)
			return 0;
	}

	if (NULL == theCurrentNode->leftChild && NULL == theCurrentNode->rightChild)
	{
		if (aTree->root == theCurrentNode)
			aTree->root = NULL;

		else if (LeftChild)
			theParent->leftChild = NULL;

		else
			theParent->rightChild = NULL;
	}
	else if (NULL == theCurrentNode->rightChild)
	{
		if (aTree->root == theCurrentNode)
			aTree->root = theCurrentNode->leftChild;

		else if (LeftChild)
			theParent->leftChild = theCurrentNode->leftChild;

		else
			theParent->rightChild = theCurrentNode->leftChild;
	}
	else if (NULL == theCurrentNode->leftChild)
	{
		if (aTree->root == theCurrentNode)
			aTree->root = theCurrentNode->rightChild;

		else if (LeftChild)
			theParent->leftChild = theCurrentNode->rightChild;

		else
			theParent->rightChild = theCurrentNode->rightChild;
	}

	free(theCurrentNode);
	theResult = 1;
	return theResult;
}