#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*数组中有一个数字出现次数超过数组长度的一半，请找出该数字 */
bool g_bInputInvalid = false;
bool CheckInvalidArray(int *numbers, int length){
	// 检查输入的数组是否是有效的
	g_bInputInvalid = false;
	if (numbers == NULL || length <= 0)
		g_bInputInvalid = true;
	return g_bInputInvalid;
}
bool CheckMoreThanHalf(int *numbers, int length, int number){
	int times = 0;
	for (int i = 0; i < length; i++){
		if (number == numbers[i])
			times++;
	}
	bool isMoreThanHalf = true;
	if (times * 2 <= length){
		g_bInputInvalid = true;
		isMoreThanHalf = false;
	}
	return isMoreThanHalf;
}
void swap(int &a, int &b)
{
	int temp = b;
	b = a;
	a = temp;
}
// 产生随机数
int RandomInRange(int start, int end){
	return rand() % (end - start + 1)+start;
}
int Partition(int* numbers, int length, int start, int end){
	if (numbers == NULL || length <= 0 || start < 0 || end >= length){
		cout << "Invalid Parameters!\n";
		g_bInputInvalid = true;
		return -1;
	}
	int index = RandomInRange(start, end);
	swap(numbers[index], numbers[end]);
	int small = start - 1;
	for (index = start; index < end; ++index){
		if (numbers[index] < numbers[end]){
			++small;
			if (small != index)
				swap(numbers[index], numbers[small]);
		}
	}
	++small;
	swap(numbers[small], numbers[end]);
	return small;
}
// 实现代码
int MoreThanHalfNum1(int *numbers, int length){
	if (CheckInvalidArray(numbers, length))
		return -1;
	// 符合要求的数字一定是数组的中位数
	int middle = length >> 1;
	int start = 0;
	int end = length - 1;
	// 对数组进行排序，使得index左边的数字都小于index的数值，右边都比它大
	int index = Partition(numbers, length, start, end);
	while (index != middle){
		if (index > middle){
			end = index - 1;
			index = Partition(numbers, length, start, end);
		}
		else{
			start = index + 1;
			index = Partition(numbers, length, start, end);
		}
	}
	int result = numbers[middle];
	// 确定结果是否符合要求，超过数组长度的一半
	if (!CheckMoreThanHalf(numbers, length, result))
		result = -1;
	return result;
}
// 解法2
int MoreThanHalfNum2(int* numbers, int length){
	if (CheckInvalidArray(numbers, length))
		return -1;
	int result = numbers[0];
	int times = 1;
	for (int i = 1; i < length; i++){
		if (times == 0){
			result = numbers[i];
			times = 1;
		}
		else if (numbers[i] == result){
			++times;
		}
		else
			times--;
	}
	// 确定结果是否符合要求，超过数组长度的一半
	if (!CheckMoreThanHalf(numbers, length, result))
		result = -1;
	return result;
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
	int result = MoreThanHalfNum1(numbers, length);
	int result2 = MoreThanHalfNum2(numbers, length);
	if (g_bInputInvalid)
		cout << "wrong input!\n";
	else{
		cout << "Solution1 result = " << result << endl;
		cout << "Solution2 result = " << result2 << endl;
	}
		
}

// 测试
int main(void){
	int a1[] = { 1, 2, 2, 3, 4, 5, 6 };
	Test(a1, 7);
	int a2[] = { 2, 2, 3, 3, 3, 3, 2 };
	Test(a2, 7);
	int a3[] = { 1 };
	Test(a3, 1);

	Test(NULL, 1);


	system("pause");
	return 0;
}