#pragma once
#include <string>

using std::string;

// ����ģʽƥ���㷨
int getIndex(string& mainString, string& subString);

// KMP�㷨
int kmp(string& mainString, string& subString, int next[]);

// ��һ���ַ����� next ����
int* getNext(std::string& str);

// �Ż���� next �㷨
int* getNextVal(std::string& str);