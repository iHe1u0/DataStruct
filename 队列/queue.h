#pragma once

typedef int ElemType;

// ���е�˳��ʵ��
#define MaxSize 5

typedef struct {
	ElemType data[MaxSize];	// �þ�̬����洢����Ԫ��
	int front, rear;		// ��ͷָ��Ͷ�βָ��
};
