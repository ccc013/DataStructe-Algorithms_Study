#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;
using std::cin;

/*输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。*/

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
// 解法，先翻转整个句子，再翻转每个单词
string ReverseSentence(string pData){
	if (pData.size() <= 0)
		return NULL;
	int pBegin = 0;
	int  pEnd = pData.size() - 1;
	
	// 翻转整个句子
	Reverse(pData, pBegin,pEnd);
	// 翻转句子中的每个单词
	int i = 0;
	// 判断是否找到单词
	bool isWord = false;
	pBegin = pEnd = 0;
	while (pData[pEnd+1] != '\0'){
		if (pData[pEnd] != ' ' && pData[pEnd] != '\0'){
			++pEnd;
			isWord = true;
		}
		else{
			// 找到单词
			Reverse(pData, pBegin, pEnd-1);
			isWord = false;
			// 下一个还是空格
			while (pData[pEnd + 1] == ' ' && pData[pEnd + 1] != '\0')
				++pEnd;
			pBegin = ++pEnd;
		}
	}
	if (isWord)
		// 最后一个单词
		Reverse(pData, pBegin, pEnd);
	return pData;
}

void Test(string pData){
	if (pData.size()>0)
		cout << "Test sentence: " << pData << endl;
	else
		cout << "Test for NULL: \n";
	string pResult = ReverseSentence(pData);
	if (pData.size()>0)
		cout << "Reverse sentence: " << pResult << endl;
	else
		cout << "NULL\n";
}

// 测试
int main(void){
	char *test[] = { "hello world. I will go back!", "hello"};
	for (int i = 0; i < 2; i++)
		Test(test[i]);
	

	system("pause");
	return 0;
}