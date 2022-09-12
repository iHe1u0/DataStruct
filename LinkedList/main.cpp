#include <cstdio>
#include <cstdlib>

#define ElemType int

typedef struct LNode {
	ElemType data;
	struct LNode* pNext;
} LNode, * LinkList;

//	求单链表的长度length
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
// 初始化一个单链表
LinkList InitList() {
	LinkList list = (LinkList)malloc(sizeof(LNode));
	if (list == NULL)
	{
		return NULL;
	}
	list->pNext = NULL;
	return list;
}

//	按位查找，返回第index个元素
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

// 按值查找
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

// 前插
bool InsertForward(LinkList& list, int index, ElemType data) {
	if (index < 1)
	{
		return false;
	}
	LNode* pCurrentNode;	//	当前的节点
	int currentIndex = 0;		//	当前节点(pCurrent)指向的节点位置
	pCurrentNode = list;	//	list指向的是原链表的头结点，原链表的头结点不存储数据
	//	循环找到要插入的位置(index)之前的节点
	while (pCurrentNode != NULL && currentIndex < index - 1)
	{
		pCurrentNode = pCurrentNode->pNext;
		currentIndex++;
	}
	//	循环一遍，找到最后还没找到要插入的位置
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
//	前插的另一种
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

//	后插
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

//	删除index处的节点，data为删除节点处的值
bool DeleteNode(LinkList& list, int index, ElemType& data) {
	if (index < 1)
	{
		return false;
	}
	LNode* pCurrentNode;		//	该节点指向当前扫描的节点
	int currentIndex = 0;		//	当前扫描的位置
	pCurrentNode = list;
	while (pCurrentNode != NULL && currentIndex < index - 1)
	{
		pCurrentNode = pCurrentNode->pNext;
		currentIndex++;
	}
	//	若index超过了链表的大小或者index节点是最后一个节点
	if (pCurrentNode == NULL || pCurrentNode->pNext == NULL)
	{
		return false;
	}
	LNode* deletedNode = pCurrentNode->pNext;	//	指向要被删除的节点
	pCurrentNode->pNext = deletedNode->pNext;
	data = deletedNode->data;
	free(deletedNode);
	return true;
}

//	删除指定节点
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
	printf("链表长度为：%d\n", GetLength(list));
	//	前插法模拟插入1~9
	for (size_t i = 1; i < 10; i++)
	{
		InsertForward(list, i, i);
	}
	printf("链表长度为：%d\n", GetLength(list));

	//	后插插入100~110
	for (size_t i = 100; i <= 110; i++)
	{
		InsertBack(list, i);
	}
	printf("链表长度为：%d\n", GetLength(list));

	free(list);

	return 0;
}