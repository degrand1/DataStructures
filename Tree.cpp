#include "Tree.h"

#include <algorithm>
#include <iostream>

using namespace std;

Tree::~Tree()
{
	DeleteTreeHelper(root);
}

void Tree::DeleteTreeHelper(TreeNode* node)
{
	if( node == NULL ) return;
	DeleteTreeHelper(node->left);
	DeleteTreeHelper(node->right);
	cout << "Deleting node: " << node->data << endl;
	delete node;
}

int Tree::GetMaxHeight(TreeNode* node)
{
	if( node == NULL ) return 0;
	return 1 + std::max( GetMaxHeight(node->left), GetMaxHeight(node->right) );
}

int Tree::GetMinHeight(TreeNode* node)
{
	if( node == NULL ) return 0;
	return 1 + min( GetMinHeight(node->left), GetMinHeight(node->right) );
}

bool Tree::IsBalanced()
{
	if( root == NULL || root->left == NULL || root->right == NULL ) return true;
	return GetMaxHeight( root ) - GetMinHeight( root ) <= 1;
}

void Tree::InOrderTraversalHelper(TreeNode* node)
{
	if( node == NULL ) return;
	InOrderTraversalHelper(node->left);
	cout << node->data << " ";
	InOrderTraversalHelper(node->right);
}

void Tree::InOrderTraversal()
{
	InOrderTraversalHelper(root);
}

TreeNode* Tree::CreateBSTTreeNode(int* list, int start, int end, TreeNode* parent )
{
	if( end < start ) return NULL;
	int mid = (start + end)/2;
	TreeNode* node = new TreeNode();
	node->data = list[mid];
	node->parent = parent;
	node->left = CreateBSTTreeNode(list, start, mid-1, node);
	node->right = CreateBSTTreeNode(list, mid+1, end, node);
	return node;
}

void Tree::CreateBSTFromSortedList(int* list, int n)
{
	root = CreateBSTTreeNode( list, 0, n-1, NULL);
}

void Tree::CreateArrayOfLinkedListsForEachLevelOfTreeHelper( LinkedList<int>* arrayList, int level, TreeNode* node )
{
	if( node == NULL ) return;
	CreateArrayOfLinkedListsForEachLevelOfTreeHelper( arrayList, level+1, node->left );
	CreateArrayOfLinkedListsForEachLevelOfTreeHelper( arrayList, level+1, node->right );
	arrayList[level].AddElement(node->data);
}

LinkedList<int>* Tree::CreateArrayOfLinkedListsForEachLevelOfTree()
{
	int numLevels = GetMaxHeight(root);
	LinkedList<int>* returnList = new LinkedList<int>[numLevels];
	CreateArrayOfLinkedListsForEachLevelOfTreeHelper( returnList, 0, root );
	return returnList;
}

TreeNode* Tree::GetInOrderSuccessor( TreeNode* node )
{
	if( node == NULL ) return NULL;
	if( node->right != NULL )
	{
		//Get the leftmode node of this subtree
		TreeNode* leftModeNode = NULL;
		TreeNode* currentNode = node->right;
		while( currentNode != NULL )
		{
			leftModeNode = currentNode;
			currentNode = currentNode->left;
		}
		return leftModeNode;
	}
	//If the root has no right children, then there is no successor
	TreeNode* parent = node->parent;
	while( parent != NULL )
	{
		if( parent->left == node )
			break;
	}
	return parent;
}

int Tree::NumberOfNodesCoveredByRoot( TreeNode* root, TreeNode* p, TreeNode* q )
{
	if( root == NULL ) return 0;
	int NumNodes = 0;
	if( root == p || root == q ) NumNodes++;
	NumNodes += NumberOfNodesCoveredByRoot( root->left, p, q );
	if( NumNodes == 2 ) return NumNodes; //return early if both nodes were found
	return NumNodes + NumberOfNodesCoveredByRoot(root->right, p, q );
}

TreeNode* Tree::GetCommonAncestorHelper( TreeNode* root, TreeNode* p, TreeNode* q )
{
	//edge case for when p and q equal each other
	if( root == NULL ) return NULL;
	if( p == q ) return root->parent;
	int NumNodesOnLeftSide = NumberOfNodesCoveredByRoot( root->left, p, q );
	if( NumNodesOnLeftSide == 2 )
	{
		if( root->left == p || root->left == q ) return root->left;
		else return GetCommonAncestorHelper( root->left, p, q );
	}
	else if( NumNodesOnLeftSide == 1 )
	{
		if( root == p ) return p;
		if( root == q ) return q;
	}
	int NumNodesOnRightSide = NumberOfNodesCoveredByRoot( root->right, p, q );
	if( NumNodesOnRightSide == 2 )
	{
		if( root->right == p || root->right == q ) return root->right;
		else return GetCommonAncestorHelper( root->right, p, q );
	}
	else if( NumNodesOnRightSide == 1 )
	{
		if( root == p ) return p;
		if( root == q ) return q;
	}

	if( NumNodesOnRightSide == 1 && NumNodesOnLeftSide == 1 ) return root;
	return NULL;
}

TreeNode* Tree::GetCommonAncsestor( TreeNode* p, TreeNode* q )
{
	return GetCommonAncestorHelper( root, p, q);
}