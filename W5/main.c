#include <stdio.h>
#include "dk12_tool.h"

int main()
{
	doubleTree* tree = createDoubleTree(); 

	insertDoubleValueToTree(tree, 3.273); 
	insertDoubleValueToTree(tree, 5.679);
	insertDoubleValueToTree(tree, 2.421);
	insertDoubleValueToTree(tree, 6.787);
	insertDoubleValueToTree(tree, 8.968);
	insertDoubleValueToTree(tree, 6.384);
	insertDoubleValueToTree(tree, 1.127);
	insertDoubleValueToTree(tree, 9.127);

	printf("First case:\n");
	printTree(tree->root); 
	printf("\nNode %.3f\n", findNodeWithValue(tree, 8.968)->value); 

	deleteValueFromTree(tree, 6.787);
	deleteValueFromTree(tree, 6.384);

	printTree(tree->root);																	  
	printf("\nNode %.3f still exist\n", findNodeWithValue(tree, 8.968)->value);

	insertDoubleValueToTree(tree, 6.787);
	insertDoubleValueToTree(tree, 6.384);

	printf("\n/////////////////////////////////////////////////////////////////////////\n\n");
	printf("Second case:\n");
	printTree(tree->root);

	printf("\nNode %.3f\n", findNodeWithValue(tree, 8.968)->value);

	deleteValueFromTree(tree, 6.787);
	deleteValueFromTree(tree, 8.968);

	printTree(tree->root);
	printf("\nNode %.3f still exist\n", findNodeWithValue(tree, 8.968)->value);
	deleteDoubleTree(tree); 
}