#include "Tree.h"

#include <algorithm>

using namespace std;

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