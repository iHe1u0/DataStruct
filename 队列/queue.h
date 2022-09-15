#pragma once

typedef int ElemType;

// 队列的顺序实现
#define MaxSize 5

typedef struct {
	ElemType data[MaxSize];	// 用静态数组存储队列元素
	int front, rear;		// 队头指针和队尾指针
};
