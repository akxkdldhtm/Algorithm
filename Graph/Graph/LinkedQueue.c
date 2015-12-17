

#include "LinkedQueue.h"



void  LQ_CreateQueue(LinkedQueue** Queue)
{
	(*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
	(*Queue)->Count = 0;
}
void  LQ_DestroyQueue(LinkedQueue* Queue)
{
	while (!LQ_IsEmpty(Queue))
	{
		Node* Popped = LQ_DeQueue(Queue);
		LQ_DestroyNode(Popped);
	}

	free(Queue);
}

Node* LQ_CreateNode(char* NewData)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->Data = (char*)malloc(strlen(NewData) + 1);
	strcpy_s(node->Data,strlen(NewData), NewData);

	node->NextNode = NULL;

	return node;
}
void  LQ_DestroyNode(Node* node)
{
	free(node->Data);
	free(node);
}

void  LQ_EnQueue(LinkedQueue* Queue, Node* NewNode)
{
	if (Queue->Front == NULL)
	{
		Queue->Front = NewNode;
		Queue->Rear = NewNode;
		Queue->Count++;
	}
	else
	{
		Queue->Rear->NextNode = NewNode;
		Queue->Rear = NewNode;
		Queue->Count++; 
	}
}

Node* LQ_DeQueue(LinkedQueue* Queue)
{
	Node* Front = Queue->Front;

	if (Queue->Front->NextNode == NULL)
	{
		Queue->Front = NULL;
		Queue->Rear = NULL;
	}
	else
	{
		Queue->Front = Queue->Front->NextNode;
	}

	Queue->Count--;

	return Front;
}

int   LQ_IsEmpty(LinkedQueue* Queue)
{

	return (Queue->Front == NULL);
}