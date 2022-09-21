#include "kmp.h"
#include <iostream>
#include <cstring>
#include <format> // C++20中新加的特性，格式化输出

using std::cout;
using std::endl;
using std::string;
using std::format;

/// 本代码中的字符串下标均是从0开始计算
/// 区别于王道书以及大部分学校所教的数组下标从0开始
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
	cout << format("获取到的索引为：{}", index);
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
		// 当为-1的时候，代表着主串的指针指向了第一个元素
		// 此事需要将主串和子串的指针同时向右移动
		if (subIndex == -1 || mainString.at(mainIndex) == subString.at(subIndex))
		{
			mainIndex++;
			subIndex++;
		}
		else
		{
			// mainIndex不需要回溯了
			subIndex = next[subIndex];
		}
	}
	if (subIndex > subString.length())
	{
		// 匹配成功，返回主串中的第一个字符的位置
		return mainIndex - subIndex;
	}
	return -100;
}

int* getNext(string& str)
{
	// kmp获取next数组的算法与主串无关，仅仅与子串有关
	// 声明一个数组用来存放 next 数组
	int* next = new int[str.length()];
	if (next == nullptr)
	{
		return nullptr;
	}
	// next[0]=-1 进行初始化
	next[0] = -1;
	// 
	int i = 1, j = 0;
	// nextValue 记录 next[j] 的值
	int nextValue = -1;
	while (j < str.length())
	{
		// 当为起始位置或者相匹配时，继续向右移动
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
