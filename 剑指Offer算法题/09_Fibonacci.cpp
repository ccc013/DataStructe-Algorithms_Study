#include<iostream>

using std::cout;
using std::endl;
using std::cin;
// 递归的解法
long long Fibonacci(unsigned int n){
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}
// 改进版本
long long FibonacciOptimz(unsigned int n){
	int result[2] = { 0, 1 };
	if (n < 2)
		return result[n];

	long long fibNMinusOne = 1;
	long long fibNMinusTwo = 0;
	long long fibN = 0;
	for (unsigned int i = 2; i <= n; i++){
		fibN = fibNMinusOne + fibNMinusTwo;

		fibNMinusTwo = fibNMinusOne;
		fibNMinusOne = fibN;
	}

	return fibN;
}

// 测试
int main(void){
	int n = 10;
	cout << "use Fibonacci(), n = " << n << ", result = " << Fibonacci(n) << endl;
	cout << "use FibonacciOptimz(), n = " << n << ", result = " << FibonacciOptimz(n) << endl;
	cout << "start to test:\n";
	int test[] = { 0, 1, 2, 3, 5, 10, 40, 50, 100 };
	for (int i = 0; i < 9; i++){
		int num = test[i];
		cout << "use FibonacciOptimz(), num = " << num << ", result = " << FibonacciOptimz(num) << endl;
	}

	system("pause");
	return 0;
}