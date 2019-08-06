#include<iostream>

using std::cout;
using std::endl;
using std::cin;
// ˳�����
int MinInOrder(int* numbers, int index1, int index2){
	int result = numbers[index1];
	for (int i = index1 + 1; i < index2; i++){
		if (result>numbers[i])
			result = numbers[i];
	}
	return result;
}
// Ѱ����ת�������Сֵ
int Min(int* numbers, int length){
	if (numbers == NULL || length <= 0){
		throw new std::exception("Invaild parameters.\n");
	}

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	while (numbers[index1] >= numbers[index2]){
		if (index2 - index1 == 1){
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2) / 2;
		// ����±�Ϊindex1��index2��indexMidָ������ֶ���ȣ�ֻ��ʹ��˳�����
		if (numbers[index1] == numbers[index2]
			&& numbers[index1] == numbers[indexMid])
			return MinInOrder(numbers, index1, index2);

		if (numbers[indexMid] > numbers[index1])
			index1 = indexMid;
		else if (numbers[indexMid] <= numbers[index2])
			index2 = indexMid;
	}

	return numbers[indexMid];
		
}

// ����
int main(void){
	// �������������һ��ѡ������
	int a1[5] = { 3, 4, 5, 1, 2 };
	cout << "min = " << Min(a1, 5) << endl;
	// ���ظ�����
	int a2[5] = { 3, 4, 5, 1, 1 };
	cout << "min = " << Min(a2, 5) << endl;
	// ������������
	int a3[5] = { 2, 3, 4, 5, 6 };
	cout << "min = " << Min(a3, 5) << endl;
	// ֻ��һ������
	int a4[1] = { 4 };
	cout << "min = " << Min(a4, 1) << endl;
	// ��������
	int a5[5] = { 1, 0, 1, 1, 1 };
	cout << "min = " << Min(a5, 5) << endl;
	int a6[] = { 1, 1, 1, 0, 1 };
	cout << "min = " << Min(a6, 5) << endl;

	system("pause");
	return 0;
}