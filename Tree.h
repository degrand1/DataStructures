#ifndef TREE_H
#define TREE_H
	#include "LinkedList.h"
	#include <stddef.h>


	struct TreeNode {
		TreeNode* left;
		TreeNode* right;
		int data;
	};

	class Tree {
	private:
		TreeNode* root;
		void DeleteTreeHelper(TreeNode* node);
		TreeNode* CreateBSTTreeNode(int* list, int start, int end );
		void InOrderTraversalHelper(TreeNode* node);
		void CreateArrayOfLinkedListsForEachLevelOfTreeHelper( LinkedList<int>* arrayList, int level, TreeNode* node );
		int GetMaxHeight(TreeNode* node);
		int GetMinHeight(TreeNode* node);
	public:
		Tree() : root(NULL) {}
		~Tree();

		bool IsBalanced();
		int GetHeight() { return GetMaxHeight(root); }
		void CreateBSTFromSortedList(int* list, int n);
		void InOrderTraversal();
		LinkedList<int>* CreateArrayOfLinkedListsForEachLevelOfTree();
	};
#endif