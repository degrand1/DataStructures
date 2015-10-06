#include "Graph.h"
#include "Queue.h"

bool Graph::DoesPathBetweenNodesExist_BFS( GraphNode* startNode, GraphNode* endNode )
{
	Queue<GraphNode*> queue;
	Node<GraphNode*>* Current = allNodes->GetHead();
	while( Current != NULL )
	{
		Current->data->Visited = false;
		Current = Current->next;
	}

	queue.Enqueue(startNode);
	while( !queue.IsEmpty() )
	{
		GraphNode* currentNode = queue.Dequeue()->data;
		if( !currentNode->Visited )
		{
			Node<GraphNode*>* currentNeighbor = currentNode->neighbors->GetHead();
			while( currentNeighbor != NULL )
			{
				if( currentNeighbor->data == endNode )
				{
					return true;
				}
				else
				{
					queue.Enqueue(currentNeighbor->data);
				}
				currentNeighbor = currentNeighbor->next;
			}
		}
		currentNode->Visited = true;
	}
	return false;
}

void Graph::AddNode( GraphNode* node )
{
	allNodes->AddElement( node );
}

void Graph::ConnectNodeAToNodeB( GraphNode* A, GraphNode* B )
{
	A->neighbors->AddElement(B);
}