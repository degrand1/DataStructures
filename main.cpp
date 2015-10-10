#include "CCI_ArraysAndStrings.h"
#include "CCI_LinkedLists.h"
#include "DoublyLinkedList.h"
#include "Graph.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Sort.h"
#include "Stack.h"
#include "Tree.h"

#include <iostream>
using namespace std;

void TestLinkedList()
{
	const int size = 5;
	LinkedList<int> List;
	for(int i = 0; i < size; i++)
	{
		List.AddElement(i);
	}
	List.PrintList();
	//Test removing the head
	List.RemoveElement(0);
	List.PrintList();
	//Test removing the tail
	List.RemoveElement(size-1);
	List.PrintList();
	//Test removing the middle
	List.RemoveElement(2);
	List.PrintList();
	cout << "Found the element " << List.FindElement(1)->data << endl;
	for(int i = 0; i < size; i++)
	{
		List.AddElement(1);
		List.AddElement(3);
	}
	List.PrintList();
	cout << "Removing duplicates via a buffer" << endl;
	List.RemoveDuplicatesUsingBuffer();
	List.PrintList();
	for(int i = 0; i < size; i++)
	{
		List.AddElement(1);
		List.AddElement(3);
	}
	cout << "Removing duplicates without a buffer" << endl;
	List.RemoveDuplicatesWithoutBuffer();
	List.PrintList();
	for( int i = 0; i < size; i++ )
	{
		List.AddElement(i<<1);
	}
	List.PrintList();
	cout << "The last element is:" << List.FindNthFromLastElement(0)->data << endl;
	cout << "The second from last element is:" << List.FindNthFromLastElement(1)->data << endl;
	cout << "Test deleting the head" << endl;
	List.RemoveNode(List.FindElement(0));
	List.PrintList();
	cout << "Test deleting the tail" << endl;
	List.RemoveNode(List.FindNthFromLastElement(0));
	List.PrintList();
	cout << "Test deleting a middle node" << endl;
	List.RemoveNode(List.FindElement( (List.GetSize()-1)>>1) );
	List.PrintList();
	LinkedList<int> CircularList;
	for(int i = 0; i < size; i++ )
	{
		CircularList.AddElement(i);
	}
	CircularList.FindNthFromLastElement(0)->next = CircularList.FindElement( CircularList.GetSize()>>1 );
	Node<int>* LoopBeginning = NULL;
	if( CircularList.IsListCircular( LoopBeginning ) )
		cout << "The beginning of the circular list is: " << LoopBeginning->data << endl;
	else
		cout << "Incorrectly believe that a circular list is not circular." << endl;
	CircularList.GetTail()->next = NULL;
}

void TestDoublyLinkedList()
{
	const int size = 5;
	DoublyLinkedList List;
	for(int i = 0; i < size; i++)
	{
		List.AddElement(i);
	}
	List.PrintListForwards();
	List.PrintListBackwards();
	cout << "Test removing the head" << endl;
	List.RemoveElement(0);
	List.PrintListForwards();
	List.PrintListBackwards();
	cout << "Test popping the tail" << endl;
	List.PopTail();
	List.PrintListForwards();
	List.PrintListBackwards();
	cout << "Test adding and removing the tail" << endl;
	List.AddElement(size-1);
	List.RemoveElement(size-1);
	List.PrintListForwards();
	List.PrintListBackwards();
	cout << "Test removing the middle" << endl;
	List.RemoveElement(2);
	List.PrintListForwards();
	List.PrintListBackwards();
	cout << "Test popping everything, and then adding it back in" << endl;
	List.PopTail();
	List.PopTail();
	for(int i = 0; i < size; i++)
	{
		List.AddElement(i);
	}
	List.PrintListForwards();
	List.PrintListBackwards();
}

void TestStack()
{
	const int size = 5;
	Stack stack;
	//test dequeueing from an empty stack
	if( stack.Dequeue() != NULL )
		cout << "Dequeuing from an empty stack failed" << endl;
	else
		cout << "Dequeuing form an empty stack passed" << endl;
	for(int i = 0; i < size; i++ )
		stack.Enqueue(size-i);
	for(int i = 0; i < size; i++ )
		stack.Enqueue(i);
	for(int i = 0; i < size<<1; i++ )
	{
		DoublyLinkedNode* node = stack.Dequeue();
		if( node == NULL )
		{
			cout << "Somehow got an empty node" << endl;
			break;
		}
		cout << "The " << i << "th element of the stack is: " << node->data << endl;
		cout << "The minimum node of the stack is: " << node->min->data << endl; 
		delete node;
	}
}

