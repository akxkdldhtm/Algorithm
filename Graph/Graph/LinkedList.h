#include <stdio.h>
#include <stdlib.h>

#ifndef  LINKEDLIST_H
#define  LINKEDLIST_H


typedef struct tagNode
{
	int Data;
	struct tagNode* pNextNode;
}Node;

typedef struct tagLinkedList
{
	Node* head;
}LK_List;

void CreateList(LK_List** pList);
void DestroyList(LK_List* pList);

Node* CreateNode(int Data);
void DeleteNode(Node* pNode);

void AddNode(LK_List* pList,Node* pNode);


#endif