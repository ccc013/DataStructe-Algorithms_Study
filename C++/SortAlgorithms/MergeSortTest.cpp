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

// �������SR[i..m]��SR[m+1..n]�鲢Ϊ�����TR[i..n]
void Merge(int SR[], int TR[], int i, int m, int n){
	int j, k, l;
	for (j = m+1, k = i; i <= m && j <= n; k++){
		// ��SR�м�¼��С������TR
		if (SR[i] < SR[j])
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
	if (i <= m){
		for (l = 0; l <= m - i; l++)
			// ��ʣ���SR[i..m]���Ƶ�TR
			TR[k + l] = SR[i + l];
	}
	if (j <= n){
		for (l = 0; l <= n - j; l++)
			// ��ʣ���SR[j..n-1]���Ƶ�TR
			TR[k + l] = SR[j + l];
	}
}

// ��SR[s..t]�鲢����ΪTR1[s..t]
void MSort(int SR[], int TR1[], int s, int t){
	int m;
	int TR2[MAXSIZE];
	if (s == t)
		TR1[s] = SR[s];
	else{
		// ��SR[s..t]ƽ��ΪSR[s...m-1]��SR[m...t]
		m = (s + t) / 2+1;
		MSort(SR, TR2, s, m-1);
		MSort(SR, TR2, m, t);
		// ��TR2[s..m-1]��TR2[m..t]�鲢��TR1[s..t]
		Merge(TR2, TR1, s, m-1, t);
	}
}

// �鲢����,ʹ�õݹ�
void MergeSort(SqList *L){
	MSort(L->r, L ->r, 0, L->length-1);
}

// ��SR[]�����ڳ���Ϊs�������������鲢��TR[]
void MergePass(int SR[], int TR[], int s, int n){
	int i = 0;
	int j;
	while (i <= n - 2 * s){
		// �����鲢
		Merge(SR, TR, i, i + s - 1, i + 2 * s - 1);
		i = i + 2 * s;
	}
	if (i < n - s + 1)
		// �鲢�������������
		Merge(SR, TR, i, i + s - 1, n - 1);
	else{
		// �����ʣ�µ���������
		for (j = i; j <= n - 1; j++)
			TR[j] = SR[j];
	}
}

// �ǵݹ�汾�Ĺ鲢����
void MergeSort2(SqList *L){
	// �������ռ�
	int* TR = (int *)malloc(L->length * sizeof(int));
	int k = 1;
	while (k < L->length){
		MergePass(L->r, TR, k, L->length);
		// �����г��ȼӱ�
		k = 2 * k;
		MergePass(TR, L->r, k, L->length);
		k = 2 * k;
	}
}

//���ж�����������a[first...mid]��a[mid...last]�ϲ���  
void MergeArray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;
	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <= m)
		temp[k++] = a[i++];
	while (j <= n)
		temp[k++] = a[j++];
	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
//�ڶ��ֵݹ����ɹ鲢����  
void MergeSort(int a[], int first, int last, int temp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		MergeSort(a, first, mid, temp);    //�������  
		MergeSort(a, mid + 1, last, temp); //�ұ�����  
		MergeArray(a, first, mid, last, temp); //�ٽ������������кϲ�  
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

