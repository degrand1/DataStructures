#ifndef GRAPH_H
#define GRAPH_H
	#include "LinkedList.h"

	struct GraphNode {
		bool Visited;
		LinkedList<GraphNode*>* neighbors;
		GraphNode() : Visited(false) { neighbors = new LinkedList<GraphNode*>(); }
		~GraphNode() { delete neighbors; }
	};

	class Graph {
	public:
		Graph() { allNodes = new LinkedList<GraphNode*>(); }
		~Graph() { delete allNodes; }

		bool DoesPathBetweenNodesExist_BFS( GraphNode* startNode, GraphNode* endNode );
		void AddNode( GraphNode* node );
		void ConnectNodeAToNodeB( GraphNode* A, GraphNode* B );
	private:
		LinkedList<GraphNode*>* allNodes;
	};
#endif