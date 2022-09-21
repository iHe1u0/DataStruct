#pragma once
#include <string>

using std::string;

// 朴素模式匹配算法
int getIndex(string& mainString, string& subString);

// KMP算法
int kmp(string& mainString, string& subString, int next[]);

// 求一个字符串的 next 数组
int* getNext(std::string& str);

// 优化后的 next 算法
int* getNextVal(std::string& str);