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

// 将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n]
void Merge(int SR[], int TR[], int i, int m, int n){
	int j, k, l;
	for (j = m+1, k = i; i <= m && j <= n; k++){
		// 将SR中记录由小到大并入TR
		if (SR[i] < SR[j])
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
	if (i <= m){
		for (l = 0; l <= m - i; l++)
			// 将剩余的SR[i..m]复制到TR
			TR[k + l] = SR[i + l];
	}
	if (j <= n){
		for (l = 0; l <= n - j; l++)
			// 将剩余的SR[j..n-1]复制到TR
			TR[k + l] = SR[j + l];
	}
}

// 将SR[s..t]归并排序为TR1[s..t]
void MSort(int SR[], int TR1[], int s, int t){
	int m;
	int TR2[MAXSIZE];
	if (s == t)
		TR1[s] = SR[s];
	else{
		// 将SR[s..t]平分为SR[s...m-1]和SR[m...t]
		m = (s + t) / 2+1;
		MSort(SR, TR2, s, m-1);
		MSort(SR, TR2, m, t);
		// 将TR2[s..m-1]和TR2[m..t]归并到TR1[s..t]
		Merge(TR2, TR1, s, m-1, t);
	}
}

// 归并排序,使用递归
void MergeSort(SqList *L){
	MSort(L->r, L ->r, 0, L->length-1);
}

// 将SR[]中相邻长度为s的子序列两两归并到TR[]
void MergePass(int SR[], int TR[], int s, int n){
	int i = 0;
	int j;
	while (i <= n - 2 * s){
		// 两两归并
		Merge(SR, TR, i, i + s - 1, i + 2 * s - 1);
		i = i + 2 * s;
	}
	if (i < n - s + 1)
		// 归并最后两个子序列
		Merge(SR, TR, i, i + s - 1, n - 1);
	else{
		// 若最后剩下单个子序列
		for (j = i; j <= n - 1; j++)
			TR[j] = SR[j];
	}
}

// 非递归版本的归并排序
void MergeSort2(SqList *L){
	// 申请额外空间
	int* TR = (int *)malloc(L->length * sizeof(int));
	int k = 1;
	while (k < L->length){
		MergePass(L->r, TR, k, L->length);
		// 子序列长度加倍
		k = 2 * k;
		MergePass(TR, L->r, k, L->length);
		k = 2 * k;
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
	MergeSort2(&l);
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

