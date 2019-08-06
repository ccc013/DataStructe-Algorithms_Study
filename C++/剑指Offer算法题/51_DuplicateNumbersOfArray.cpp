#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/* ��һ������Ϊn���������������ֶ���0��n-1�ķ�Χ�ڣ����ҳ�����������һ���ظ������֡� */
bool duplicate(int numbers[], int length, int* duplication){
	if (numbers == NULL || length <= 0){
		cout << "invalid input\n";
		return false;
	}
	for (int i = 0; i < length; ++i){
		// ��֤���鶼��0��n-1�ķ�Χ
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
			// ������ǰԪ�غ�����ֵΪ��ǰԪ��ֵ������Ԫ��
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

// ����
int main(void){
	int t[] = { 1, 3, 2, 4, 5, 2, 1 };
	Test(t, 7);
	int t2[] = { 2, 3, 1, 4, 0 };
	Test(t2, 5);
	Test(NULL, 1);
	

	system("pause");
	return 0;
}