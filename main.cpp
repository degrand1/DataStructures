#include "LinkedList.h"
#include "Stack.h"

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
}

void TestStack()
{
	const int size = 5;
	Stack<int> stack;
	//test dequeueing from an empty stack
	if( stack.Dequeue() != NULL )
		cout << "Dequeuing from an empty stack failed" << endl;
	else
		cout << "Dequeuing form an empty stack passed" << endl;
	for(int i = 0; i < size; i++ )
		stack.Enqueue(i);
	for(int i = 0; i < size; i++ )
	{
		Node<int>* node = stack.Dequeue();
		if( node == NULL )
		{
			cout << "Somehow got an empty node" << endl;
			break;
		}
		cout << "The " << i << "th elemnt of the stack is: " << node->data << endl;
		delete node;
	}
}

int main()
{
	//TestLinkedList();
	TestStack();
	return 0;
}