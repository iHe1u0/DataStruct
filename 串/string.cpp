#include "string.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main() {
	// 初始化一些数据
	SString* str = (SString*)malloc(sizeof(SString));
	char* ch = (char*)malloc(sizeof(char) * MaxSize);
	if (str == NULL || ch == NULL)
	{
		return -100;
	}
	strcpy(ch, "iMorning");
	StringAssign(str, ch);
	printf("data: %s\n", str->ch);
	// 求子串
	SString* subString = SubString(str, 1, 2);

	// 比较两个串的大小
	// int compareResult = StringCompare(*str, *subString);
	// printf("比较结果：%d", compareResult);

	// 朴素模式匹配算法
	SString* subStr = (SString*)malloc(sizeof(SString));
	if (subStr == NULL)
	{
		return -103;
	}
	subStr->length = 0;
	for (int index = 0; index <= MaxSize; index++)
	{
		if (index <= 4)
		{
			subStr->ch[index] = ch[index];
		}
		else
		{
			subStr->ch[index] = NULL;
		}
		subStr->length++;
	}
	printf("%d", Index(*str, *subStr));
	return 0;
}

void StringAssign(SString*& destination, char* source)
{
	if (source == NULL)
	{
		return;
	}
	destination->ch[0] = ' ';
	for (int pos = 1; pos < strlen(source) + 1; pos++)
	{
		destination->ch[pos] = source[pos - 1];
	}
	destination->length = strlen(source);
	// 清理脏数据
	for (int index = destination->length + 1; index < MaxSize; index++)
	{
		destination->ch[index] = NULL;
	}
}

void StringCopy(SString& destination, SString source)
{
}

bool isEmpty(SString source)
{
	return source.length == 0;
}

int GetLength(SString source)
{
	return source.length;
}

void StringClear(SString& source)
{
}

void StringDestory(SString& source)
{
	free(&source);
}

void StringConcat(SString& destination, SString source1, SString source2)
{
}

SString* SubString(SString* source, int position, int length)
{
	// 若是子串范围越界
	if (position + length - 1 > source->length)
	{
		return NULL;
	}
	SString* subString = (SString*)malloc(1 + length);
	if (subString == NULL)
	{
		return NULL;
	}
	subString->ch[0] = ' ';
	// 记录子串的下标
	int subIndex = 0;
	for (int index = position; index < position + length; index++, subIndex++)
	{
		subString->ch[subIndex] = source->ch[index];
	}
	subString->length = length;
	return subString;
}

int GetIndex(SString source, SString substring)
{
	int startPos = 1, sourceLength = GetLength(source), subLength = GetLength(substring);
	SString* sub = (SString*)malloc(sizeof(SString)); // 用于暂存子串
	while (startPos <= sourceLength - subLength + 1)
	{
		sub = SubString(&source, startPos, subLength);
		if (StringCompare(*sub, source) != 0)
		{
			++startPos;
		}
		else
		{
			return startPos;
		}
	}
	return 0;
}

int StringCompare(SString source1, SString source2)
{
	for (int index = 1; index < source1.length && index < source2.length; index++)
	{
		if (source1.ch[index] != source2.ch[index])
		{
			return source1.ch[index] - source2.ch[index];
		}
	}
	return source1.length - source2.length;
}

int Index(SString mainString, SString subString)
{
	int startPos = 1; // 指向当前主串的起始位置
	// index 指向主串每次匹配的位置
	// subIndex 指向子串的每次匹配的位置
	int index = startPos, subIndex = 1;
	// 记录主串和子串的长度
	int mainStringLength = GetLength(mainString);
	int subStringLength = GetLength(subString);
	while (index < mainStringLength && subIndex < subStringLength)
	{
		if (mainString.ch[index] == subString.ch[subIndex])
		{
			index++;
			subIndex++;
		}
		else
		{
			startPos++;
			index = startPos;
			subIndex = 1;
		}
	}
	// 判断子串的下标是否超出的子串的长度
	// 若是超出了长度，则代表着在上个循环中，即使是不符合
	// index < mainStringLength 这个条件，也是将子串完全匹配完了的
	if (subIndex > subStringLength)
	{
		return startPos;
	}
	// 否则是由于 index < mainStringLength 这个原因结束了上个循环
	return 0;
}
