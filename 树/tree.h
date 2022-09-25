#pragma once
#include <iostream>

// ��������˳��洢
typedef int ElemType;
// �������ڵ���
constexpr auto MaxSize = 32;
// ˳��洢�ṹ��
struct TreeNode
{
	ElemType value;
	bool isEmpty;
};
// ��ʽ�洢�Ľṹ��
typedef struct BiTreeNode
{
	ElemType data;
	BiTreeNode* lchild, * rchild;
}BiTreeNode, * BiTree;

// ����һ�����ʽڵ�ķ������˴��Ǵ�ӡ�ڵ��ֵ
void visit(BiTree& node);

// �������
void preOrder(BiTree& tree);

// �������
void inOrder(BiTree& tree);

// �������
void postOrder(BiTree& tree);

// �������
void levelOrder(BiTree& tree);

// ��ȡ�������/�߶�
int getTreeDepth(BiTree& tree);