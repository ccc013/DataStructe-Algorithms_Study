#include<iostream>

using std::cout;
using std::endl;
using std::cin;

bool g_InvalidInput = false;

// 判断num1是否等于num2
bool equal(double num1, double num2){
	if ((num1 - num2) > -0.0000001
		&& (num1 - num2) < 0.0000001)
		return true;
	else
		return false;
}
// 求指数是正数的结果
double PowerWithUnsignedExponent(double base, unsigned int exponent){
	double result = 1.0;
	for (int i = 1; i <= exponent; i++)
		result *= base;

	return result;
}
// 改进版本
double PowerWithUnsignedExponentOptimz(double base, unsigned int exponent){
	if (exponent == 0)
		return 0;
	if (exponent == 1)
		return base;

	double result = PowerWithUnsignedExponentOptimz(base, exponent >> 1);
	result *= result;
	if (exponent & 0x1 == 1)
		// 如果指数是奇数
		result *= base;

	return result;
}

double Power(double base, int exponent){
	g_InvalidInput = false;
	// 非法输入
	if (equal(base, 0.0) && exponent < 0){
		g_InvalidInput = true;
		return 0.0;
	}

	unsigned int absExponent = (unsigned int)(exponent);
	if (exponent < 0)
		absExponent = (unsigned int)(-exponent);

	//double result = PowerWithUnsignedExponent(base, absExponent);
	double result = PowerWithUnsignedExponentOptimz(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;

	return result;
}

// 测试
int main(void){
	double base[] = { 0, 2.2, -2.2, 3, -4 };
	int exponents[] = { 0, 1, 3, -2 };
	for (int i = 0; i < 5; i++){
		double b = base[i];
		for (int j = 0; j < 4; j++){
			int e = exponents[j];
			cout << "base= " << b << ", exponent = " << e;
			double res = Power(b, e);
			if (!g_InvalidInput)
				cout << ", result = " <<res << endl;
			else
				cout << ", Invalid input." << endl;
		}
	}

	system("pause");
	return 0;
}