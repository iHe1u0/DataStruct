#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

// �����ַ���
#define MaxSize 32
typedef struct {
	char ch[MaxSize]; // ������0���±겻�洢����
	int length;       // �ַ����ĳ���
}SString;
//typedef struct HString {
//	char* ch;
//	int length;
//}HString;

typedef struct StringNode {
	char ch;
	struct StringNode* next;
}StringNode, * String;

// ��ֵ����
void StringAssign(SString*& destination, char* source);

// ��ֵ����
void StringCopy(SString& destination, SString source);

// �пղ���
bool isEmpty(SString source);

// �󴮳�
int GetLength(SString source);

// ��ղ��������ַ�����Ϊ�մ�
void StringClear(SString& source);

// ���ٲ��������� source ���ٲ������ڴ�ռ�
void StringDestory(SString& source);

// ��������
void StringConcat(SString& destination, SString source1, SString source2);

// ���Ӵ������ش� source �ӵ� position ��ʼ����Ϊ length ���Ӵ�
SString* SubString(SString* source, int position, int length);

// ��λ������������ source �д������Ӵ� substring ��ͬ�Ĵ����򷵻���һ�γ��ֵ�λ�ã����򷵻�0
int GetIndex(SString source, SString substring);

// �Ƚϲ���
// �� source1 > source2������ֵ >0
// �� source1 = source2������ֵ =0
// �� source1 < source2������ֵ <0
int StringCompare(SString source1, SString source2);