#include<iostream>

using std::cout;
using std::endl;
using std::cin;
// 常规解法，判断二进制数中1的个数
int NumbersOf1(int n){
	int count = 0;
	unsigned int flag = 1;
	while (flag){
		if (n & flag)
			count++;
		flag = flag << 1;
	}
	return count;
}
// 改进算法
int NumbersOf1Optimiz(int n){
	int count = 0;

	while (n){
		++count;
		n = (n - 1) & n;
	}
	return count;
}
// 测试
int main(void){
	int a[] = { 0, 1,9, 0x7FFFFFFF, 0x80000000, 0xFFFFFFFF };
	for (int i = 0; i < 6; i++){
		int num = a[i];
		cout << "test number = " << num << ", numbersOf1 = " << NumbersOf1(num) << endl;
		cout << "test number = " << num << ", NumbersOf1Optimiz = " << NumbersOf1Optimiz(num) << endl;
	}

	system("pause");
	return 0;
}