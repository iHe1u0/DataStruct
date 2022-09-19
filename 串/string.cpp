#include "string.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main() {
	// ��ʼ��һЩ����
	SString* str = (SString*)malloc(sizeof(SString));
	char* ch = (char*)malloc(sizeof(char) * MaxSize);
	if (str == NULL || ch == NULL)
	{
		return -100;
	}
	strcpy(ch, "iMorning");
	StringAssign(str, ch);
	printf("data: %s\n", str->ch);
	// ���Ӵ�
	SString* subString = SubString(str, 1, 2);

	// �Ƚ��������Ĵ�С
	// int compareResult = StringCompare(*str, *subString);
	// printf("�ȽϽ����%d", compareResult);

	// ����ģʽƥ���㷨
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
	// ����������
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
	// �����Ӵ���ΧԽ��
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
	// ��¼�Ӵ����±�
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
	SString* sub = (SString*)malloc(sizeof(SString)); // �����ݴ��Ӵ�
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
	int startPos = 1; // ָ��ǰ��������ʼλ��
	// index ָ������ÿ��ƥ���λ��
	// subIndex ָ���Ӵ���ÿ��ƥ���λ��
	int index = startPos, subIndex = 1;
	// ��¼�������Ӵ��ĳ���
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
	// �ж��Ӵ����±��Ƿ񳬳����Ӵ��ĳ���
	// ���ǳ����˳��ȣ�����������ϸ�ѭ���У���ʹ�ǲ�����
	// index < mainStringLength ���������Ҳ�ǽ��Ӵ���ȫƥ�����˵�
	if (subIndex > subStringLength)
	{
		return startPos;
	}
	// ���������� index < mainStringLength ���ԭ��������ϸ�ѭ��
	return 0;
}
