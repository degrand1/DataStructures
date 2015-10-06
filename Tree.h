#ifndef TREE_H
#define TREE_H
	#include <stddef.h>

	struct TreeNode {
		TreeNode* left;
		TreeNode* right;
		int data;
	};

	class Tree {
	private:
		TreeNode* root;
	public:
		Tree() : root(NULL) {}

		bool IsBalanced();
		int GetMaxHeight(TreeNode* node);
		int GetMinHeight(TreeNode* node);
	};
#endif