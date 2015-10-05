#include "CCI_LinkedLists.h"
#include "LinkedList.h"

#include <iostream>
using namespace std;

static void CCI_Test_Question2_4();

static LinkedList<int>* Question2_4_SumUpTwoLinkedLists( LinkedList<int>* List1, LinkedList<int>* List2 );

void CCI_Test_LinkedLists()
{
	CCI_Test_Question2_4();
}

static void CCI_Test_Question2_4()
{
	LinkedList<int> List1;
	List1.AddElement(3);
	List1.AddElement(1);
	List1.AddElement(5);

	LinkedList<int> List2;
	List2.AddElement(5);
	List2.AddElement(9);
	List2.AddElement(4);

	LinkedList<int>* List3 = Question2_4_SumUpTwoLinkedLists(&List1, &List2);
	List3->PrintList();
	delete List3;
}

static LinkedList<int>* Question2_4_SumUpTwoLinkedLists( LinkedList<int>* List1, LinkedList<int>* List2 )
{
	LinkedList<int>* returnList = new LinkedList<int>();
	int carryOver = 0; //Amount carried over from the previous addition;
	int currentSum = 0;
	bool List1IsLonger = List1->GetSize() > List2->GetSize();
	Node<int>* iteratorList = List1IsLonger ? List1->GetHead() : List2->GetHead();
	Node<int>* secondaryList = List1IsLonger ? List2->GetHead() : List1->GetHead();
	while( iteratorList != NULL )
	{
		currentSum = iteratorList->data + (secondaryList != NULL ? secondaryList->data : 0) + carryOver;
		if( currentSum >= 10 )
		{
			currentSum -= 10;
			carryOver = 1;
		}
		else
		{
			carryOver = 0;
		}
		returnList->AddElement(currentSum);
		iteratorList = iteratorList->next;
		if( secondaryList != NULL )
			secondaryList = secondaryList->next;
	}
	if( carryOver == 1 )
		returnList->AddElement( carryOver );
	return returnList;
}