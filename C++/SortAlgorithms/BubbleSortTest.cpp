#include<iostream>

#define MAXSIZE 10	// ����������ĸ������ֵ

using std::cout;
using std::endl;
using std::cin;

typedef struct{
	// �洢����������
	int r[MAXSIZE];
	int length;
}SqList;

// ����L������r���±�i��j��ֵ
void swap(SqList *L, int i, int j){
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

// ð�����������
void BubbleSort0(SqList *L){
	int i, j;
	for (i = 0; i < L->length-1; i++) {
		for (j = i + 1; j <= L->length-1; j++){
			if (L->r[i] > L->r[j]){
				// ʵ�ֵ�������
				swap(L, i, j);
			}
		}
	}
}

// ���ڵ�ð�������㷨ʵ�ִ���
void BubbleSort(SqList *L){
	int i, j;
	for (i = 0; i < L->length; i++) {
		for (j = L->length-2; j >= i; j--){
			// j�ǴӺ���ǰѭ��
			if (L->r[j] > L->r[j + 1]){
				// ʵ�ֵ�������
				swap(L, j, j+1);
			}
		}
	}
}

// �Ľ���ð���㷨
void BubbleSortOptimz(SqList *L){
	int i, j;
	bool flag = true;
	for (int i = 0; i < L->length && flag; i++){
		// �� flagΪfalse���˳�ѭ��
		flag = false;
		for (j = L->length-2; j >= i; j--){
			// j�ǴӺ���ǰѭ��
			if (L->r[j] > L->r[j + 1]){
				// ʵ�ֵ�������
				swap(L, j, j + 1);
				// ��������ݽ�������flag��true
				flag = true;
			}
		}
	}
}


int main(void){
	SqList l;
	int a[] = { 9, 1, 5, 8, 3, 7, 4, 6, 2 };
	int length = 9;
	l.length = length;
	for (int i = 0; i < length; i++){
		l.r[i] = a[i];
	}
	cout << "original: ";
	for (int i = 0; i < length; i++){
		cout << l.r[i];
		if (i == length-1)
			cout << "\n";
		else
			cout<< ", ";
	}
	BubbleSortOptimz(&l);
	cout << "After sorting: ";
	for (int i = 0; i < length; i++){
		cout << l.r[i];
		if (i == length-1)
			cout << "\n";
		else
			cout << ", ";
	}

	system("pause");
	return 0;
}

