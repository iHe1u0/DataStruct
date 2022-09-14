#include "stack.h"
#include <cstdio>
#include <cstdlib>

//	�п�
bool isEmpty(LinkStackList stack) {
	return stack == NULL;
}

//	��ʼ��ջ
bool InitStack(LinkStackList& stack) {
	stack = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	if (stack == NULL)
	{
		return false;
	}
	stack->next = NULL;
	return true;
}

//	��ջ
void Push(LinkStackList& stack, ElemType data) {
	if (stack == NULL)
	{
		return;
	}
	LinkStackNode* lastNode = stack;
	while (lastNode->next != NULL)
	{
		lastNode = lastNode->next;
	}
	//	����һ���ڵ�
	LinkStackNode* node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	if (node != NULL)
	{
		node->data = data;
		node->next = NULL;
		lastNode->next = node;
	}
}

//	��ջ
ElemType Pop(LinkStackList& stack) {
	if (stack == NULL)
	{
		return NULL;
	}
	LinkStackNode* priorNode = stack;
	LinkStackNode* currentNode = priorNode->next;
	while (currentNode->next != NULL)
	{
		priorNode = priorNode->next;
		currentNode = priorNode->next;
	}
	ElemType data = currentNode->data;
	free(currentNode);
	priorNode->next = NULL;
	return data;
}

int main() {
	LinkStackList stack;
	InitStack(stack);
	for (int i = 0; i < 5; i++)
	{
		Push(stack, i);
	}

	for (int i = 0; i < 5; i++)
	{
		Pop(stack);
	}
	return 0;
}