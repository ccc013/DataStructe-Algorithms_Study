#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*在字符串中找出第一个只出现一次的字符 */

// 解法，采用哈希表
char FirstNotRepeatingChar(char* pStr){
	if (pStr == NULL)
		return '\0';
	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	// 初始化哈希表
	for (unsigned int i = 0; i < tableSize; ++i)
		hashTable[i] = 0;
	// 第一次遍历字符串，在哈希表中记录每个字符出现次数
	char* pHashKey = pStr;
	while (*pHashKey != '\0')
		hashTable[*(pHashKey++)]++;
	// 第二次遍历字符串，找到第一个只出现一次的字符并返回结果
	pHashKey = pStr;
	while (*pHashKey != '\0'){
		if (hashTable[*pHashKey] == 1)
			return *pHashKey;
		pHashKey++;
	}
	return '\0';
}


void Test(char* pStr){
	if (pStr == NULL)
		cout << "Test for NULL String: ";
	else
		cout << "Test String: " << pStr << endl;
	char str = FirstNotRepeatingChar(pStr);
	if (str == '\0')
		cout << "wrong input!\n";
	else
		cout << "result = " << str << endl;
}

// 测试
int main(void){
	Test("abaccdeff");
	Test("ababccdede");
	Test("dab");
	Test("abcde");
	Test(NULL);


	system("pause");
	return 0;
}