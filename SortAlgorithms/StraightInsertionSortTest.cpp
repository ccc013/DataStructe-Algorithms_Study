#include<iostream>

#define MAXSIZE 10	// 待排序数组的个数最大值

using std::cout;
using std::endl;
using std::cin;

typedef struct{
	// 存储待排序数组
	int r[MAXSIZE];
	int length;
}SqList;

// 交换L中数组r的下标i和j的值
void swap(SqList *L, int i, int j){
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

// 直接插入排序
void InsertSort(SqList *L){
	int i, j,val;
	for (i = 1; i <= L->length - 1; i++){
		if (L->r[i] < L->r[i - 1]){
			// 将L->r[i]插入有序表中,使用val保存待插入的数组元素L->r[i]
			val = L->r[i];
			for (j = i - 1; j >= 0 && L->r[j]>val; j--)
				// 记录后移
				L->r[j + 1] = L->r[j];	
			// 插入到正确位置
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

