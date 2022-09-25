#include "tree.h"
#include <format>
#include <iostream>
#include <queue>

using std::format;
using std::cout;
using std::endl;
// 使用C++ STL提供的队列功能
using std::queue;

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
	BiTree rchild = (BiTree)malloc(sizeof(BiTreeNode));
	if (lchild == nullptr || rchild == nullptr)
	{
		return -2;
	}
	lchild->data = 2;
	rchild->data = 3;

	lchild->lchild = lchild->rchild = nullptr;
	rchild->lchild = rchild->rchild = nullptr;
	// 将根节点的左孩子指向lchild
	root->lchild = lchild;
	// 将根节点的左孩子指向rchild
	root->rchild = rchild;

	// 先序遍历
	// preOrder(root);
	// 中序遍历
	// inOrder(root);
	// 后序遍历
	// postOrder(root);
	// 层序遍历
	levelOrder(root);
	// 获取数的高度
	cout << format("树的深度为：{}\n", getTreeDepth(root));

	// 用后销毁
	// 若是使用new关键字，则此处的删除得用 delete root;
	free(lchild);
	free(rchild);
	free(root);
	return 0;
}

void visit(BiTree& node)
{
	cout << node->data << endl;
}

void preOrder(BiTree& tree)
{
	// 如果是一棵空树，则啥都不做
	if (tree == nullptr)
	{
		return;
	}
	visit(tree);
	preOrder(tree->lchild);
	preOrder(tree->rchild);
}

void inOrder(BiTree& tree)
{
	if (tree == nullptr)
	{
		return;
	}
	preOrder(tree->lchild);
	visit(tree);
	preOrder(tree->rchild);
}

void postOrder(BiTree& tree)
{
	if (tree == nullptr)
	{
		return;
	}
	preOrder(tree->lchild);
	visit(tree);
	preOrder(tree->rchild);
}

void levelOrder(BiTree& tree)
{
	if (tree == nullptr)
	{
		return;
	}
	// C++ stl 提供的队列功能
	queue<BiTree> q;
	// 根节点入队
	q.push(tree);
	// 队列不为空的时候循环
	while (!q.empty())
	{
		// 访问队首元素
		auto elem = q.front();
		visit(elem);
		// 然后将队首元素出队
		q.pop();
		if (elem->lchild != nullptr)
		{
			q.push(elem->lchild);
		}
		if (elem->rchild != nullptr)
		{
			q.push(elem->rchild);
		}
	}
}

int getTreeDepth(BiTree& tree)
{
	if (tree == nullptr)
	{
		return 0;
	}
	int lChildDepth = getTreeDepth(tree->lchild);
	int rChildDepth = getTreeDepth(tree->rchild);
	return lChildDepth > rChildDepth ? lChildDepth + 1 : rChildDepth + 1;
}
