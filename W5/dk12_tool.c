#include <stdlib.h>
#include "dk12_tool.h"

static void deleteNode(doubleNode* aNode);
static doubleNode* createNodeWithDoubleValue(double value);

doubleTree* createDoubleTree()
{
	doubleTree* newTree = (doubleTree*)malloc(sizeof(doubleTree));

	if (newTree != NULL)
	{
		newTree->root = NULL;
		newTree->count = 0;
	}
	return newTree;
}

void deleteDoubleTree(doubleTree* aTree)
{
	deleteNode(aTree->root);
	free(aTree);
}

static void deleteNode(doubleNode* aNode)
{
	if (NULL != aNode)
	{
		deleteNode(aNode->leftChild);
		deleteNode(aNode->rightChild);
		free(aNode);
	}
}

static doubleNode* createNodeWithDoubleValue(double value)
{
	doubleNode* newNode = (doubleNode*)malloc(sizeof(doubleNode));

	if (NULL != newNode)
	{
		newNode->leftChild = NULL;
		newNode->rightChild = NULL;
		newNode->value = value;
	}
	return newNode;
}

void insertDoubleValueToTree(doubleTree* aTree, double aValue)
{
	if (NULL == aTree)
		return;

	doubleNode* theNode = createNodeWithDoubleValue(aValue);
	if (NULL == theNode)
		return;

	if (NULL == aTree->root)
		aTree->root = theNode;

	else
	{
		doubleNode* theCurrent = aTree->root;
		doubleNode* theParent = NULL;

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
	}
	aTree->count++;
}

doubleNode* findNodeWithValue(doubleTree* aTree, double aValue) 
{
	doubleNode* theCurrentNode = NULL;

	if (NULL != aTree)
	{
		theCurrentNode = aTree->root;
		while (aValue != theCurrentNode->value)
		{
			theCurrentNode = (aValue < theCurrentNode->value)
				? theCurrentNode->leftChild
				: theCurrentNode->rightChild;

			if (NULL == theCurrentNode)
			{
				printf("\nNode does not exist!!!\n");
				break;
			}
		}
	}
	return theCurrentNode;
}

doubleNode* getRecipient(doubleTree* aTree, doubleNode* aDelNode)
{
	doubleNode* theRecipientParent = aDelNode;
	doubleNode* theRecipient = aDelNode;
	doubleNode* theCurrent = aDelNode->rightChild;

	while (NULL != theCurrent)
	{
		theRecipientParent = theRecipient;
		theRecipient = theCurrent;
		theCurrent = theCurrent->leftChild;
	}

	if (theRecipient != aDelNode->rightChild)
	{
		theRecipientParent->leftChild = theRecipient->rightChild;
		theRecipient->rightChild = aDelNode->rightChild;
	}
	return theRecipient;
}

double deleteValueFromTree(doubleTree* aTree, double aValue) 
{
	double theResult = 1;
	doubleNode* theCurrent = aTree->root;
	doubleNode* theParent = aTree->root;
	double LeftChild = 1;

	while (aValue != theCurrent->value)
	{
		theParent = theCurrent;
		if (aValue < theCurrent->value)
		{
			LeftChild = 1;
			theCurrent = theCurrent->leftChild;
		}
		else
		{
			LeftChild = 0;
			theCurrent = theCurrent->rightChild;
		}

		if (NULL == theCurrent)
			return 0;
	}

	if (NULL == theCurrent->leftChild && NULL == theCurrent->rightChild)
	{
		if (aTree->root == theCurrent)
			aTree->root = NULL;

		else if (LeftChild)
			theParent->leftChild = NULL;

		else
			theParent->rightChild = NULL;
	}
	else if (NULL == theCurrent->rightChild)
	{
		if (aTree->root == theCurrent)
			aTree->root = theCurrent->leftChild;

		else if (LeftChild)
			theParent->leftChild = theCurrent->leftChild;

		else
			theParent->rightChild = theCurrent->leftChild;
	}
	else if (NULL == theCurrent->leftChild)
	{
		if (aTree->root == theCurrent)
			aTree->root = theCurrent->rightChild;

		else if (LeftChild)
			theParent->leftChild = theCurrent->rightChild;

		else
			theParent->rightChild = theCurrent->rightChild;
	}
	else
	{
		doubleNode* theRecipient = getRecipient(aTree, theCurrent);
		if (aTree->root == theRecipient)
			aTree->root = NULL;

		else if (LeftChild)
			theParent->leftChild = theRecipient;

		else
			theParent->rightChild = theRecipient;
	}

	free(theCurrent);
	theResult = 1;
	return theResult;
}

void printTree(doubleNode* aRoot) 
{
	if (NULL == aRoot)
		return;

	printf("%.3f ", aRoot->value);
	printTree(aRoot->leftChild);
	printTree(aRoot->rightChild);
}