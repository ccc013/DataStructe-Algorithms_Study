#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*统计一个数字在一个排序数组中出现的次数 */

// 解法，分别找到第一次出现的位置和最后一次出现的位置
// 寻找第一次出现的位置
int GetFirstK(int *data, int length, int k, int start, int end){
	if (start > end)
		return -1;
	int middleIndex = (end + start) / 2;
	int middleData = data[middleIndex];

	if (middleData == k){
		// 判断中间值是否就是第一个k值
		if (middleIndex > 0 && data[middleIndex - 1] != k || middleIndex == 0)
			return middleIndex;
		else
			// 第一个k值应该在前面
			end = middleIndex - 1;
	}
	else if (middleData > k)
		end = middleIndex - 1;
	else
		start = middleIndex + 1;

	return GetFirstK(data, length, k, start, end);
}
// 寻找最后一个k值的位置
int GetLastK(int *data, int length, int k, int start, int end){
	if (start > end)
		return -1;
	int middleIndex = (end + start) / 2;
	int middleData = data[middleIndex];

	if (middleData == k){
		if (middleIndex < length - 1 && data[middleIndex + 1] != k
			|| middleIndex == length - 1)
			return middleIndex;
		else
			start = middleIndex + 1;
	}
	else if (middleData < k)
		start = middleIndex + 1;
	else
		end = middleIndex - 1;
	return GetLastK(data, length, k, start, end);
}
// 实现
int GetNumberOfK(int *data, int length, int k){
	int number = -1;
	if (data != NULL && length > 0){
		int first = GetFirstK(data, length, k, 0, length - 1);
		int last = GetLastK(data, length, k, 0, length - 1);
		if (first > -1 && last > -1)
			number = last - first + 1;
	}
	return number;
}

void Test(int *numbers, int length, int k){
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
		cout << "Find value = " << k << endl;
	}
	int number = GetNumberOfK(numbers, length, k);
	if (number != -1)
		cout << "numbers = " << number << endl;
	else
		cout << "wrong input\n";
}

// 测试
int main(void){
	int t1[] = { 1, 2, 3, 3, 4, 5, 6 };
	Test(t1, 7, 3);
	// 数组不存在查找的数值
	Test(t1, 7, 7);
	// 查找数组的最大值
	Test(t1, 7, 6);
	// 查找数组的最小值
	Test(t1, 7, 1);
	// 数组只有一个数字
	int t2[] = { 1 };
	Test(t2, 1, 1);
	// NULL数组
	Test(NULL, 1, 1);




	system("pause");
	return 0;
}