#include<iostream>

#define MAXSIZE 10	// 待排序数组的个数最大值
#define MAX_LENGTH_INSERT_SORT 7 

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
	int i, j, val;
	for (i = 1; i <= L->length - 1; i++){
		if (L->r[i] < L->r[i - 1]){
			// 将L->r[i]插入有序表中,使用val保存待插入的数组元素L->r[i]
			val = L->r[i];
			for (j = i - 1; L->r[j]>val; j--)
				// 记录后移
				L->r[j + 1] = L->r[j];
			// 插入到正确位置
			L->r[j + 1] = val;
		}
	}
}

// 交换待排序序列L中子表的记录，使枢轴记录到位，并返回其所在位置
// 并使得其之前位置的值小于它，后面位置的值大于它
int Partition(SqList *L, int low, int high){
	int pivot_key;
	// 使用三数取中法选取枢轴
	int m = low + (high - low) / 2;
	if (L->r[low] > L->r[high])
		// 保证左端最小
		swap(L, low, high);
	if (L->r[m] > L->r[high])
		// 保证中间较小
		swap(L, high, m);
	if (L->r[m] > L->r[low])
		// 保证左端较小
		swap(L, m, low);

	pivot_key = L->r[low];
	int temp = pivot_key;
	while (low < high){
		while (low < high && L->r[high] >= pivot_key)
			high--;
		// 将小于枢轴记录的值交换到低端
		// swap(L, low, high);
		// 采用替换而不是交换的方式进行操作
		L->r[low] = L->r[high];
		while (low < high && L->r[low] <= pivot_key)
			low++;
		// 将大于枢轴记录的值交换到高端
		// swap(L, low, high);
		// 采用替换而不是交换的方式进行操作
		L->r[high] = L->r[low];
	}
	// 将枢轴值替换回L.r[low]
	L->r[low] = temp;
	return low;
}

// 对待排序序列L中的子序列L->r[low...high]做快速排序
void QSort(SqList *L, int low, int high){
	int pivot;

	if ((high - low) > MAX_LENGTH_INSERT_SORT){
		// 当high - low 大于常数时用快速排序
		while (low < high){
			// 将L->r[low...high]一分为二，算出枢轴值pivot
			pivot = Partition(L, low, high);
			// 对低子序列递归排序
			QSort(L, low, pivot - 1);
			// 尾递归
			low = pivot + 1;
			// 对高子序列递归排序
			// QSort(L, pivot + 1, high);
		}
	}
	else{
		// 否则使用直接插入排序
		InsertSort(L);
	}
}

// 快速排序
void QuickSort(SqList *L){
	QSort(L, 0, L->length - 1);
}

// 另一种快速排序
void quickSort(int a[], int l, int h){
	if (l < h){
		int i = l, j = h, key = a[l];
		while (i < j){
			while (i < j && a[j] >= key)
				j--;
			if (i < j)
				a[i++] = a[j];
			while (i < j && a[i] <= key)
				i++;
			if (i < j)
				a[j--] = a[i];
		}
		a[i] = key;
		quickSort(a, l, i - 1);
		quickSort(a, i + 1, h);
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
	QuickSort(&l);
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

