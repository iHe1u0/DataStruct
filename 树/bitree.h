#pragma once
#include <iostream>

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
	struct BiTreeNode* lchild, * rchild;
	// 左右线索标志
	bool lTag, rTag;
}BiTreeNode, * BiTree;
// 线索二叉树的结构体
typedef struct ThreadNode
{
	ElemType data;
	struct ThreadNode* lchild, * rchild;
	// 左右线索标志，true代表被线索化
	bool lTag, rTag;
}ThreadNode, * ThreadTree;

// 定义一个访问节点的方法，此处是打印节点的值
void visit(BiTree& node);

// 先序遍历
void preOrder(BiTree& tree);

// 中序遍历
void inOrder(BiTree& tree);

// 后序遍历
void postOrder(BiTree& tree);

// 层序遍历
void levelOrder(BiTree& tree);

// 获取树的深度/高度
int getTreeDepth(BiTree& tree);