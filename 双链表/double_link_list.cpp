#include <cstdlib>
#include <cstdio>

#define ElemType int

typedef struct DNode {
	ElemType data;
	DNode* prior, * next;
}DNode, * DLinkList;

// 在priorNode节点后插入node节点
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

// 删除节点node后的一个节点
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

// 判空
bool isEmpty(DLinkList list) {
	if (list->next == nullptr)
	{
		return true;
	}
	return false;
}

// 向后遍历查找target节点
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

// 初始化双链表
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

// 销毁一个双链表
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
		printf("%s\n", "初始化链表失败");
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

	// 查找值为5的节点
	int location = FindBack(list, 5);
	printf("值为5的节点在第%d处\n", location);
	free(list);
	return 0;
}