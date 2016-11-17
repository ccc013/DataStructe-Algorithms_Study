#include<iostream>

#define MAXSIZE 10	// 待排序数组的个数最大值

using std::cout;
using std::endl;
using std::cin;

typedef struct{
	// 存储待排序数组，r[0]用作哨兵或临时变量
	int r[MAXSIZE + 1];
	int length;
}SqList;

// 交换L中数组r的下标i和j的值
void swap(SqList *L, int i, int j){
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

// 冒泡排序初级版
void BubbleSort0(SqList *L){
	int i, j;
	for (i = 1; i < L->length; i++) {
		for (j = i + 1; j <= L->length; j++){
			if (L->r[i] > L->r[j]){
				// 实现递增排序
				swap(L, i, j);
			}
		}
	}
}

// 正宗的冒泡排序算法实现代码
void BubbleSort(SqList *L){
	int i, j;
	for (i = 1; i < L->length; i++) {
		for (j = L->length - 1; j >= i; j--){
			// j是从后往前循环
			if (L->r[j] > L->r[j + 1]){
				// 实现递增排序
				swap(L, j, j+1);
			}
		}
	}
}

// 改进版冒泡算法
void BubbleSortOptimz(SqList *L){
	int i, j;
	bool flag = true;
	for (int i = 1; i < L->length && flag; i++){
		// 若 flag为false则退出循环
		flag = false;
		for (j = L->length - 1; j >= i; j--){
			// j是从后往前循环
			if (L->r[j] > L->r[j + 1]){
				// 实现递增排序
				swap(L, j, j + 1);
				// 如果有数据交换，则flag是true
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
	for (int i = 1; i <= length; i++){
		l.r[i] = a[i - 1];
	}
	cout << "original: ";
	for (int i = 1; i <= length; i++){
		cout << l.r[i];
		if (i == length)
			cout << "\n";
		else
			cout<< ", ";
	}
	BubbleSortOptimz(&l);
	cout << "After sorting: ";
	for (int i = 1; i <= length; i++){
		cout << l.r[i];
		if (i == length)
			cout << "\n";
		else
			cout << ", ";
	}

	system("pause");
	return 0;
}

