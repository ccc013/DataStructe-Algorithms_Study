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
		int flag = (int)(arr[i] / 10); //flag标识小数的第一位   
		bucket[flag][count[flag]] = temp; //用二维数组的每个向量来存放小数第一位相同的数据  
		int j = count[flag]++;

		/* 利用插入排序对每一行进行排序 */
		for (; j > 0 && temp < bucket[flag][j - 1]; --j)
		{
			bucket[flag][j] = bucket[flag][j - 1];
		}
		bucket[flag][j] = temp;
	}

	/* 所有数据重新链接 */
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
		cout << data[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
