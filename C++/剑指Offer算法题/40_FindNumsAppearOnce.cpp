#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*一个整型数组里除了两个数字之外，其他的数字都出现了两次，请找出这两个只出现一次的数字。要求时间复杂度是O(n),空间复杂度是O(1) */

// 判断num的二进制表示中从右边数起的indexBit位是不是1
bool isBit1(int num, unsigned int indexBit){
	num = num >> indexBit;
	return (num & 1);
}
// 在整数num的二进制表示中找到最右边是1的位
unsigned int FindFirstBitIs1(int num){
	int indexBit = 0;
	while (((num & 1) == 0) && (indexBit < 8 * sizeof(int))){
		num = num >> 1;
		++indexBit;
	}
	return indexBit;
}
// 实现
void FindNumsAppearOnce(int data[], int length, int* num1, int* num2){
	if (data == NULL || length < 2)
		return;

	int resultExclusiveOR = 0;
	// 对整个数组进行异或
	for (int i = 0; i < length; i++)
		resultExclusiveOR ^= data[i];
	// 找到异或结果中第一个位为1的位置
	unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);
	*num1 = *num2 = 0;
	for (int j = 0; j < length; j++){
		// 根据数组元素的indexOf1位置是否为1分为两个子数组，分别进行异或，得到的最终结果就是目标的两个数字
		if (isBit1(data[j], indexOf1)){
			*num1 ^= data[j];
		}
		else{
			*num2 ^= data[j];
		}
	}
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
	int *num1 = new int;
	int *num2 = new int;
	FindNumsAppearOnce(numbers, length, num1, num2);
	if (num1 != NULL && num2 != NULL){
		cout << "result num1 = " << *num1 << ", num2 = " << *num2 << endl;
	}
	else
		cout << "wrong input\n";
	delete num1;
	delete num2;
}

// 测试
int main(void){
	int t1[] = { 2, 4, 3, 6, 3, 2, 5, 5};
	Test(t1, 8);
	int t2[] = { 2, 1, 3, 4, 5, 2, 3, 4 };
	Test(t2, 8);

	

	system("pause");
	return 0;
}