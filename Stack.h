#ifndef STACK_H
#define STACK_H
	#include "DoublyLinkedList.h"
	
	class Stack {
	public:
		Stack(){ List = new DoublyLinkedList(); }
		~Stack();
		DoublyLinkedNode* Dequeue();
		DoublyLinkedNode* GetMin();
		void Enqueue( int Value );
	private:
		DoublyLinkedList* List;
	};
	
	Stack::~Stack() {
		if( List != NULL )
		{
			delete List;
			List = NULL;
		}
	}
	
	void Stack::Enqueue( int Value )
	{
		DoublyLinkedNode* prevTail = List->GetTail();
		int prevMin = prevTail != NULL ? prevTail->minValue : INT_MAX;
		DoublyLinkedNode* prevMinNode = prevTail != NULL ? prevTail->min : NULL;
		List->AddElement(Value);
		DoublyLinkedNode* node = List->GetTail();
		node->minValue = prevMin < Value ? prevMin : Value;
		node->min = prevMin < Value ? prevMinNode : node;
	}
	
	DoublyLinkedNode* Stack::Dequeue()
	{
		return List->IsEmpty() ? NULL : List->PopTail();
	}

	DoublyLinkedNode* Stack::GetMin()
	{
		DoublyLinkedNode* tail = List->GetTail();
		return tail != NULL ? tail->min : NULL;
	}
	
#endif