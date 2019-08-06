#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*���˿����������5���ƣ��ж��ǲ���һ��˳�ӣ�����5�����ǲ��������ġ�2-10Ϊ���ֱ���A��1��J,Q,K�ֱ���11,12,13������С����������������*/
int compare(const void *arg1, const void *arg2){
	return *(int *)arg1 - *(int *)arg2;
}

bool isContinuous(int* numbers, int length){
	if (numbers == NULL || length < 1)
		return false;
	// ��������
	qsort(numbers, length, sizeof(int), compare);
	int numberOfZero = 0;
	int numberOfGap = 0;
	// ͳ��������0�ĸ���
	for (int i = 0; i < length && numbers[i] == 0; i++)
		++numberOfZero;
	// ͳ�������еļ����Ŀ
	int small = numberOfZero;
	int big = small + 1;
	while (big < length){
		// ��������ȣ��ж��ӣ���������˳��
		if (numbers[small] == numbers[big])
			return false;
		numberOfGap += numbers[big] - numbers[small] - 1;
		small = big;
		big++;
	}
	return (numberOfGap > numberOfZero) ? false : true;
}

void Test(int* numbers, int length){
	if (numbers == NULL || length < 1){
		cout << "wrong input" << endl;
		return;
	}
	else{
		cout << "input array: ";
		for (int i = 0; i < length; i++)
			cout << numbers[i] << " ";
		cout << endl;
	}
	if (isContinuous(numbers, length))
		cout << "array is continuous\n";
	else
		cout << "array isn't continuous\n";
}

// ����
int main(void){
	int t1[] = { 0, 1, 3, 4, 5 };
	Test(t1, 5);
	int t2[] = { 0, 0, 2, 4, 5 };
	Test(t2, 5);
	int t3[] = { 9, 5, 7, 6, 8 };
	Test(t3, 5);
	int t4[] = { 1, 3, 9, 2, 1 };
	Test(t4, 5);
	int t5[] = { 11, 2, 3, 13, 10 };
	Test(t5, 5);
	Test(NULL, 5);
	

	system("pause");
	return 0;
}