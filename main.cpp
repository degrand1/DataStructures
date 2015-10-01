#include "LinkedList.h"

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

int main()
{
	TestLinkedList();
	return 0;
}