#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;
using std::cin;

/*ʵ���ַ�������ת����������ת�����ǽ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β��*/

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
// �ⷨ�����ַ����ֳ������֣�ǰ��ѡ���nλ�ַ�����ʣ�µ��ַ���
string LeftRotateString(string pData, int n){
	if (pData.size() > 0){
		int nLength = pData.size();
		if (nLength > 0 && n > 0 && n < nLength){
			int pFirstStart = 0;
			int pFristEnd = n - 1;
			int pSecondStart = n;
			int pSecondEnd = nLength - 1;
			// ��ת�ַ�����ǰ��n���ַ�
			Reverse(pData, pFirstStart, pFristEnd);
			// ��ת�ַ�������Ĳ���
			Reverse(pData, pSecondStart, pSecondEnd);
			// ��ת�����ַ���
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

// ����
int main(void){
	char *test[] = { "hello world"};
	for (int i = 0; i < 13; i++)
		Test(test[0],i);
	

	system("pause");
	return 0;
}