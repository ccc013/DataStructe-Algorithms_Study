#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/* 写一个函数，求两个整数之和，要求在你函数体内不得使用加减乘除四则运算符号。*/

int Add(int num1, int num2){
	int sum, carry;
	do{
		// 先异或计算每个位
		sum = num1 ^ num2;
		// 位与运算，求进位
		carry = (num1 & num2) << 1;

		num1 = sum;
		num2 = carry;
	} while (num2 != 0);

	return num1;
}

void Test(int num1, int num2){
	cout << num1 << " + " << num2 << " = " << Add(num1, num2) << endl;
}

// 测试
int main(void){
	Test(12, 14);
	Test(2, 0);
	Test(1, -2);
	Test(0, -2);
	Test(-2, -5);
	

	system("pause");
	return 0;
}