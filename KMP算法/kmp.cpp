#include "kmp.h"
#include <iostream>
#include <cstring>
#include <format> // C++20���¼ӵ����ԣ���ʽ�����

using std::cout;
using std::endl;
using std::string;
using std::format;

/// �������е��ַ����±���Ǵ�0��ʼ����
/// �������������Լ��󲿷�ѧУ���̵������±��0��ʼ
int main() {
	string str = "A man who doesn't spend time with his family can never be a real man.";
	//string subStr = "time";
	//auto index = getIndex(str, subStr);
	//cout << "position is :" << index << endl;

	string kmpStr = "man.";
	auto next = getNext(kmpStr);
	auto size = kmpStr.length();
	for (auto index = 0; index <= size; index++)
	{
		cout << format("next[{}]={}", index, next[index]) << endl;
	}
	int index = kmp(str, kmpStr, next);
	cout << format("��ȡ��������Ϊ��{}", index);
	return 0;
}

int getIndex(string& mainString, string& subString) {
	auto startPos = 0;
	auto mainIndex = startPos;
	auto subIndex = 0;
	auto mainLen = mainString.size(), subLen = subString.size();
	while (startPos < mainLen && subIndex < subLen)
	{
		auto mainChar = mainString.at(mainIndex);
		auto subChar = subString.at(subIndex);
		if (mainChar == subChar)
		{
			mainIndex++;
			subIndex++;
		}
		else
		{
			startPos++;
			mainIndex = startPos;
			subIndex = 0;
		}
	}
	if (subIndex >= subLen)
	{
		return startPos;
	}
	return 0;
}

int kmp(string& mainString, string& subString, int next[])
{
	int mainIndex = 0, subIndex = 0;
	while (mainIndex < mainString.length() && subIndex < subString.length())
	{
		// ��Ϊ-1��ʱ�򣬴�����������ָ��ָ���˵�һ��Ԫ��
		// ������Ҫ���������Ӵ���ָ��ͬʱ�����ƶ�
		if (subIndex == -1 || mainString.at(mainIndex) == subString.at(subIndex))
		{
			mainIndex++;
			subIndex++;
		}
		else
		{
			// mainIndex����Ҫ������
			subIndex = next[subIndex];
		}
	}
	if (subIndex > subString.length())
	{
		// ƥ��ɹ������������еĵ�һ���ַ���λ��
		return mainIndex - subIndex;
	}
	return -100;
}

int* getNext(string& str)
{
	// kmp��ȡnext������㷨�������޹أ��������Ӵ��й�
	// ����һ������������� next ����
	int* next = new int[str.length()];
	if (next == nullptr)
	{
		return nullptr;
	}
	// next[0]=-1 ���г�ʼ��
	next[0] = -1;
	// 
	int i = 1, j = 0;
	// nextValue ��¼ next[j] ��ֵ
	int nextValue = -1;
	while (j < str.length())
	{
		// ��Ϊ��ʼλ�û�����ƥ��ʱ�����������ƶ�
		if (nextValue == -1 || str.at(j) == str.at(nextValue)) {
			j++;
			nextValue++;
			next[j] = nextValue;
		}
		else {
			nextValue = next[nextValue];
		}
	}
	return next;
}

int* getNextVal(std::string& str) {

	return nullptr;
}
