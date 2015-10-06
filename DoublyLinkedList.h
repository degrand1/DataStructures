#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
	#include <stddef.h>
	
	#include <iostream>
	#include <limits.h>
	using namespace std;

	struct DoublyLinkedNode {
		int data;
		int minValue;
		DoublyLinkedNode* min;
		DoublyLinkedNode* next;
		DoublyLinkedNode* prev;
		DoublyLinkedNode(int Value): data(Value), next(NULL), prev(NULL), minValue(INT_MAX), min(NULL) {}
	};

	class DoublyLinkedList {
	private:
		DoublyLinkedNode* head;
		DoublyLinkedNode* tail;
		int size;
	public:
	
		DoublyLinkedList(): head(NULL), tail(NULL), size(0) {}
		~DoublyLinkedList();
	
		void AddElement( int Value );
		//Removes the specified element from the list
		void RemoveElement( int Value );
		//Pops the last element of the list
		DoublyLinkedNode* PopTail();
		DoublyLinkedNode* GetTail() { return tail; }
		int GetSize() { return size; }
		void PrintListForwards();
		void PrintListBackwards();
		bool IsEmpty();
	};

	DoublyLinkedList::~DoublyLinkedList() {
		DoublyLinkedNode* Current = head;
		while( Current != NULL )
		{
			head = head->next;
			delete Current;
			Current = head;
		}
		size = 0;
	}

	void DoublyLinkedList::AddElement( int Value )
	{
		DoublyLinkedNode* NewNode = new DoublyLinkedNode(Value);
		if(head == NULL)
		{
			head = NewNode;
			tail = head;
		}
		else if(tail == head)
		{
			tail = NewNode;
			head->next = tail;
			tail->prev = head;
		}
		else
		{
			tail->next = NewNode;
			DoublyLinkedNode* Temp = tail;
			tail = tail->next;
			tail->prev = Temp;
		}
		size++;
	}

	//Removes the specified element from the list
	void DoublyLinkedList::RemoveElement( int Value )
	{
		DoublyLinkedNode* Current = head;
		while( Current != NULL )
		{
			if( Current->data == Value )
			{
				if( Current == head )
				{
					//Only one node in the list
					if( head == tail ) 
						tail = tail->next;
					head = head->next;
					head->prev = NULL;
				}
				else if( Current == tail )
				{
					if( Current->prev == head )
					{
						tail->prev = NULL;
						tail = head;
						head->next = NULL;
					}
					else
					{
						tail = tail->prev;
						tail->next = NULL;
					}
				}
				else
				{
					DoublyLinkedNode* Prev = Current->prev;
					DoublyLinkedNode* Next = Current->next;
					Prev->next = Next;
					Next->prev = Prev;
				}
				size--;
				delete Current;
				return;
			}
			Current = Current->next;
		}
		cout << "Could not find the specified element " << Value << endl;
	}

	void DoublyLinkedList::PrintListForwards()
	{
		DoublyLinkedNode* Current = head;
		while( Current != NULL )
		{
			cout << Current->data << " ";
			Current = Current->next;
		}
		cout << endl;
	}
	
	void DoublyLinkedList::PrintListBackwards()
	{
		DoublyLinkedNode* Current = tail;
		while( Current != NULL )
		{
			cout << Current->data << " ";
			Current = Current->prev;
		}
		cout << endl;
	}

	bool DoublyLinkedList::IsEmpty()
	{
		return head == NULL;
	}
	
	DoublyLinkedNode* DoublyLinkedList::PopTail()
	{
		DoublyLinkedNode* ReturnElement = NULL;
		if( head == NULL )
		{
			return NULL;
		}
		else if( tail == head )
		{
			ReturnElement = head;
			head = NULL;
			tail = NULL;
		}
		else
		{
			ReturnElement = tail;
			tail = tail->prev;
			tail->next = NULL;
		}
		size--;
		return ReturnElement;
	}

#endif