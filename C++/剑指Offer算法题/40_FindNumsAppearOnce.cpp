#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*һ�����������������������֮�⣬���������ֶ����������Σ����ҳ�������ֻ����һ�ε����֡�Ҫ��ʱ�临�Ӷ���O(n),�ռ临�Ӷ���O(1) */

// �ж�num�Ķ����Ʊ�ʾ�д��ұ������indexBitλ�ǲ���1
bool isBit1(int num, unsigned int indexBit){
	num = num >> indexBit;
	return (num & 1);
}
// ������num�Ķ����Ʊ�ʾ���ҵ����ұ���1��λ
unsigned int FindFirstBitIs1(int num){
	int indexBit = 0;
	while (((num & 1) == 0) && (indexBit < 8 * sizeof(int))){
		num = num >> 1;
		++indexBit;
	}
	return indexBit;
}
// ʵ��
void FindNumsAppearOnce(int data[], int length, int* num1, int* num2){
	if (data == NULL || length < 2)
		return;

	int resultExclusiveOR = 0;
	// ����������������
	for (int i = 0; i < length; i++)
		resultExclusiveOR ^= data[i];
	// �ҵ�������е�һ��λΪ1��λ��
	unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);
	*num1 = *num2 = 0;
	for (int j = 0; j < length; j++){
		// ��������Ԫ�ص�indexOf1λ���Ƿ�Ϊ1��Ϊ���������飬�ֱ������򣬵õ������ս������Ŀ�����������
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

// ����
int main(void){
	int t1[] = { 2, 4, 3, 6, 3, 2, 5, 5};
	Test(t1, 8);
	int t2[] = { 2, 1, 3, 4, 5, 2, 3, 4 };
	Test(t2, 8);

	

	system("pause");
	return 0;
}