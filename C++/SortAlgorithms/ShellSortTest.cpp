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

// ϣ������
void ShellSort(SqList *L){
	int i, j,val;
	int increment = L->length;
	do{
		// ��������
		increment = increment / 3 + 1;
		for (i = increment; i <= L->length - 1; i++){
			if (L->r[i]<L->r[i - increment]){
				// ��L->r[i]�����������,ʹ��val��������������Ԫ��L->r[i]
				val = L->r[i];
				for (j = i - increment; j >= 0 && L->r[j]>val; j -= increment)
					// ��¼���ƣ����Ҳ���λ��
					L->r[j + increment] = L->r[j];
				L->r[j + increment] = val;
			}
		}
	} while (increment > 1);
}

int main(void){
	SqList l;
	int a[] = { 9, 1, 5, 8, 3, 7, 4, 6, 2 };
	int length = 9;
	l.length = length;
	for (int i = 0; i < length; i++){
		l.r[i] = a[i ];
	}
	cout << "original: ";
	for (int i = 0; i < length; i++){
		cout << l.r[i];
		if (i == length-1)
			cout << "\n";
		else
			cout<< ", ";
	}
	ShellSort(&l);
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

