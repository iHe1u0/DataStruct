#include <cstdio>
#include <cstdlib>

#define ElemType int

typedef struct LNode {
	ElemType data;
	struct LNode* pNext;
} LNode, * LinkList;

//	������ĳ���length
size_t GetLength(LinkList list) {
	if (list == NULL)
	{
		return 0;
	}
	LNode* pCurrentNode;
	pCurrentNode = list;
	int length = 0;
	while (pCurrentNode->pNext != NULL)
	{
		length++;
		pCurrentNode = pCurrentNode->pNext;
	}
	return length;
}
// ��ʼ��һ��������
LinkList InitList() {
	LinkList list = (LinkList)malloc(sizeof(LNode));
	if (list == NULL)
	{
		return NULL;
	}
	list->pNext = NULL;
	return list;
}

//	��λ���ң����ص�index��Ԫ��
LNode* GetElem(LinkList list, int index) {
	if (list == NULL || index < 0)
	{
		return NULL;
	}
	LNode* pCurrentNode;
	int currentIndex = 0;
	pCurrentNode = list;
	while (pCurrentNode != NULL && currentIndex != index)
	{
		pCurrentNode = pCurrentNode->pNext;
		currentIndex++;
	}
	if (pCurrentNode == NULL) {
		return NULL;
	}
	return pCurrentNode;
}

// ��ֵ����
int FindElem(LinkList list, ElemType target) {
	if (list == NULL || target == NULL)
	{
		return -1;
	}
	LNode* pCurrentNode;
	pCurrentNode = list;
	int currentIndex = 0;
	while (pCurrentNode != NULL && pCurrentNode->data != target)
	{
		pCurrentNode = pCurrentNode->pNext;
		currentIndex++;
	}
	return currentIndex;
}

// assert if the link list is empty
bool isEmpty(LinkList list) {
	return list->pNext == NULL;
}

// ǰ��
bool InsertForward(LinkList& list, int index, ElemType data) {
	if (index < 1)
	{
		return false;
	}
	LNode* pCurrentNode;	//	��ǰ�Ľڵ�
	int currentIndex = 0;		//	��ǰ�ڵ�(pCurrent)ָ��Ľڵ�λ��
	pCurrentNode = list;	//	listָ�����ԭ�����ͷ��㣬ԭ�����ͷ��㲻�洢����
	//	ѭ���ҵ�Ҫ�����λ��(index)֮ǰ�Ľڵ�
	while (pCurrentNode != NULL && currentIndex < index - 1)
	{
		pCurrentNode = pCurrentNode->pNext;
		currentIndex++;
	}
	//	ѭ��һ�飬�ҵ����û�ҵ�Ҫ�����λ��
	if (pCurrentNode == NULL)
	{
		return false;
	}
	LNode* node = (LNode*)malloc(sizeof(LNode));
	node->data = data;
	node->pNext = pCurrentNode->pNext;
	pCurrentNode->pNext = node;
	return true;
}
//	ǰ�����һ��
bool InsertForward(LinkList list, ElemType data) {
	if (list == NULL)
	{
		return false;
	}
	LNode* node = (LNode*)malloc(sizeof(LNode));
	if (node == NULL)
	{
		return false;
	}
	node->pNext = list->pNext;
	list->pNext = node;
	node->data = list->data;
	list->data = data;
	return true;
}

//	���
bool InsertBack(LinkList& list, ElemType data) {
	if (list == NULL)
	{
		return false;
	}
	LNode* node = (LNode*)malloc(sizeof(LNode));
	if (node == NULL)
	{
		return false;
	}
	node->data = data;
	node->pNext = list->pNext;
	list->pNext = node;
	return true;
}

//	ɾ��index���Ľڵ㣬dataΪɾ���ڵ㴦��ֵ
bool DeleteNode(LinkList& list, int index, ElemType& data) {
	if (index < 1)
	{
		return false;
	}
	LNode* pCurrentNode;		//	�ýڵ�ָ��ǰɨ��Ľڵ�
	int currentIndex = 0;		//	��ǰɨ���λ��
	pCurrentNode = list;
	while (pCurrentNode != NULL && currentIndex < index - 1)
	{
		pCurrentNode = pCurrentNode->pNext;
		currentIndex++;
	}
	//	��index����������Ĵ�С����index�ڵ������һ���ڵ�
	if (pCurrentNode == NULL || pCurrentNode->pNext == NULL)
	{
		return false;
	}
	LNode* deletedNode = pCurrentNode->pNext;	//	ָ��Ҫ��ɾ���Ľڵ�
	pCurrentNode->pNext = deletedNode->pNext;
	data = deletedNode->data;
	free(deletedNode);
	return true;
}

//	ɾ��ָ���ڵ�
bool DeleteNode(LNode* node) {
	if (node == NULL)
	{
		return false;
	}
	LNode* nextNode = node->pNext;
	node->data = nextNode->data;
	node->pNext = nextNode->pNext;
	free(nextNode);
	return true;
}

int main() {
	LinkList list = InitList();
	printf("������Ϊ��%d\n", GetLength(list));
	//	ǰ�巨ģ�����1~9
	for (size_t i = 1; i < 10; i++)
	{
		InsertForward(list, i, i);
	}
	printf("������Ϊ��%d\n", GetLength(list));

	//	������100~110
	for (size_t i = 100; i <= 110; i++)
	{
		InsertBack(list, i);
	}
	printf("������Ϊ��%d\n", GetLength(list));

	free(list);

	return 0;
}