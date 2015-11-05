#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
	#include <stddef.h>
	
	#include <iostream>
	#include <limits.h>
	using namespace std;

	template<class Data>
	struct DoublyLinkedNode {
		Data data;
		DoublyLinkedNode* next;
		DoublyLinkedNode* prev;
		DoublyLinkedNode(Data Value): data(Value), next(NULL), prev(NULL){}
	};

	template<>
	struct DoublyLinkedNode<int> {
		int data;
		int minValue;
		DoublyLinkedNode* min;
		DoublyLinkedNode* next;
		DoublyLinkedNode* prev;
		DoublyLinkedNode(int Value): data(Value), next(NULL), prev(NULL), minValue(INT_MAX), min(NULL) {}
	};

	template<class Data>
	class DoublyLinkedList {
	private:
		DoublyLinkedNode<Data>* head;
		DoublyLinkedNode<Data>* tail;
		int size;
	public:
	
		DoublyLinkedList(): head(NULL), tail(NULL), size(0) {}
		~DoublyLinkedList();
	
		void AddElement( Data Value );
		//Removes the specified element from the list
		void RemoveElement( Data Value );
		//Pops the last element of the list
		DoublyLinkedNode<Data>* PopTail();
		DoublyLinkedNode<Data>* GetTail() { return tail; }
		int GetSize() { return size; }
		void PrintListForwards();
		void PrintListBackwards();
		bool IsEmpty();
	};

	template<class Data>
	DoublyLinkedList<Data>::~DoublyLinkedList()
	{
		DoublyLinkedNode<Data>* Current = head;
		while( Current != NULL )
		{
			head = head->next;
			delete Current;
			Current = head;
		}
		size = 0;
	}

	template<class Data>
	void DoublyLinkedList<Data>::AddElement(Data Value )
	{
		DoublyLinkedNode<Data>* NewNode = new DoublyLinkedNode<Data>(Value);
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
			DoublyLinkedNode<Data>* Temp = tail;
			tail = tail->next;
			tail->prev = Temp;
		}
		size++;
	}

	//Removes the specified element from the list
	template<class Data>
	void DoublyLinkedList<Data>::RemoveElement( Data Value )
	{
		DoublyLinkedNode<Data>* Current = head;
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
					DoublyLinkedNode<Data>* Prev = Current->prev;
					DoublyLinkedNode<Data>* Next = Current->next;
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

	template<class Data>
	void DoublyLinkedList<Data>::PrintListForwards()
	{
		DoublyLinkedNode<Data>* Current = head;
		while( Current != NULL )
		{
			cout << Current->data << " ";
			Current = Current->next;
		}
		cout << endl;
	}
	
	template<class Data>
	void DoublyLinkedList<Data>::PrintListBackwards()
	{
		DoublyLinkedNode<Data>* Current = tail;
		while( Current != NULL )
		{
			cout << Current->data << " ";
			Current = Current->prev;
		}
		cout << endl;
	}

	template<class Data>
	bool DoublyLinkedList<Data>::IsEmpty()
	{
		return head == NULL;
	}
	
	template<class Data>
	DoublyLinkedNode<Data>* DoublyLinkedList<Data>::PopTail()
	{
		DoublyLinkedNode<Data>* ReturnElement = NULL;
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