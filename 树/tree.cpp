#include "tree.h"
#include <format>
#include <iostream>

using std::format;
using std::cout;
using std::endl;

int main() {
	// 二叉树的顺序存储方式
	TreeNode tree[MaxSize];
	// 初始化二叉树，下标从1开始
	// 从1开始是为了对应课本上的根节点从1开始
	// 这里初始化的是一颗完全二叉树（也可能是满二叉树）
	for (auto index = 0; index < MaxSize; index++)
	{
		tree[index].isEmpty = true;
		tree[index].value = index;
	}

	// 二叉树的链式存储
	// 定义一棵空树
	BiTree root = nullptr;
	// 插入根节点
	root = (BiTree)malloc(sizeof(BiTreeNode));
	// C++也可采用以下方法
	// root = new BiTreeNode;
	if (root == nullptr)
	{
		return -1;
	}
	root->data = 1;
	root->lchild = root->rchild = nullptr;
	// 一个新的结点
	BiTree lchild = (BiTree)malloc(sizeof(BiTreeNode));
	if (lchild==nullptr)
	{
		return -2;
	}
	lchild->data = 2;
	lchild->lchild = lchild->rchild = nullptr;
	// 将根节点的左孩子指向lchild
	root->lchild = lchild;

	// 用后销毁
	// 若是使用new关键字，则此处的删除得用 delete root;
	free(lchild);
	free(root);
	return 0;
}