#include "GraphTraversal.h"

void DFS(Vertex* V)
{
	Edge* E = NULL;

	printf("%d", V->Data);

	V->nVisited = Visited;

	E = V->AdjacencyList;

	while (E != NULL)
	{
		if (E->Target != NULL && E->Target->nVisited == NotVisited)
			DFS(E->Target);

		E = E->Next;
	}


}

void BFS(Vertex* V, LinkedQueue* Queue)
{
	Edge* E = NULL;

	printf("%d", V->Data);
	V->nVisited = Visited;

	LQ_EnQueue(Queue, LQ_CreateNode(V->Data));

	while (!LQ_IsEmpty(Queue))
	{
		Node* Popped = LQ_DeQueue(Queue);
		V = Popped->Data;
		E = V->AdjacencyList;

		while (E != NULL)
		{
			V = E->Target;

			if (V != NULL && V->nVisited == NotVisited)
			{
				printf("%d", V->Data);
				V->nVisited = Visited;
				LQ_EnQueue(Queue, LQ_CreateNode(V->Data));
			}

			E = E->Next;
		}
	}
}