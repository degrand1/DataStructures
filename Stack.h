#ifndef STACK_H
#define STACK_H
	#include "DoublyLinkedList.h"

	template<class Data>
	class Stack {
	public:
		Stack(){ List = new DoublyLinkedList<Data>(); }
		~Stack();
		DoublyLinkedNode<Data>* Dequeue();
		void Enqueue( Data Value );
		bool IsEmpty() { return List->IsEmpty(); }
	private:
		DoublyLinkedList<Data>* List;
	};
	
	template<>
	class Stack<int> {
	public:
		Stack(){ List = new DoublyLinkedList<int>(); }
		~Stack()
		{
			if( List != NULL )
			{
				delete List;
				List = NULL;
			}
		}
		DoublyLinkedNode<int>* Dequeue()
		{
			return List->IsEmpty() ? NULL : List->PopTail();
		}

		void Enqueue( int Value )
		{
			DoublyLinkedNode<int>* prevTail = List->GetTail();
			int prevMin = prevTail != NULL ? prevTail->minValue : INT_MAX;
			DoublyLinkedNode<int>* prevMinNode = prevTail != NULL ? prevTail->min : NULL;
			List->AddElement(Value);
			DoublyLinkedNode<int>* node = List->GetTail();
			node->minValue = prevMin < Value ? prevMin : Value;
			node->min = prevMin < Value ? prevMinNode : node;
		}
		DoublyLinkedNode<int>* GetMin()
		{
			DoublyLinkedNode<int>* tail = List->GetTail();
			return tail != NULL ? tail->min : NULL;
		}

		bool IsEmpty() { return List->IsEmpty(); }
	private:
		DoublyLinkedList<int>* List;
	};

	template<class Data>
	Stack<Data>::~Stack() {
		if( List != NULL )
		{
			delete List;
			List = NULL;
		}
	}
	
	template<class Data>
	void Stack<Data>::Enqueue( Data Value )
	{
		List->AddElement(Value);
	}
	
	template<class Data>
	DoublyLinkedNode<Data>* Stack<Data>::Dequeue()
	{
		return List->IsEmpty() ? NULL : List->PopTail();
	}
	
#endif