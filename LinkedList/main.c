#include <stdlib.h>
#include <stdio.h>

#define ElemType int

typedef struct LinkListNode {
	ElemType data;
	struct LNode* pNext;
} LNode, *LinkList;

int main() {
	LinkList list = (LNode*)malloc(sizeof(LNode));
	list->data = 0;
	list->pNext = NULL;

	getchar();
	return 0;
}