#include "tree.h"
#include <format>
#include <iostream>

using std::format;
using std::cout;
using std::endl;

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
	if (lchild==nullptr)
	{
		return -2;
	}
	lchild->data = 2;
	lchild->lchild = lchild->rchild = nullptr;
	// �����ڵ������ָ��lchild
	root->lchild = lchild;

	// �ú�����
	// ����ʹ��new�ؼ��֣���˴���ɾ������ delete root;
	free(lchild);
	free(root);
	return 0;
}