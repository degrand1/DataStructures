#ifndef LINKEDLIST_H
#define LINKEDLIST_H
	#include <stddef.h>
	
	#include <iostream>
	using namespace std;
	
	template<class Data>
	class Node {
	public:
		Data data;
		Node<Data>* next;
		Node(Data Value): data(Value), next(NULL) {}
	};

	template <class Data>
	class LinkedList {
	private:
		Node<Data>* head;
		Node<Data>* tail;
	public:
	
		LinkedList(): head(NULL), tail(NULL) {}
		~LinkedList();
	
		void AddElement( Data Value );
		//Removes the specified element from the list
		void RemoveElement( Data Value );
		//Returns the ith element in the list
		Node<Data>* FindElement( int i );
		void PrintList();
	};
	
	
	template<class Data>
	LinkedList<Data>::~LinkedList() {
		Node<Data>* Current = head;
		while( Current != NULL )
		{
			head = head->next;
			delete Current;
			Current = head;
		}
	}

	template<class Data>
	void LinkedList<Data>::AddElement( Data Value )
	{
		Node<Data>* NewNode = new Node<Data>(Value);
		if(head == NULL)
		{
			head = NewNode;
		}
		else if(tail == NULL)
		{
			tail = NewNode;
			head->next = tail;
		}
		else
		{
			tail->next = NewNode;
			tail = tail->next;
		}
	}

	//Removes the specified element from the list
	template<class Data>
	void LinkedList<Data>::RemoveElement( Data Value )
	{
		Node<Data>* Current = head;
		Node<Data>* Prev = NULL;
		while( Current != NULL )
		{
			if( Current->data == Value )
			{
				if( Current == head )
				{
					head = head->next;
				}
				else if( Current == tail )
				{
					if( Prev == head )
					{
						tail = NULL;
						head->next = tail;
					}
					else
					{
						tail = Prev;
						tail->next = NULL;
					}
				}
				else
				{
					Prev->next = Current->next;
				}
				delete Current;
				return;
			}
			Prev = Current;
			Current = Current->next;
		}
		cout << "Could not find the specified element " << Value << endl;
	}


	//Returns the ith element in the list
	template<class Data>
	Node<Data>* LinkedList<Data>::FindElement( int i )
	{
		Node<Data>* Current = head;
		int count = 0;
		while( Current != NULL )
		{
			if( count == i )
				return Current;
			Current = Current->next;
			count++;
		}
		cout << "The " << i << "th element does not exist" << endl;
		return NULL;
	}

	template<class Data>
	void LinkedList<Data>::PrintList()
	{
		Node<Data>* Current = head;
		while( Current != NULL )
		{
			cout << Current->data << " ";
			Current = Current->next;
		}
		cout << endl;
	}
	
#endif