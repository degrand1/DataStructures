#ifndef STACK_H
#define STACK_H
	#include "LinkedList.h"
	template<class Data>
	class Stack {
	public:
		Stack(){ List = new LinkedList<Data>(); }
		~Stack();
		Node<Data>* Dequeue();
		void Enqueue( Data Value );
	private:
		LinkedList<Data>* List;
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
	Node<Data>* Stack<Data>::Dequeue()
	{
		return List->IsEmpty() ? NULL : List->PopTail();
	}
	
#endif