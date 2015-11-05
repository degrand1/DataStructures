#include "PIE_TreesAndGraphs.h"

#include "Stack.h"
#include "Tree.h"

static void PIE_Test_NonRecursivePreOrderTraversal();

void PIE_Test_TreesAndGraphs()
{
	PIE_Test_NonRecursivePreOrderTraversal();
}

static void PIE_Test_NonRecursivePreOrderTraversal()
{
	Tree tree;
	const int size = 7;
	int array[size];
	for(int i = 0; i < size; i++ )
	{
		array[i] = i;
	}
	tree.CreateBSTFromSortedList(array, size);

	Stack<TreeNode*> stack;
	stack.Enqueue(tree.root);
	while( !stack.IsEmpty() )
	{
		TreeNode* CurrentNode = stack.Dequeue()->data;
		cout << CurrentNode->data << " ";
		if( CurrentNode->right != NULL ) stack.Enqueue(CurrentNode->right);
		if( CurrentNode->left != NULL ) stack.Enqueue(CurrentNode->left);
	}
	cout << endl;
}