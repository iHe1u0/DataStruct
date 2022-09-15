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
	queue.rear->next = node; // 将新节点插入到旧的表尾 rear 之后
	queue.rear = node;       // 修改表尾指针，指向新的表尾节点
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
	LinkNode* node = queue.front->next; // 旧的队头节点
	ElemType data = node->data;         // 存储数据
	queue.front->next = node->next;     // 修改队头节点，指向下一个节点
	if (queue.rear == node)             // 若此次出队是队列中的最后一个节点
	{
		queue.rear = queue.front;       // 修改 rear 指针，使其变成空队列
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
