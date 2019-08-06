#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*����һ���������飬������������͵����ֵ��Ҫ��ʱ�临�Ӷ���O(n) */
bool g_bInputInvalid = false;
// ʵ�ִ���
int FindGreatestSumOfSubArray(int *pData, int nLength){
	if (pData == NULL || nLength <= 0){
		g_bInputInvalid = true;
		return 0;
	}
	g_bInputInvalid = false;
	int nCurSum = 0;
	int nGreatestSum = 0x80000000;
	for (int i = 0; i < nLength; i++){
		if (nCurSum <= 0)
			// �����Ϊ��ֵ������ǰ�����ֵ�����¿�ʼ����������ĺ�
			nCurSum = pData[i];
		else
			nCurSum += pData[i];

		if (nCurSum > nGreatestSum)
			// ���浱ǰ������͵����ֵ
			nGreatestSum = nCurSum;
	}
	return nGreatestSum;
}



void Test(int *numbers, int length){
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
	int result = FindGreatestSumOfSubArray(numbers, length);
	if (g_bInputInvalid)
		cout << "wrong input!\n";
	else
		cout << "result = " << result << endl;
}

// ����
int main(void){
	int a1[] = { 1, -2, 3, 10, -4, 7, 2, -5};
	Test(a1, 8);
	int a2[] = { 1, 2, 3, 0, 5 };
	Test(a2, 5);
	int a3[] = { -1, -3, -5, -6, -2 };
	Test(a3, 5);

	Test(NULL, 1);


	system("pause");
	return 0;
}