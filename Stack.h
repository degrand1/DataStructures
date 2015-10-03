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
	private:
		DoublyLinkedList<Data>* List;
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