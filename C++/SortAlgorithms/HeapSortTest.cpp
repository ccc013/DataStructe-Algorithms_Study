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

// ��֪L->r[s...m]�м�¼�Ĺؼ��ֳ�L->r[s]֮�������ѵĶ���
// ����������L->r[s]�Ĺؼ��֣�ʹL->r[s..m]��Ϊһ���󶥶�
void HeapAdjust(SqList *L, int s, int m){
	int temp, j;
	temp = L->r[s];
	for (j = 2 * s; j <= m - 1; j *= 2){
		// �عؼ��ֽϴ�ĺ��ӽ������ɸѡ
		if (j < m-1 && L->r[j] < L->r[j + 1])
			// j�ǹؼ����нϴ�ļ�¼���±�
			++j;
		if (temp >= L->r[j])
			// ��ǰֵ����Ҫ���е���
			break;
		L->r[s] = L->r[j];
		s = j;
	}
	// ����
	L->r[s] = temp;
}

// ������
void HeapSort(SqList *L){
	int i;
	for (i = L->length / 2; i >= 0; i--){
		// ������������й���һ������
		HeapAdjust(L, i, L->length);
	}

	// ��ʼ��������
	for (i = L->length - 1; i > 0; i--){
		// ���Ѷ���¼�뵱ǰδ������������е����һ����¼����
		swap(L, 0, i);
		// ���µ���Ϊ����
		HeapAdjust(L, 0, i - 1);
	}
}

/*���ظ��ڵ�*/
int parent(int i)
{
	return (int)floor((i - 1) / 2);
}

/*�������ӽڵ�*/
int left(int i)
{
	return (2 * i + 1);
}

/*�����Һ��ӽڵ�*/
int right(int i)
{
	return (2 * i + 2);
}

/*����ĳһ�ڵ�Ϊ�����������ѵ���(��֤��������)*/
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

/*��������*/
void BuildHeap(int A[], int heap_size)
{
	for (int i = (heap_size - 2) / 2; i >= 0; i--)
	{
		HeapAdjust(A, i, heap_size);
	}
}

/*������*/
void print(int A[], int heap_size)
{
	for (int i = 0; i < heap_size; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

/*�ڶ��ֶ�����*/
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

