#pragma once

typedef int ElemType;

#define MaxSize 50

// 队列的顺序实现
typedef struct {
	ElemType data[MaxSize]; // 用静态数组存储队列元素
	int front, rear;        // 队头指针和队尾指针
}SeqQueue;


// 队列的链式实现
// 双端队列可以看做是一种特殊的链式队列
typedef struct LinkNode {
	ElemType data;          // 存储数据
	LinkNode* next;         // 存储下一个节点的地址
}LinkNode;
typedef struct {
	LinkNode* front, * rear;// 队首和队尾指针
}LinkQueue;

// 初始化队列
void InitQueue(SeqQueue& queue);
void InitQueue(LinkQueue& queue);

// 队列判空
bool isEmpty(SeqQueue queue);
bool isEmpty(LinkQueue& queue);

// 队列是否满了
bool isFull(SeqQueue queue);

// 入队
bool EnQueue(SeqQueue& queue, ElemType data);
bool EnQueue(LinkQueue& queue, ElemType data);

// 出队
ElemType DeQueue(SeqQueue& queue);
ElemType DeQueue(LinkQueue& queue);

// 获取队头的值
ElemType GetFront(SeqQueue queue);
ElemType GetFront(LinkQueue queue);
