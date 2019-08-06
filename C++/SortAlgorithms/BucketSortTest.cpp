#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int size = 10;
void BucketSort(int * arr, int n)
{
	vector<vector<int> > bucket;
	for (int i = 0; i < n; i++){
		vector<int> t(n, 0);
		bucket.push_back(t);
	}
	int count[size] = { 0 };
	for (int i = 0; i < n; i++)
	{
		int temp = arr[i];
		int flag = (int)(arr[i] / 10); //flag��ʶС���ĵ�һλ   
		bucket[flag][count[flag]] = temp; //�ö�ά�����ÿ�����������С����һλ��ͬ������  
		int j = count[flag]++;

		/* ���ò��������ÿһ�н������� */
		for (; j > 0 && temp < bucket[flag][j - 1]; --j)
		{
			bucket[flag][j] = bucket[flag][j - 1];
		}
		bucket[flag][j] = temp;
	}

	/* ���������������� */
	int k = 0;
	for (int i = 0; i <n; i++)
	{
		for (int j = 0; j< count[i]; j++)
		{
			arr[k++] = bucket[i][j];
		}
	}
}

int main()
{
	int n = 8;
	int a[] = { 1, 5, 4, 2, 3, 3,6,4 };
	BucketSort(a, n);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
