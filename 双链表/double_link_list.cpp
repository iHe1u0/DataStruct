#include <cstdlib>
#include <cstdio>

#define ElemType int

typedef struct DNode {
	ElemType data;
	DNode* prior, * next;
}DNode, * DLinkList;

// ��priorNode�ڵ�����node�ڵ�
bool Insert(DNode* priorNode, DNode* node) {
	if (priorNode == NULL || node == NULL)
	{
		return false;
	}
	node->next = priorNode->next;
	if (priorNode->next != NULL)
	{
		priorNode->next->prior = node;
	}
	node->prior = priorNode;
	priorNode->next = node;
	return true;
}

// ɾ���ڵ�node���һ���ڵ�
bool DeleteNode(DNode* node) {
	if (node == NULL)
	{
		return false;
	}
	DNode* deletedNode = node->next;
	if (deletedNode == NULL)
	{
		return false;
	}
	node->next = deletedNode->next;
	if (deletedNode->next != NULL)
	{
		deletedNode->next->prior = node;
	}
	free(deletedNode);
	return true;
}

// �п�
bool isEmpty(DLinkList list) {
	if (list->next == nullptr)
	{
		return true;
	}
	return false;
}

// ����������target�ڵ�
int FindBack(DNode* node, ElemType target) {
	if (node == NULL)
	{
		return -1;
	}
	int index = 0;
	while (node != NULL && node->data != target)
	{
		node = node->next;
		index++;
	}
	if (node == NULL)
	{
		return -1;
	}
	return index;
}

// ��ʼ��˫����
bool InitDLinkList(DLinkList& list) {
	list = (DLinkList)malloc(sizeof(DNode));
	if (list == NULL)
	{
		return false;
	}
	list->next = NULL;
	list->prior = NULL;
	return true;
}

// ����һ��˫����
bool DestoryDLinkList(DLinkList& list) {
	if (list == NULL)
	{
		return false;
	}
	while (list->next != NULL)
	{
		DeleteNode(list);
	}
	free(list);
	return true;
}

int main() {
	DLinkList list;
	bool result = InitDLinkList(list);
	if (!result)
	{
		printf("%s\n", "��ʼ������ʧ��");
		exit(-1);
	}
	for (int i = 1; i < 10; i++)
	{
		DNode* node = (DNode*)malloc(sizeof(DNode));
		if (node == NULL)
		{
			node->data = i;
			node->next = NULL;
			node->prior = NULL;
			Insert(list, node);
		}
	}

	// ����ֵΪ5�Ľڵ�
	int location = FindBack(list, 5);
	printf("ֵΪ5�Ľڵ��ڵ�%d��\n", location);
	free(list);
	return 0;
}