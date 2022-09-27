// ���Ĵ洢�ṹ
#pragma once

typedef int ElemType;

// ˫�ױ�ʾ����˳��洢��:ÿ����㱣��ָ��˫�׵ġ�ָ�롱
// ���������������Ŀ
constexpr auto MAX_TREE_SIZE = 100;
// �����Ķ���
struct ParentTreeNode
{
	ElemType data; //����Ԫ��
	int parent;    //˫��λ����
};
//�����͵Ķ���
struct ParentTree {
	ParentTreeNode nodes[MAX_TREE_SIZE]; //˫�ױ�ʾ
	int num;                             //�����Ŀ
};

// ���ӱ�ʾ����˳��+��ʽ�洢��
// ˳��洢������㣬ÿ������б��溢������ͷָ��
struct ChildTreeNode
{
	int child;           //���ӽ���������е�λ��
	ChildTreeNode* next; //��һ������
};
struct ChildTreeBox
{
	ElemType data;
	ChildTreeNode* firstChild; //��һ������
};
struct ChildTree
{
	ChildTreeBox nodes[MAX_TREE_SIZE];
	int num, root; //������͸��ڵ��λ��
};

// �����ֵܱ�ʾ������ʽ�洢��
typedef struct CSNode
{
	ElemType data; //������
	CSNode* firstChild, * next; //��һ�����Ӻ����ֵ�ָ��
}CSNode, * CSTree;