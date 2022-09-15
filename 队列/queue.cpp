#include "queue.h"
#include <cstdio>
#include <cstdlib>

int main() {
	LinkQueue queue;
	InitQueue(queue);
	for (int looper = 0; looper < MaxSize; looper++)
	{
		EnQueue(queue, looper);
	}

	while (!isEmpty(queue))
	{
		printf("data is %d\n", DeQueue(queue));
	}
	return 0;
}

void InitQueue(SeqQueue& queue)
{
	queue.front = queue.rear = 0;
}

void InitQueue(LinkQueue& queue)
{
	queue.front = queue.rear = (LinkNode*)malloc(sizeof(LinkNode));
	if (queue.front != NULL)
	{
		queue.front->next = NULL;
	}
}

bool isEmpty(SeqQueue queue)
{
	return queue.front == queue.rear;
}

bool isEmpty(LinkQueue& queue)
{
	return queue.front == queue.rear;
}

bool isFull(SeqQueue queue)
{
	return (queue.rear + 1) % MaxSize == queue.front;
}

bool EnQueue(SeqQueue& queue, ElemType data)
{
	if (isFull(queue))
	{
		return false;
	}
	queue.data[queue.rear] = data;
	queue.rear = (queue.rear + 1) % MaxSize;
	return true;
}

bool EnQueue(LinkQueue& queue, ElemType data)
{
	LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
	if (node == NULL)
	{
		return false;
	}
	node->data = data;
	node->next = NULL;
	queue.rear->next = node; // ���½ڵ���뵽�ɵı�β rear ֮��
	queue.rear = node;       // �޸ı�βָ�룬ָ���µı�β�ڵ�
}

ElemType DeQueue(SeqQueue& queue)
{
	if (queue.rear == queue.front)
	{
		return NULL;
	}
	ElemType data = queue.data[queue.front];
	queue.front = (queue.front + 1) % MaxSize;
	return data;
}

ElemType DeQueue(LinkQueue& queue)
{
	if (isEmpty(queue))
	{
		return NULL;
	}
	LinkNode* node = queue.front->next; // �ɵĶ�ͷ�ڵ�
	ElemType data = node->data;         // �洢����
	queue.front->next = node->next;     // �޸Ķ�ͷ�ڵ㣬ָ����һ���ڵ�
	if (queue.rear == node)             // ���˴γ����Ƕ����е����һ���ڵ�
	{
		queue.rear = queue.front;       // �޸� rear ָ�룬ʹ���ɿն���
	}
	free(node);
	return data;
}

ElemType GetFront(SeqQueue queue)
{
	if (isEmpty(queue))
	{
		return NULL;
	}
	return queue.data[queue.front];
}

ElemType GetFront(LinkQueue queue)
{
	if (isEmpty(queue))
	{
		return NULL;
	}
	return queue.front->next->data;
}
