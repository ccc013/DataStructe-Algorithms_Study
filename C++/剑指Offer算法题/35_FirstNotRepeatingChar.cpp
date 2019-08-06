#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*���ַ������ҳ���һ��ֻ����һ�ε��ַ� */

// �ⷨ�����ù�ϣ��
char FirstNotRepeatingChar(char* pStr){
	if (pStr == NULL)
		return '\0';
	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	// ��ʼ����ϣ��
	for (unsigned int i = 0; i < tableSize; ++i)
		hashTable[i] = 0;
	// ��һ�α����ַ������ڹ�ϣ���м�¼ÿ���ַ����ִ���
	char* pHashKey = pStr;
	while (*pHashKey != '\0')
		hashTable[*(pHashKey++)]++;
	// �ڶ��α����ַ������ҵ���һ��ֻ����һ�ε��ַ������ؽ��
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

// ����
int main(void){
	Test("abaccdeff");
	Test("ababccdede");
	Test("dab");
	Test("abcde");
	Test(NULL);


	system("pause");
	return 0;
}