#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*��ֻ��������2,3��5������Ϊ�������󰴴�С�����˳��ĵ�1500��������ϰ���Ͻ�1������һ������ */

// �ж��Ƿ��ǳ���
bool isUgly(int number){
	while (number % 2 == 0)
		number /= 2;
	while (number % 3 == 0)
		number /= 3;
	while (number % 5 == 0)
		number /= 5;

	return (number == 1) ? true : false;
}

// �ⷨ1
int GetUglyNumber(int index){
	if (index <= 0)
		return 0;
	int number = 0;
	int uglyFound = 0;
	while (uglyFound < index){
		++number;
		if (isUgly(number))
			++uglyFound;
	}
	return number;
}
// �ⷨ2
int Min(int number1, int number2, int number3){
	int min = (number1 < number2) ? number1 : number2;
	return (min < number3) ? min : number3;
}
int GetUglyNumber_Solution2(int index){
	if (index <= 0)
		return 0;
	// ����һ�����飬�������г���
	int *pUglyNumbers = new int[index];
	pUglyNumbers[0] = 1;
	int nextUglyIndex = 1;

	int *pMultiply2 = pUglyNumbers;
	int *pMultiply3 = pUglyNumbers;
	int *pMultiply5 = pUglyNumbers;
	while (nextUglyIndex < index){
		int min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
		pUglyNumbers[nextUglyIndex] = min;
		while (*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
			++pMultiply2;
		while (*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
			++pMultiply3;
		while (*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
			++pMultiply5;

		++nextUglyIndex;
	}
	int ugly = pUglyNumbers[nextUglyIndex - 1];
	delete[] pUglyNumbers;
	return ugly;
}


void Test(int index){
	cout << "index = " << index << endl;
	cout << "Solution 1 result = " << GetUglyNumber(index) << endl;
	cout << "Solution 2 result = " << GetUglyNumber_Solution2(index) << endl;
}

// ����
int main(void){
	int t[] = { 0, 1, 2, 5, 6, 50, 100, 150, 1500 };
	for (int i = 0; i < 9; i++)
		Test(t[i]);


	system("pause");
	return 0;
}