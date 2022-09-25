#include "tree.h"
#include <format>
#include <iostream>
#include <queue>

using std::format;
using std::cout;
using std::endl;
// ʹ��C++ STL�ṩ�Ķ��й���
using std::queue;

int main() {
	// ��������˳��洢��ʽ
	TreeNode tree[MaxSize];
	// ��ʼ�����������±��1��ʼ
	// ��1��ʼ��Ϊ�˶�Ӧ�α��ϵĸ��ڵ��1��ʼ
	// �����ʼ������һ����ȫ��������Ҳ����������������
	for (auto index = 0; index < MaxSize; index++)
	{
		tree[index].isEmpty = true;
		tree[index].value = index;
	}

	// ����������ʽ�洢
	// ����һ�ÿ���
	BiTree root = nullptr;
	// ������ڵ�
	root = (BiTree)malloc(sizeof(BiTreeNode));
	// C++Ҳ�ɲ������·���
	// root = new BiTreeNode;
	if (root == nullptr)
	{
		return -1;
	}
	root->data = 1;
	root->lchild = root->rchild = nullptr;
	// һ���µĽ��
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
	// �����ڵ������ָ��lchild
	root->lchild = lchild;
	// �����ڵ������ָ��rchild
	root->rchild = rchild;

	// �������
	// preOrder(root);
	// �������
	// inOrder(root);
	// �������
	// postOrder(root);
	// �������
	levelOrder(root);
	// ��ȡ���ĸ߶�
	cout << format("�������Ϊ��{}\n", getTreeDepth(root));

	// �ú�����
	// ����ʹ��new�ؼ��֣���˴���ɾ������ delete root;
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
	// �����һ�ÿ�������ɶ������
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
	// C++ stl �ṩ�Ķ��й���
	queue<BiTree> q;
	// ���ڵ����
	q.push(tree);
	// ���в�Ϊ�յ�ʱ��ѭ��
	while (!q.empty())
	{
		// ���ʶ���Ԫ��
		auto elem = q.front();
		visit(elem);
		// Ȼ�󽫶���Ԫ�س���
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
