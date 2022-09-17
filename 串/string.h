#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

// 定义字符串
#define MaxSize 32
typedef struct {
	char ch[MaxSize]; // 定长，0号下标不存储数据
	int length;       // 字符串的长度
}SString;
//typedef struct HString {
//	char* ch;
//	int length;
//}HString;

typedef struct StringNode {
	char ch;
	struct StringNode* next;
}StringNode, * String;

// 赋值操作
void StringAssign(SString*& destination, char* source);

// 赋值操作
void StringCopy(SString& destination, SString source);

// 判空操作
bool isEmpty(SString source);

// 求串长
int GetLength(SString source);

// 清空操作，将字符串清为空串
void StringClear(SString& source);

// 销毁操作，将串 source 销毁并回收内存空间
void StringDestory(SString& source);

// 串的连接
void StringConcat(SString& destination, SString source1, SString source2);

// 求子串，返回串 source 从第 position 开始长度为 length 的子串
SString* SubString(SString* source, int position, int length);

// 定位操作，若主串 source 中存在与子串 substring 相同的串，则返回它一次出现的位置，否则返回0
int GetIndex(SString source, SString substring);

// 比较操作
// 若 source1 > source2，返回值 >0
// 若 source1 = source2，返回值 =0
// 若 source1 < source2，返回值 <0
int StringCompare(SString source1, SString source2);