#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数 */

// 解法1，时间复杂度是O(nlogn)
int NumberOf1(unsigned int n){
	int number = 0;
	while (n){
		if (n % 10 == 1)
			number++;
		n = n / 10;
	}
	return number;
}
int NumberOf1Between1AndN(unsigned int n){
	int number = 0;
	for (unsigned int i = 1; i <= n; i++)
		number += NumberOf1(i);
	return number;
}

// 解法2，时间复杂度是O(logn)，更优的解法
int PowerBase10(unsigned int n){
	int result = 1;
	for (unsigned int i = 0; i < n; i++)
		result *= 10;
	return result;
}
int NumberOf1(const char* strN){
	if (!strN || *strN < '0' || *strN > '9' || *strN == '\0')
		return 0;
	int first = *strN - '0';
	unsigned int length = static_cast<unsigned int>(strlen(strN));
	if (length == 1 && first == 0)
		return 0;
	if (length == 1 && first > 0)
		return 1;
	// 假设strN是“21345”，numFirstDigit 是数字10000~19999的第一个位中的数目
	int numFirstDigit = 0;
	if (first > 1)
		numFirstDigit = PowerBase10(length - 1);
	else if (first == 1)
		// 如果输入的是12345，则对于10000~12345中出现1的次数是2346,即2345+1.
		numFirstDigit = atoi(strN + 1) + 1;

	// numOtherDigits 是1346~21345除了第一位之外的数位中的数目
	int numOtherDigits = first * (length - 1) * PowerBase10(length - 2);
	// numRecursive 是 1~1345中的数目
	int numRecursive = NumberOf1(strN + 1);

	return numFirstDigit + numOtherDigits + numRecursive;
}
int NumberOf1Between1AndN_2(int n){
	if (n <= 0)
		return 0;
	char strN[50];
	sprintf_s(strN, "%d", n);
	return NumberOf1(strN);
}


void Test(int n){
	cout << "Test number = " << n << endl;
	cout << "solution1 result = " << NumberOf1Between1AndN(n) << endl;
	cout << "solution2 result = " << NumberOf1Between1AndN_2(n) << endl;
}

// 测试
int main(void){
	int test[] = { 0, 1, 5, 10, 55, 99, 10000, 21345, 31254 };
	for (int i = 0; i < 9; i++)
		Test(test[i]);


	system("pause");
	return 0;
}