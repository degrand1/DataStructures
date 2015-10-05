#ifndef LINKEDLIST_H
#define LINKEDLIST_H
	#include <stddef.h>
	#include <map>

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
		int size;
	public:
	
		LinkedList(): head(NULL), tail(NULL), size(0) {}
		~LinkedList();
	
		int GetSize() { return size; }
		Node<Data>* GetHead() { return head; }
		Node<Data>* GetTail() { return tail; }
		void AddElement( Data Value );
		//Removes the specified element from the list
		void RemoveElement( Data Value );
		void RemoveIthElement( int i );
		//Pops the last element of the list
		//This function could take O(n) time, so it would be better to use a doubly linked list if this function is needed
		Node<Data>* PopTail();
		//Pops the first element of the list
		Node<Data>* PopHead();
		//Returns the ith element in the list
		Node<Data>* FindElement( int i );
		Node<Data>* FindNthFromLastElement( int i );
		//Uses O(n) space to remove duplicates from a buffer in O(n) time
		void RemoveDuplicatesUsingBuffer();
		//Uses O(1) space to remove duplicates from a buffer in O(n^2) time
		void RemoveDuplicatesWithoutBuffer();
		//Will be O(n) if the tail is passed in, O(1) otherwise
		bool RemoveNode( Node<Data>* node );
		void PrintList();
		bool IsEmpty();
		bool IsListCircular( Node<Data>* &LoopBeginning );
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
		size = 0;
	}

	template<class Data>
	void LinkedList<Data>::AddElement( Data Value )
	{
		Node<Data>* NewNode = new Node<Data>(Value);
		if(head == NULL)
		{
			head = NewNode;
			tail = NewNode;
		}
		else if(tail == head)
		{
			tail = NewNode;
			head->next = tail;
		}
		else
		{
			tail->next = NewNode;
			tail = tail->next;
		}
		size++;
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
					//Only one element in the list
					if(tail == head )
						tail = tail->next;
					head = head->next;
				}
				else if( Current == tail )
				{
					if( Prev == head )
					{
						tail = head;
						head->next = NULL;
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
				size--;
				delete Current;
				return;
			}
			Prev = Current;
			Current = Current->next;
		}
		cout << "Could not find the specified element " << Value << endl;
	}

	template<class Data>
	void LinkedList<Data>::RemoveIthElement( int i )
	{
		Node<Data>* Current = head;
		Node<Data>* Prev = NULL;
		int count = 0;
		while( Current != NULL )
		{
			if( count == i )
			{
				if( Current == head )
				{
					//Only one element in the list
					if(tail == head )
						tail = tail->next;
					head = head->next;
				}
				else if( Current == tail )
				{
					if( Prev == head )
					{
						tail = head;
						head->next = NULL;
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
				size--;
				delete Current;
				return;
			}
			Prev = Current;
			Current = Current->next;
			count++;
		}
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
		return NULL;
	}

	template<class Data>
	Node<Data>* LinkedList<Data>::FindNthFromLastElement( int i )
	{
		int elementToFind = size - i - 1;
		return FindElement( elementToFind );
	}

	template<class Data>
	void LinkedList<Data>::RemoveDuplicatesUsingBuffer()
	{
		map<Data, int> hashTable;
		map<Data, int>::iterator it;
		Node<Data>* Current = head;
		int count = 0;
		while( Current != NULL )
		{
			Data data = Current->data;
			Current = Current->next; //Advance this pointer now incase it gets deleted
			it = hashTable.find(data);
			if( it != hashTable.end() ) //If we found a duplicate
				RemoveIthElement( count );
			else
			{
				hashTable.insert( pair<Data, int>(data, 1) );
				count++;
			}
			
		}
	}

	template<class Data>
	void LinkedList<Data>::RemoveDuplicatesWithoutBuffer()
	{
		Node<Data>* Current = head;
		int count = 0;
		while( Current != NULL )
		{
			Data CurrentData = Current->data;
			Node<Data>* SecondIterator = Current->next;
			int secondCount = count+1;
			while( SecondIterator != NULL )
			{
				Data SecondData = SecondIterator->data;
				SecondIterator = SecondIterator->next;
				if( CurrentData == SecondData )
					RemoveIthElement( secondCount );
				else
					secondCount++;
			}
			Current = Current->next;
			count++;
		}
	}

	template<class Data>
	bool LinkedList<Data>::RemoveNode( Node<Data>* node )
	{
		if( node == NULL || (node != tail && node->next == NULL ) ) return false;
		Node<Data>* nodeToDelete;
		if( node == head )
		{
			nodeToDelete = PopHead();
		}
		else if( node == tail ) //Will be O(n) time
		{
			nodeToDelete = PopTail();
		}
		else
		{
			Node<Data>* nextNode = node->next;
			node->data = nextNode->data;
			node->next = nextNode->next;
			nodeToDelete = nextNode;
		}
		delete nodeToDelete;
		return true;
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
	
	template<class Data>
	bool LinkedList<Data>::IsEmpty()
	{
		return head == NULL;
	}
	
	template<class Data>
	Node<Data>* LinkedList<Data>::PopTail()
	{
		Node<Data>* ReturnElement = NULL;
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
			Node<Data>* Temp = head;
			while( Temp != NULL && Temp->next != tail )
				Temp = Temp->next;
			tail = Temp == head ? NULL : Temp;
			tail->next = NULL;
		}
		size--;
		return ReturnElement;
	}
	
	template<class Data>
	Node<Data>* LinkedList<Data>::PopHead()
	{
		Node<Data>* ReturnElement = NULL;
		if( head == NULL )
		{
			return NULL;
		}
		else if( head == tail )
		{
			ReturnElement = head;
			head = NULL;
			tail = NULL;
		}
		else
		{
			ReturnElement = head;
			head = head->next;
		}
		size--;
		return ReturnElement;
	}

	template<class Data>
	bool LinkedList<Data>::IsListCircular( Node<Data>* &LoopBeginning )
	{
		Node<Data>* tortoise = head;
		Node<Data>* hare = head;
		//Find the meeting point
		while( hare->next != NULL )
		{
			tortoise = tortoise->next;
			hare = hare->next->next;
			if( tortoise == hare ) break;
		}

		if( hare == NULL )
		{
			LoopBeginning = NULL;
			return false;
		}

		//Put the tortoise back at the start. Both animals are k steps away from the beginning of the loop, so advance both of them until they meet
		tortoise = head;
		while( tortoise != hare )
		{
			tortoise = tortoise->next;
			hare = hare->next;
		}
		LoopBeginning = tortoise;
		return true;
	}

#endif