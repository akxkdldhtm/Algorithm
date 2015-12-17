#include "Graph.h"

Graph* CreateGraph()
{
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->Vertices = NULL;
	graph->VertexCount = 0;
	return graph;
}

void DestroyGraph(Graph* G)
{
	while (G->Vertices != NULL)
	{
		Vertex* Vertices = G->Vertices->Next;
		DestroyVertex(G->Vertices);
		G->Vertices = Vertices;
	}

	free(G);
}

Vertex* CreateVertex(ElementType Data)
{
	Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
	vertex->Data = Data;
	vertex->AdjacencyList = NULL;
	vertex->index = -1;
	vertex->Next = NULL;
	vertex->nVisited = NotVisited;

	return vertex;
}

void DestroyVertex(Vertex* V) //������ �༮���� �� ���ִµ�
{
	while (V->AdjacencyList != NULL)
	{
		Edge* Edge = V->AdjacencyList->Next;	//V���� ����� �༮����� ����
		DestroyEdge(V->AdjacencyList);
		V->AdjacencyList = Edge;
	}

	free(V);
}

Edge* CreateEdge(Vertex* From, Vertex* Target, int Weight)
{
	Edge* edge = (Edge*)malloc(sizeof(Edge));
	edge->From = From;
	edge->Target = Target;
	edge->Weight = Weight;
	edge->Next = NULL;  // Edge�� Next��..����
	
	return edge;


}

void DestroyEdge(Edge* E)
{
	free(E);
}

void AddVertex(Graph* G, Vertex* V)
{
	//G���� �ִ� ����߿��� ���� �־�߰���?

	Vertex* VertexList = G->Vertices;

	if (VertexList == NULL)
	{
		G->Vertices = V;
	}
	else
	{
		while (VertexList->Next != NULL)
			VertexList = VertexList->Next;

		VertexList->Next = V;
	}

	V->index = G->VertexCount++;
}

void AddEdge(Vertex* V, Edge* E)
{
	if (V->AdjacencyList == NULL)
		V->AdjacencyList = E;
	else
	{
		Edge* e = V->AdjacencyList;
		while (e->Next != NULL)
			e = e->Next;

		e->Next = E;
	}
}

void PrintGraph(Graph* G)
{
	Vertex* V = NULL;
	Edge*   E = NULL;

	if ((V = G->Vertices) == NULL)
		return;

	while (V != NULL)
	{
		printf("%c : ", V->Data);

		if ((E = V->AdjacencyList) == NULL){ //���� Edge�� ������ ���� Vertex
			V = V->Next;
			printf("\n");
			continue;
		}

		while (E != NULL){
			printf("%c[%d]", E->Target->Data, E->Weight);
			E = E->Next;
		}

		printf("\n");

		V = V->Next; 
	}

	printf("\n");
}
