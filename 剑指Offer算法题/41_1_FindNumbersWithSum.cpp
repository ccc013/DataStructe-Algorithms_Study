#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对符合的数字，输出任意一对即可 */

// 实现代码，使用两个指针，分别指向数组第一位和最后一位
bool FindNumbersWithSum(int* numbers, int length, int sum, int *num1, int *num2){
	bool found = false;
	if (length < 1 || num1 == NULL || num2 == NULL)
		return found;
	int ahead = 0;
	int behind = length - 1;
	while (ahead < behind){
		long long curSum = numbers[ahead] + numbers[behind];
		if (curSum == sum){
			*num1 = numbers[ahead];
			*num2 = numbers[behind];
			found = true;
			break;
		}
		else if (curSum > sum)
			// 如果当前数字和大于sum，则让第二个指针往前移动
			behind--;
		else
			ahead++;
	}

	return found;
}

void Test(int* numbers, int length, int sum){
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
		cout << "sum numbers = " << sum << endl;
	}
	int *num1 = new int;
	int *num2 = new int;
	bool res = FindNumbersWithSum(numbers, length, sum, num1, num2);
	if (num1 != NULL && num2 != NULL && res){
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
	Test(t1, 8, 6);
	int t2[] = { 2, 1, 3, 4, 5, 2, 3, 4 };
	Test(t2, 8, 7);
	Test(t2, 8, 10);
	Test(NULL, 1, 9);

	system("pause");
	return 0;
}