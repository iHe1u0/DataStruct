// 树的存储结构
#pragma once

typedef int ElemType;

// 双亲表示法（顺序存储）:每个结点保存指向双亲的“指针”
// 定义树的最大结点数目
constexpr auto MAX_TREE_SIZE = 100;
// 树结点的定义
struct ParentTreeNode
{
	ElemType data; //数据元素
	int parent;    //双亲位置域
};
//树类型的定义
struct ParentTree {
	ParentTreeNode nodes[MAX_TREE_SIZE]; //双亲表示
	int num;                             //结点数目
};

// 孩子表示法（顺序+链式存储）
// 顺序存储各个结点，每个结点中保存孩子链表头指针
struct ChildTreeNode
{
	int child;           //孩子结点在数组中的位置
	ChildTreeNode* next; //下一个孩子
};
struct ChildTreeBox
{
	ElemType data;
	ChildTreeNode* firstChild; //第一个孩子
};
struct ChildTree
{
	ChildTreeBox nodes[MAX_TREE_SIZE];
	int num, root; //结点数和根节点的位置
};

// 孩子兄弟表示法（链式存储）
typedef struct CSNode
{
	ElemType data; //数据域
	CSNode* firstChild, * next; //第一个孩子和右兄弟指针
}CSNode, * CSTree;