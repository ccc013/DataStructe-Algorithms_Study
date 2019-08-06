#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*输入一个整型数组，求所有子数组和的最大值，要求时间复杂度是O(n) */
bool g_bInputInvalid = false;
// 实现代码
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
			// 如果和为负值，抛弃前面的数值，重新开始计算子数组的和
			nCurSum = pData[i];
		else
			nCurSum += pData[i];

		if (nCurSum > nGreatestSum)
			// 保存当前子数组和的最大值
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

// 测试
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