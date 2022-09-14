#pragma once

#define ElemType int
#define MaxSize 32

//	栈
typedef struct Stack {
	ElemType data[MaxSize];	//	存放栈中的元素
	int top;				//	栈顶指针
}Stack;

//	共享栈
typedef struct SharedStack {
	ElemType data[MaxSize];
	int top0, top1;
}SharedStack;

//	链栈
typedef struct LinkStackNode {
	ElemType data;
	struct LinkStackNode* next;
}LinkStackNode, * LinkStackList;