#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ��β��/˫��ð�������㷨
void CocktailSort(int *a, int nsize)
{
	int tail = nsize - 1;
	for (int i = 0; i<tail;)
	{
		for (int j = tail; j>i; --j) //��һ�֣��Ƚ���С�������ŵ�ǰ��  
		{
			if (a[j]<a[j - 1])
			{
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
		++i;                    //ԭ��i���������ź��򣬼�1  
		for (j = i; j<tail; ++j)    //�ڶ��֣������������ŵ�����  
		{
			if (a[j]>a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
		tail--;                 //ԭtail������Ҳ���ź��򣬽����1  
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
