#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::endl;
using std::cin;

/*�������� */

//���δ��������������һ��Ԫ��ֵ
int GetMaxVal(int* arr, int len)
{
	int maxVal = arr[0]; //�������Ϊarr[0]

	for (int i = 1; i < len; i++)  //�����Ƚϣ��ҵ���ľ͸�ֵ��maxVal
	{
		if (arr[i] > maxVal)
			maxVal = arr[i];
	}

	return maxVal;  //�������ֵ
}
void CountSort(int *numbers, int length, int max){
	if (numbers == NULL || length <= 0){
		cout << "wrong input!";
		return;
	}
	vector<int> bucket(max, 0);
	/*for (int i = 0; i < length + 1; i++){
	bucket[i] = 0;
	}*/
	// ����������ÿ��Ԫ�س��ֵĴ���
	for (int i = 0; i < length; i++){
		bucket[numbers[i]] ++;
	}
	// ����
	int count = 0;
	for (int i = 0; i < max; i++){
		if (bucket[i] > 0){
			for (int j = 0; j < bucket[i]; j++){
				numbers[count++] = i;
			}
		}
	}
}
// �ڶ��ּ������򷽷�
int ctsort(int *data, int size, int k)
{
	int * counts = NULL,/*��������*/
		*temp = NULL;/*��������������*/
	int i = 0;
	/*��������ռ�*/
	if ((counts = (int *)malloc(k * sizeof(int))) == NULL)
		return -1;
	if ((temp = (int *)malloc(k * sizeof(int))) == NULL)
		return -1;
	/*��ʼ����������*/
	for (i = 0; i < k; i++)
		counts[i] = 0;
	/*�����г��ֵ�Ԫ�أ������ִ�����¼*/
	for (i = 0; i < size; i++)
		counts[data[i]] += 1;
	/*����Ԫ�ؼ����У�����ǰһ��������¼���ȸ�λ�õ�Ԫ��i��ĸ���*/
	for (i = 1; i < k; i++)
		counts[i] += counts[i - 1];
	/*ʹ�ü��������еļ�¼��ֵ����������������󱣴��temp*/
	for (i = size - 1; i >= 0; i--){
		// ��һ�Ǽ�ȥdata[i]����
		counts[data[i]] -= 1;
		temp[counts[data[i]]] = data[i];
	}

	memcpy(data, temp, size * sizeof(int));
	free(counts);
	free(temp);
	return 0;
}


void Test(int *numbers, int length){
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
	int max = GetMaxVal(numbers, length) + 1;
	CountSort(numbers, length,max);
	if (numbers != NULL){
		cout << "after using BucketSort: ";
		for (int i = 0; i < length; i++){
			cout << numbers[i];
			if (i == length - 1)
				cout << "\n";
			else
				cout << ", ";
		}
	}
}

// ����
int main(void){
	int t1[] = { 1, 3, 5, 2, 4, 8, 10, 9 };
	int t2[] = { 1, 1, 3, 2, 2, 5, 6, 2, 10, 12, 8, 3 };
	Test(t1, 8);
	Test(t2, 12);
	Test(NULL, 2);


	system("pause");
	return 0;
}