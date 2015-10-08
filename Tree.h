#ifndef TREE_H
#define TREE_H
	#include "LinkedList.h"
	#include <stddef.h>


	struct TreeNode {
		TreeNode* left;
		TreeNode* right;
		TreeNode* parent;
		int data;
	};

	class Tree {
	private:
		void DeleteTreeHelper(TreeNode* node);
		TreeNode* CreateBSTTreeNode(int* list, int start, int end, TreeNode* parent  );
		void InOrderTraversalHelper(TreeNode* node);
		void CreateArrayOfLinkedListsForEachLevelOfTreeHelper( LinkedList<int>* arrayList, int level, TreeNode* node );
		int GetMaxHeight(TreeNode* node);
		int GetMinHeight(TreeNode* node);
		TreeNode* GetCommonAncestorHelper( TreeNode* root, TreeNode* p, TreeNode* q );
		int NumberOfNodesCoveredByRoot( TreeNode* root, TreeNode* p, TreeNode* q );
	public:
		TreeNode* root;
		Tree() : root(NULL) {}
		~Tree();

		bool IsBalanced();
		int GetHeight() { return GetMaxHeight(root); }
		void CreateBSTFromSortedList(int* list, int n);
		void InOrderTraversal();
		LinkedList<int>* CreateArrayOfLinkedListsForEachLevelOfTree();
		TreeNode* GetInOrderSuccessor( TreeNode* node );
		TreeNode* GetCommonAncsestor( TreeNode* p, TreeNode* q );
	};
#endif