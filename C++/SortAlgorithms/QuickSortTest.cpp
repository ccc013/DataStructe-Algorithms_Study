#include<iostream>

#define MAXSIZE 10	// ����������ĸ������ֵ
#define MAX_LENGTH_INSERT_SORT 7 

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
	int i, j, val;
	for (i = 1; i <= L->length - 1; i++){
		if (L->r[i] < L->r[i - 1]){
			// ��L->r[i]�����������,ʹ��val��������������Ԫ��L->r[i]
			val = L->r[i];
			for (j = i - 1; L->r[j]>val; j--)
				// ��¼����
				L->r[j + 1] = L->r[j];
			// ���뵽��ȷλ��
			L->r[j + 1] = val;
		}
	}
}

// ��������������L���ӱ�ļ�¼��ʹ�����¼��λ��������������λ��
// ��ʹ����֮ǰλ�õ�ֵС����������λ�õ�ֵ������
int Partition(SqList *L, int low, int high){
	int pivot_key;
	// ʹ������ȡ�з�ѡȡ����
	int m = low + (high - low) / 2;
	if (L->r[low] > L->r[high])
		// ��֤�����С
		swap(L, low, high);
	if (L->r[m] > L->r[high])
		// ��֤�м��С
		swap(L, high, m);
	if (L->r[m] > L->r[low])
		// ��֤��˽�С
		swap(L, m, low);

	pivot_key = L->r[low];
	int temp = pivot_key;
	while (low < high){
		while (low < high && L->r[high] >= pivot_key)
			high--;
		// ��С�������¼��ֵ�������Ͷ�
		// swap(L, low, high);
		// �����滻�����ǽ����ķ�ʽ���в���
		L->r[low] = L->r[high];
		while (low < high && L->r[low] <= pivot_key)
			low++;
		// �����������¼��ֵ�������߶�
		// swap(L, low, high);
		// �����滻�����ǽ����ķ�ʽ���в���
		L->r[high] = L->r[low];
	}
	// ������ֵ�滻��L.r[low]
	L->r[low] = temp;
	return low;
}

// �Դ���������L�е�������L->r[low...high]����������
void QSort(SqList *L, int low, int high){
	int pivot;

	if ((high - low) > MAX_LENGTH_INSERT_SORT){
		// ��high - low ���ڳ���ʱ�ÿ�������
		while (low < high){
			// ��L->r[low...high]һ��Ϊ�����������ֵpivot
			pivot = Partition(L, low, high);
			// �Ե������еݹ�����
			QSort(L, low, pivot - 1);
			// β�ݹ�
			low = pivot + 1;
			// �Ը������еݹ�����
			// QSort(L, pivot + 1, high);
		}
	}
	else{
		// ����ʹ��ֱ�Ӳ�������
		InsertSort(L);
	}
}

// ��������
void QuickSort(SqList *L){
	QSort(L, 0, L->length - 1);
}

// ��һ�ֿ�������
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

