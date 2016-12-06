#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*输入一个字符串，打印出该字符串中字符的所有排列 */
void Permutation(char* pStr, char* pBegin);
void swap(char& a, char& b)
{
	char temp = b;
	b = a;
	a = temp;
}
void Permutation(char* pStr){
	if (pStr == NULL)
		return;

	Permutation(pStr, pStr);
}
void Permutation(char* pStr, char* pBegin){
	if (*pBegin == '\0'){
		cout << pStr << endl;
	}
	else{
		for (char *pCh = pBegin; *pCh != '\0'; ++pCh){
			swap(*pCh, *pBegin);

			Permutation(pStr, pBegin + 1);
			swap(*pCh, *pBegin);
		}
	}
}
void Test(char* str)
{
	if (str == NULL)
		cout << "Test for NULL begins";
	else
		cout << "Test for " << str << endl;
	Permutation(str);
	cout << endl;
}

// 测试
int main(void){
	Test(NULL);
	char str1[] = "";
	Test(str1);

	char str2[] = "a";
	Test(str2);

	char str3[] = "ab";
	Test(str3);

	char str4[] = "abc";
	Test(str4);


	system("pause");
	return 0;
}