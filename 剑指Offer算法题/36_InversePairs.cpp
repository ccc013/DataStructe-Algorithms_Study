#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*在数组中的两个数字如果前面一个大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组逆序对的总数 */

// 解法
int InversePairsCore(int* data, int* copy, int start, int end){
	if (start == end){
		copy[start] = data[end];
		return 0;
	}
	int length = (end - start) / 2;
	int left = InversePairsCore(copy, data, start, start + length);
	int right = InversePairsCore(copy, data, start + length + 1, end);

	// i初始化为前半段最后一个数字的下标
	int i = start + length;
	// j 初始化为后半段最后一个数字的下标
	int j = end;
	int indexCopy = end;
	int count = 0;
	while (i >= start && j >= start + length + 1){
		if (data[i] > data[j]){
			copy[indexCopy--] = data[i--];
			count += j - start - length;
		}
		else{
			copy[indexCopy--] = data[j--];
		}
	}
	for (; i >= start; --i)
		copy[indexCopy--] = data[i];
	for (; j >= start + length + 1; j--)
		copy[indexCopy--] = data[j];
	return left + right + count;
}

int InversePairs(int* data, int length){
	if (data == NULL || length <= 0)
		return 0;
	int *copy = new int[length];
	for (int i = 0; i < length; i++)
		copy[i] = data[i];

	int count = InversePairsCore(data, copy, 0, length - 1);
	delete[] copy;
	return count;
}

void Test(int *numbers, int length){
	if (numbers == NULL || length <= 0)
		cout << "wrong input\n";
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
	int result = InversePairs(numbers, length);
	cout << "result = " << result << endl;

}

// 测试
int main(void){
	int t1[] = { 7, 5, 6, 4 };
	Test(t1, 4);
	int t2[] = { 1, 2, 3, 4 };
	Test(t2, 4);
	int t3[] = { 6, 5, 4, 2 };
	Test(t3, 4);
	int t4[] = { 1, 2, 1, 3, 4, 2, 5 };
	Test(t4, 7);
	int t5[] = { 2, 1 };
	Test(t5, 2);
	int t6[] = { 1 };
	Test(t6, 1);

	Test(NULL, 1);


	system("pause");
	return 0;
}