// ջ��˳��洢��ʵ�֣�������Ƶ�ջ�Ǵ�1��ʼ��
#include <cstdio>
#include <cstdlib>
#include "stack.h"

// ��ʼ��ջ
void InitStack(Stack& stack) {
	// ��ʼ��ջ��ָ��
	stack.top = -1;
}

void InitStack(SharedStack& stack) {
	stack.top0 = -1;
	stack.top1 = MaxSize;
}

// �п�
bool isEmpty(Stack stack) {
	return stack.top = -1;
}

// �ж�ջ�Ƿ�����
bool isFull(Stack stack) {
	return stack.top == MaxSize - 1;
}

bool isFull(SharedStack& stack) {
	return stack.top0 + 1 == stack.top1;
}

// ��ջ
bool Push(Stack& stack, ElemType data) {
	if (isFull(stack))
	{
		return false;
	}
	stack.top = stack.top + 1;
	stack.data[stack.top] = data;
	// ��������ȼ��� stack.data[++(stack.top)] = data;
	return true;
}

// ��ջ
ElemType Pop(Stack& stack) {
	if (isEmpty(stack))
	{
		return NULL;
	}
	ElemType data = stack.data[stack.top];
	stack.top = stack.top - 1;
}

// ��ȡջ��Ԫ��
ElemType GetTop(Stack& stack) {
	if (isEmpty(stack))
	{
		return NULL;
	}
	return stack.data[stack.top];
}