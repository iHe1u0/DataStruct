#pragma once

// 二叉树的顺序存储
typedef int ElemType;
// 定义最大节点数
constexpr auto MaxSize = 32;
// 顺序存储结构体
struct TreeNode
{
	ElemType value;
	bool isEmpty;
};
// 链式存储的结构体
typedef struct BiTreeNode
{
	ElemType data;
	BiTreeNode* lchild, * rchild;
}BiTreeNode, * BiTree;