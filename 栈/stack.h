#pragma once

#define ElemType int
#define MaxSize 32

//	ջ
typedef struct Stack {
	ElemType data[MaxSize];	//	���ջ�е�Ԫ��
	int top;				//	ջ��ָ��
}Stack;

//	����ջ
typedef struct SharedStack {
	ElemType data[MaxSize];
	int top0, top1;
}SharedStack;

//	��ջ
typedef struct LinkStackNode {
	ElemType data;
	struct LinkStackNode* next;
}LinkStackNode, * LinkStackList;