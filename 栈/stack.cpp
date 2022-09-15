// 栈的顺序存储的实现，这里设计的栈是从1开始的
#include <cstdio>
#include <cstdlib>
#include "stack.h"

// 初始化栈
void InitStack(Stack& stack) {
	// 初始化栈顶指针
	stack.top = -1;
}

void InitStack(SharedStack& stack) {
	stack.top0 = -1;
	stack.top1 = MaxSize;
}

// 判空
bool isEmpty(Stack stack) {
	return stack.top = -1;
}

// 判断栈是否满了
bool isFull(Stack stack) {
	return stack.top == MaxSize - 1;
}

bool isFull(SharedStack& stack) {
	return stack.top0 + 1 == stack.top1;
}

// 进栈
bool Push(Stack& stack, ElemType data) {
	if (isFull(stack))
	{
		return false;
	}
	stack.top = stack.top + 1;
	stack.data[stack.top] = data;
	// 上面两句等价于 stack.data[++(stack.top)] = data;
	return true;
}

// 出栈
ElemType Pop(Stack& stack) {
	if (isEmpty(stack))
	{
		return NULL;
	}
	ElemType data = stack.data[stack.top];
	stack.top = stack.top - 1;
}

// 读取栈顶元素
ElemType GetTop(Stack& stack) {
	if (isEmpty(stack))
	{
		return NULL;
	}
	return stack.data[stack.top];
}