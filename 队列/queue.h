#pragma once

typedef int ElemType;

#define MaxSize 50

// ���е�˳��ʵ��
typedef struct {
	ElemType data[MaxSize]; // �þ�̬����洢����Ԫ��
	int front, rear;        // ��ͷָ��Ͷ�βָ��
}SeqQueue;


// ���е���ʽʵ��
// ˫�˶��п��Կ�����һ���������ʽ����
typedef struct LinkNode {
	ElemType data;          // �洢����
	LinkNode* next;         // �洢��һ���ڵ�ĵ�ַ
}LinkNode;
typedef struct {
	LinkNode* front, * rear;// ���׺Ͷ�βָ��
}LinkQueue;

// ��ʼ������
void InitQueue(SeqQueue& queue);
void InitQueue(LinkQueue& queue);

// �����п�
bool isEmpty(SeqQueue queue);
bool isEmpty(LinkQueue& queue);

// �����Ƿ�����
bool isFull(SeqQueue queue);

// ���
bool EnQueue(SeqQueue& queue, ElemType data);
bool EnQueue(LinkQueue& queue, ElemType data);

// ����
ElemType DeQueue(SeqQueue& queue);
ElemType DeQueue(LinkQueue& queue);

// ��ȡ��ͷ��ֵ
ElemType GetFront(SeqQueue queue);
ElemType GetFront(LinkQueue queue);
