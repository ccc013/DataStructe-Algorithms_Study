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

// 已知L->r[s...m]中记录的关键字除L->r[s]之外均满足堆的定义
// 本函数调整L->r[s]的关键字，使L->r[s..m]成为一个大顶堆
void HeapAdjust(SqList *L, int s, int m){
	int temp, j;
	temp = L->r[s];
	for (j = 2 * s; j <= m - 1; j *= 2){
		// 沿关键字较大的孩子结点向下筛选
		if (j < m-1 && L->r[j] < L->r[j + 1])
			// j是关键字中较大的记录的下标
			++j;
		if (temp >= L->r[j])
			// 当前值不需要进行调整
			break;
		L->r[s] = L->r[j];
		s = j;
	}
	// 插入
	L->r[s] = temp;
}

// 堆排序
void HeapSort(SqList *L){
	int i;
	for (i = L->length / 2; i >= 0; i--){
		// 将待排序的序列构成一个最大堆
		HeapAdjust(L, i, L->length);
	}

	// 开始进行排序
	for (i = L->length - 1; i > 0; i--){
		// 将堆顶记录与当前未经排序的子序列的最后一个记录交换
		swap(L, 0, i);
		// 重新调整为最大堆
		HeapAdjust(L, 0, i - 1);
	}
}

/*返回父节点*/
int parent(int i)
{
	return (int)floor((i - 1) / 2);
}

/*返回左孩子节点*/
int left(int i)
{
	return (2 * i + 1);
}

/*返回右孩子节点*/
int right(int i)
{
	return (2 * i + 2);
}

/*对以某一节点为根的子树做堆调整(保证最大堆性质)*/
void HeapAdjust(int A[], int i, int heap_size)
{
	int l = left(i);
	int r = right(i);
	int largest;
	int temp;
	if (l < heap_size && A[l] > A[i])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	if (r < heap_size && A[r] > A[largest])
	{
		largest = r;
	}
	if (largest != i)
	{
		temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		HeapAdjust(A, largest, heap_size);
	}
}

/*建立最大堆*/
void BuildHeap(int A[], int heap_size)
{
	for (int i = (heap_size - 2) / 2; i >= 0; i--)
	{
		HeapAdjust(A, i, heap_size);
	}
}

/*输出结果*/
void print(int A[], int heap_size)
{
	for (int i = 0; i < heap_size; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

/*第二种堆排序*/
void HeapSort(int A[], int heap_size)
{
	BuildHeap(A, heap_size);
	int temp;
	for (int i = heap_size - 1; i >= 0; i--)
	{
		temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		HeapAdjust(A, 0, i);
	}
	print(A, heap_size);
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
	HeapSort(&l);
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

