#include "LinkedList.h"

#include <iostream>
using namespace std;

int main()
{
	const int size = 4;
	LinkedList<int> List;
	for(int i = 0; i < size; i++)
	{
		List.AddElement(i);
	}
	List.PrintList();
	
	return 0;
}