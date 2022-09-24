#pragma once

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