void TestQueue()
{
	const int size = 5;
	Queue<int> queue;
	//test dequeueing from an empty queue
	if( queue.Dequeue() != NULL )
		cout << "Dequeuing from an empty queue failed" << endl;
	else
		cout << "Dequeuing form an empty queue passed" << endl;
	for(int i = 0; i < size; i++ )
		queue.Enqueue(i);
	for(int i = 0; i < size; i++ )
	{
		Node<int>* node = queue.Dequeue();
		if( node == NULL )
		{
			cout << "Somehow got an empty node" << endl;
			break;
		}
		cout << "The " << i << "th elemnt of the stack is: " << node->data << endl;
		delete node;
	}
}

void TestGraph()
{
	Graph graph;
	GraphNode a, b, c, d, e, f;
	graph.AddNode(&a); graph.AddNode(&b); graph.AddNode(&c); graph.AddNode(&d); graph.AddNode(&e); graph.AddNode(&f);
	graph.ConnectNodeAToNodeB(&a, &b); graph.ConnectNodeAToNodeB(&b, &c); graph.ConnectNodeAToNodeB(&c, &d); graph.ConnectNodeAToNodeB(&d, &e); graph.ConnectNodeAToNodeB(&e, &f);
	graph.ConnectNodeAToNodeB(&c, &a); graph.ConnectNodeAToNodeB(&d, &f); graph.ConnectNodeAToNodeB(&c, &b); graph.ConnectNodeAToNodeB(&b, &d); graph.ConnectNodeAToNodeB(&e, &b);
	if( graph.DoesPathBetweenNodesExist_BFS(&a, &f) )
		cout << "Found the path betweeen a and f" << endl;
	else
		cout << "Could not find the path between a and f" << endl;
}

void TestTree()
{
	Tree tree;
	const int size = 7;
	int array[size];
	for(int i = 0; i < size; i++ )
	{
		array[i] = i;
	}
	tree.CreateBSTFromSortedList(array, size);
	tree.InOrderTraversal();
	LinkedList<int>* arrayList = tree.CreateArrayOfLinkedListsForEachLevelOfTree();
	int numLevels = tree.GetHeight();
	for(int i = 0; i < numLevels; i++ )
	{
		arrayList[i].PrintList();
	}
	TreeNode* TheNumberTwo = tree.root->left->right;
	TreeNode* TheNumberZero = tree.root->left->left;
	TreeNode* TheNumberOne = tree.root->left;
	TreeNode* TheNumberThree = tree.root;
	TreeNode* TheNumberFive = tree.root->right;
	TreeNode* TheNumberFour = tree.root->right->left;
	cout << "The value for the number two is:" << TheNumberTwo->data << endl;
	cout << "The value for the number three is:" << TheNumberThree->data << endl;
	cout << "The value for the number zero is:" << TheNumberZero->data << endl;
	cout << "The value for the number four is:" << TheNumberFour->data << endl;
	cout << "The value for the number five is:" << TheNumberFive->data << endl;
	cout << "The value for the number one is:" << TheNumberOne->data << endl;
	cout << "The first common ancestory of 2 and 4 is:" << tree.GetCommonAncsestor( TheNumberTwo, TheNumberFour )->data << endl;
	if( tree.DoesTreeOneContainTreeTwo( tree.root, TheNumberFive ) )
		cout << "Passed the test for finding subtrees" << endl;
	else
		cout << "Failed the test for finding subtrees" << endl;
	LinkedList<int> buffer;
	tree.PrintPathsInTreeThatSumToValue( tree.root, buffer, 6, 0 );
}

static void printArray(int *array, int n)
{
	for(int i = 0; i < n; i++ )
		cout << array[i] << " ";
	cout << endl;
}

void TestSort()
{
	const int size = 8;
	int array[size];
	for( int i = 0; i < size; i++ )
	{
		array[i] = size - i - 1;
	}
	printArray( array, size );
	QuickSort( array, size );
	printArray( array, size );

}

int main()
{
	//TestLinkedList();
	//TestDoublyLinkedList();
	//TestStack();
	//TestQueue();
	//TestGraph();
	//TestTree();
	TestSort();
	//CCI_Test_ArraysAndStrings();
	//CCI_Test_LinkedLists();
	system("pause");
	return 0;
}