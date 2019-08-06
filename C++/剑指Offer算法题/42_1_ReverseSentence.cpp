#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;
using std::cin;

/*����һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣*/

// ��ת�ַ����е�һ��
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
// �ⷨ���ȷ�ת�������ӣ��ٷ�תÿ������
string ReverseSentence(string pData){
	if (pData.size() <= 0)
		return NULL;
	int pBegin = 0;
	int  pEnd = pData.size() - 1;
	
	// ��ת��������
	Reverse(pData, pBegin,pEnd);
	// ��ת�����е�ÿ������
	int i = 0;
	// �ж��Ƿ��ҵ�����
	bool isWord = false;
	pBegin = pEnd = 0;
	while (pData[pEnd+1] != '\0'){
		if (pData[pEnd] != ' ' && pData[pEnd] != '\0'){
			++pEnd;
			isWord = true;
		}
		else{
			// �ҵ�����
			Reverse(pData, pBegin, pEnd-1);
			isWord = false;
			// ��һ�����ǿո�
			while (pData[pEnd + 1] == ' ' && pData[pEnd + 1] != '\0')
				++pEnd;
			pBegin = ++pEnd;
		}
	}
	if (isWord)
		// ���һ������
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

// ����
int main(void){
	char *test[] = { "hello world. I will go back!", "hello"};
	for (int i = 0; i < 2; i++)
		Test(test[i]);
	

	system("pause");
	return 0;
}