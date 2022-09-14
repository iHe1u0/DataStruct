#include "stack.h"
#include <cstdio>
#include <cstdlib>

//	判空
bool isEmpty(LinkStackList stack) {
	return stack == NULL;
}

//	初始化栈
bool InitStack(LinkStackList& stack) {
	stack = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	if (stack == NULL)
	{
		return false;
	}
	stack->next = NULL;
	return true;
}

//	入栈
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
	//	构造一个节点
	LinkStackNode* node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	if (node != NULL)
	{
		node->data = data;
		node->next = NULL;
		lastNode->next = node;
	}
}

//	出栈
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