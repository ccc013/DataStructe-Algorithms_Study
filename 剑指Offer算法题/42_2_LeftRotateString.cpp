#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;
using std::cin;

/*实现字符串左旋转操作，左旋转操作是将字符串前面的若干个字符转移到字符串的尾部*/

// 翻转字符串中的一段
void Reverse(string &pStr, int pBegin, int pEnd){
	if (pStr.size() <= 0)
		return;
	char temp;
	int j = (pEnd - pBegin) / 2;
	for (int i = 0; i <= j; i++){
		temp = pStr[pBegin];
		pStr[pBegin++] = pStr[pEnd];
		pStr[pEnd--] = temp;
	}
}
// 解法，将字符串分成两部分，前面选择的n位字符串和剩下的字符串
string LeftRotateString(string pData, int n){
	if (pData.size() > 0){
		int nLength = pData.size();
		if (nLength > 0 && n > 0 && n < nLength){
			int pFirstStart = 0;
			int pFristEnd = n - 1;
			int pSecondStart = n;
			int pSecondEnd = nLength - 1;
			// 翻转字符串的前面n个字符
			Reverse(pData, pFirstStart, pFristEnd);
			// 翻转字符串后面的部分
			Reverse(pData, pSecondStart, pSecondEnd);
			// 翻转整个字符串
			Reverse(pData, pFirstStart, pSecondEnd);
		}
	}
	return pData;
}

void Test(string pData, int n){
	if (pData.size()>0)
		cout << "Test string: " << pData << endl;
	else
		cout << "Test for NULL: \n";
	cout << "rotate numbers = " << n << endl;
	string pResult = LeftRotateString(pData, n);
	cout << "result = " << pResult << endl;
}

// 测试
int main(void){
	char *test[] = { "hello world"};
	for (int i = 0; i < 13; i++)
		Test(test[0],i);
	

	system("pause");
	return 0;
}