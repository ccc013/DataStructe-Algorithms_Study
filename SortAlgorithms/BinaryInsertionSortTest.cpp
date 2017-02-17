#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 二分插入排序算法
void BinInsertSort(int a[], int n)
{
	int key, left, right, middle;
	for (int i = 1; i<n; i++)
	{
		key = a[i];
		left = 0;
		right = i - 1;
		while (left <= right)
		{
			middle = (left + right) / 2;
			if (a[middle]>key)
				right = middle - 1;
			else
				left = middle + 1;
		}

		for (int j = i - 1; j >= left; j--)
		{
			a[j + 1] = a[j];
		}

		a[left] = key;
	}
}
int main()
{
	int n = 8;
	int a[] = { 1, 5, 4, 2, 3, 3,6,4 };

	BinInsertSort(a, n);
	for (int i = 0; i < 10; i++)
		cout << data[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
