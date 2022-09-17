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
	SString* subString = (SString*)malloc(sizeof(SString));
	if (subString == NULL)
	{
		return -101;
	}
	// 求子串
	subString = SubString(str, 1, 8);

	// 比较两个串的大小
	int compareResult = StringCompare(*str, *subString);

	printf("比较结果：%d", compareResult);

	free(ch);
	free(subString);
	free(str);
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
	SString* subString = (SString*)malloc(sizeof(SString));
	if (subString == NULL)
	{
		return NULL;
	}
	for (int index = position; index < position + length; index++)
	{
		subString->ch[index - position + 1] = source->ch[index];
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
