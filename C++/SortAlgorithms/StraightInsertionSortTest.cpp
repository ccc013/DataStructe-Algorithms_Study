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

// ֱ�Ӳ�������
void InsertSort(SqList *L){
	int i, j,val;
	for (i = 1; i <= L->length - 1; i++){
		if (L->r[i] < L->r[i - 1]){
			// ��L->r[i]�����������,ʹ��val��������������Ԫ��L->r[i]
			val = L->r[i];
			for (j = i - 1; j >= 0 && L->r[j]>val; j--)
				// ��¼����
				L->r[j + 1] = L->r[j];	
			// ���뵽��ȷλ��
			L->r[j + 1] =val;
		}
	}
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
	InsertSort(&l);
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

