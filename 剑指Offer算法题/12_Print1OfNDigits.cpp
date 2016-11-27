#include<iostream>

using std::cout;
using std::endl;
using std::cin;

// 简单的解法，但遇到输入值很大时会出现问题
void Print1ToMaxOfNDigits_1(int n){
	int number = 1;
	int i = 0;
	while (i++ < n)
		number *= 10;
	for (i = 1; i < number; i++)
		cout << i << " ";
	cout << endl;
}

bool Increment(char* number){
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);
	for (int i = nLength - 1; i >= 0; i--){
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1)
			nSum++;
		if (nSum >= 10){
			if (i == 0)
				isOverflow = true;
			else{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else{
			number[i] = '0' + nSum;
			break;
		}
	}
	return isOverflow;
}
// 打印用字符串表示的数字
void PrintNumber(char* number){
	bool isBeginning0 = true;
	int nLength = strlen(number);

	for (int i = 0; i < nLength; ++i){
		if (isBeginning0 && number[i] != '0')
			isBeginning0 = false;
		if (!isBeginning0)
			printf("%c", number[i]);
	}
	printf("\t");
}
// 递归方法
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index){
	if (index == length - 1){
		PrintNumber(number);
		return;
	}
	for (int i = 0; i < 10; i++){
		number[index + 1] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
	}
}
// 利用字符串来表达大数
void Print1ToMaxOfNDigits_str(int n){
	if (n <= 0)
		return;
	// 初始化为'0'
	char *numbers = new char[n + 1];
	//memset(numbers, '0', n);
	numbers[n] = '\0';

	/*while (!Increment(numbers)){
		PrintNumber(numbers);
	}*/
	for (int i = 0; i < 10; ++i){
		numbers[0] = i + '0';
		Print1ToMaxOfNDigitsRecursively(numbers, n, 0);
	}

	delete[] numbers;
}

// 测试
int main(void){
	int t[] = { 0, 1, 3, -1 };
	for (int i = 0; i < 4; i++){
		cout << "test num=" << t[i] << ": \n";
		Print1ToMaxOfNDigits_str(t[i]);
		cout << endl;
	}

	system("pause");
	return 0;
}