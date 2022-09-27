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
	struct BiTreeNode* lchild, * rchild;
	// ����������־
	bool lTag, rTag;
}BiTreeNode, * BiTree;
// �����������Ľṹ��
typedef struct ThreadNode
{
	ElemType data;
	struct ThreadNode* lchild, * rchild;
	// ����������־��true����������
	bool lTag, rTag;
}ThreadNode, * ThreadTree;

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