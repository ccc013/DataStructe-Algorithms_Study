#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*����һ������n�����1��n��n��������ʮ���Ʊ�ʾ��1���ֵĴ��� */

// �ⷨ1��ʱ�临�Ӷ���O(nlogn)
int NumberOf1(unsigned int n){
	int number = 0;
	while (n){
		if (n % 10 == 1)
			number++;
		n = n / 10;
	}
	return number;
}
int NumberOf1Between1AndN(unsigned int n){
	int number = 0;
	for (unsigned int i = 1; i <= n; i++)
		number += NumberOf1(i);
	return number;
}

// �ⷨ2��ʱ�临�Ӷ���O(logn)�����ŵĽⷨ
int PowerBase10(unsigned int n){
	int result = 1;
	for (unsigned int i = 0; i < n; i++)
		result *= 10;
	return result;
}
int NumberOf1(const char* strN){
	if (!strN || *strN < '0' || *strN > '9' || *strN == '\0')
		return 0;
	int first = *strN - '0';
	unsigned int length = static_cast<unsigned int>(strlen(strN));
	if (length == 1 && first == 0)
		return 0;
	if (length == 1 && first > 0)
		return 1;
	// ����strN�ǡ�21345����numFirstDigit ������10000~19999�ĵ�һ��λ�е���Ŀ
	int numFirstDigit = 0;
	if (first > 1)
		numFirstDigit = PowerBase10(length - 1);
	else if (first == 1)
		// ����������12345�������10000~12345�г���1�Ĵ�����2346,��2345+1.
		numFirstDigit = atoi(strN + 1) + 1;

	// numOtherDigits ��1346~21345���˵�һλ֮�����λ�е���Ŀ
	int numOtherDigits = first * (length - 1) * PowerBase10(length - 2);
	// numRecursive �� 1~1345�е���Ŀ
	int numRecursive = NumberOf1(strN + 1);

	return numFirstDigit + numOtherDigits + numRecursive;
}
int NumberOf1Between1AndN_2(int n){
	if (n <= 0)
		return 0;
	char strN[50];
	sprintf_s(strN, "%d", n);
	return NumberOf1(strN);
}


void Test(int n){
	cout << "Test number = " << n << endl;
	cout << "solution1 result = " << NumberOf1Between1AndN(n) << endl;
	cout << "solution2 result = " << NumberOf1Between1AndN_2(n) << endl;
}

// ����
int main(void){
	int test[] = { 0, 1, 5, 10, 55, 99, 10000, 21345, 31254 };
	for (int i = 0; i < 9; i++)
		Test(test[i]);


	system("pause");
	return 0;
}