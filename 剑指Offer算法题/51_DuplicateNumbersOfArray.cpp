#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/* 在一个长度为n的数组里所有数字都在0到n-1的范围内，请找出数组中任意一个重复的数字。 */
bool duplicate(int numbers[], int length, int* duplication){
	if (numbers == NULL || length <= 0){
		cout << "invalid input\n";
		return false;
	}
	for (int i = 0; i < length; ++i){
		// 保证数组都在0到n-1的范围
		if (numbers[i] < 0 || numbers[i] > length - 1){
			cout << "numbers must be in 0 - " << length - 1 << ".\n";
			return false;
		}
	}
	for (int i = 0; i < length; ++i){
		while (numbers[i] != i){
			if (numbers[i] == numbers[numbers[i]]){
				*duplication = numbers[i];
				return true;
			}
			// 交换当前元素和坐标值为当前元素值的数组元素
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;
}


void Test(int numbers[], int length){
	if (numbers != NULL){
		cout << "Test array: ";
		for (int i = 0; i < length; i++)
			cout << numbers[i] << " ";
		cout << endl;
	}
	else
		cout << "Test Null array: ";
	int *duplication = new int;
	if (duplicate(numbers, length, duplication))
		cout << "duplicate number = " << *duplication << endl;
	else
		cout << "no duplicate number.\n";
}

// 测试
int main(void){
	int t[] = { 1, 3, 2, 4, 5, 2, 1 };
	Test(t, 7);
	int t2[] = { 2, 3, 1, 4, 0 };
	Test(t2, 5);
	Test(NULL, 1);
	

	system("pause");
	return 0;
}