#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using std::string;
using std::cout;
using std::endl;
using std::cin;

/*����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ�����������������С��һ�� */

// �Ƚ�ƴ�Ӻ����������µ��������Ĵ�С
bool compare(const string strNumber1, const string strNumber2)
{
	string str1 = strNumber1 + strNumber2;
	string str2 = strNumber2 + strNumber1;
	return str2>str1;
}

// �ⷨ
void PrintMinNumber(int* numbers, int length){
	if (numbers == NULL || length <= 0){
		cout << "wrong input\n";
		return;
	}	
	std::stringstream ss;//�������ֺ��ַ���ת����
	string* str = new string[length];
	// ������ת�����ַ���
	for (int i = 0; i < length; ++i)
	{
		ss.clear();
		ss << numbers[i];
		ss >> str[i];
	}
	// ʹ�ÿ⺯��sort��������
	sort(str, str + length, compare);

	for (int i = 0; i < length; i++)
		cout << str[i];
	cout << endl;

	delete[] str;
}

void Test(int* numbers, int length){
	if (numbers == NULL)
		cout << "Test for NULL:";
	else{
		cout << "Test for array:{";
		for (int i = 0; i < length; i++){
			cout << numbers[i];
			if (i == length - 1)
				cout << "}\n";
			else
				cout << ", ";
		}
	}
	PrintMinNumber(numbers, length);
}

// ����
int main(void){
	int t1[] = { 13, 32, 321 };
	Test(t1, 3);
	int t2[] = { 1, 23, 54 };
	Test(t2, 3);
	int t3[] = { 11, 23, 324, 9, 8 };
	Test(t3, 5);
	int t4[] = { 234 };
	Test(t4, 1);
	
	Test(NULL, 1);


	system("pause");
	return 0;
}