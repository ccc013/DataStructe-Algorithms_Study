#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 鸡尾酒/双向冒泡排序算法
void CocktailSort(int *a, int nsize)
{
	int tail = nsize - 1;
	for (int i = 0; i<tail;)
	{
		for (int j = tail; j>i; --j) //第一轮，先将最小的数据排到前面  
		{
			if (a[j]<a[j - 1])
			{
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
		++i;                    //原来i处数据已排好序，加1  
		for (j = i; j<tail; ++j)    //第二轮，将最大的数据排到后面  
		{
			if (a[j]>a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
		tail--;                 //原tail处数据也已排好序，将其减1  
	}
}
int main()
{
	int n = 8;
	int a[] = { 1, 5, 4, 2, 3, 3,6,4 };

	CocktailSort(a, n);
	for (int i = 0; i < 10; i++)
		cout << data[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
