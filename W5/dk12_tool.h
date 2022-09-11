#ifndef dk12_tool_h
#define dk12_tool_h
#include <stdio.h>
#include <stdlib.h>

typedef struct __node doubleNode;
struct __node 
{
	double value;
	doubleNode* leftChild;
	doubleNode* rightChild;
};

typedef struct __tree 
{
	doubleNode* root;
	double count;
} doubleTree;

doubleTree* createDoubleTree();										  
void deleteDoubleTree(doubleTree* aTree);							  
void printTree(doubleNode* aRoot);								  
void insertDoubleValueToTree(doubleTree* aTree, double aValue);  
double deleteValueFromTree(doubleTree* aTree, double aValue);	  
doubleNode* findNodeWithValue(doubleTree* aTree, double aValue); 

#endif