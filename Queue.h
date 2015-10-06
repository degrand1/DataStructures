#ifndef QUEUE_H
#define QUEUE_H
	#include "LinkedList.h"
	template<class Data>
	class Queue {
	public:
		Queue(){ List = new LinkedList<Data>(); }
		~Queue();
		Node<Data>* Dequeue();
		void Enqueue( Data Value );
		bool IsEmpty() { return List->IsEmpty(); }
	private:
		LinkedList<Data>* List;
	};
	
	template<class Data>
	Queue<Data>::~Queue() {
		if( List != NULL )
		{
			delete List;
			List = NULL;
		}
	}
	
	template<class Data>
	void Queue<Data>::Enqueue( Data Value )
	{
		List->AddElement(Value);
	}
	
	template<class Data>
	Node<Data>* Queue<Data>::Dequeue()
	{
		return List->IsEmpty() ? NULL : List->PopHead();
	}
	
#endif