#include <stdio.h>
#include "tree.h"
#define MAXSIZE 10

int main(int argc, char** argv)
{
	srand(time(NULL));

	BinTree* ATree = createBinTree();

	debugTree(ATree);

	printBinTree(ATree->root);

	if (NULL != findNode(ATree, 5)) {
		printf("\nRequired node: %d\n", findNode(ATree, 5)->value);
	}
	else
		printf("\nNode not found.\n");

	deleteValueFromTree(ATree, 5);

	printBinTree(ATree->root);

	if (NULL != findNode(ATree, 5)) {
		printf("\nRequired node: %d\n", findNode(ATree, 5)->value);
	}
	else
		printf("\nNode not found.\n");

	addNode(ATree, 5);

	printBinTree(ATree->root);

	if (NULL != findNode(ATree, 5)) {
		printf("\nRequired node: %d\n", findNode(ATree, 5)->value);
	}
	else
		printf("\nNode not found.\n");

	destroyBinTree(ATree);

	return 0;
}