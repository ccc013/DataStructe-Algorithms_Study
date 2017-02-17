#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void radixSort(int data[], int size, int k) {
	// size是数组长度，k是数组中数值最大的位数
	vector<vector<int> > temp;
	for (int i = 0; i < size; i++){
		vector<int> t(size, 0);
		temp.push_back(t);
	}
	vector<int> order(10);
	int n = 1;
	int maxBits = pow(10,k-1);
	while (n <= maxBits) {
		int i;
		for (i = 0; i < size; i++) {
			// 得到当前数位上的数值
			int lsd = ((data[i] / n) % 10);
			temp[lsd][order[lsd]] = data[i];
			// 计算数位值为lsd的个数
			order[lsd]++;
		}
		// 重新排列  
		int k = 0;
		for (i = 0; i < 10; i++) {
			if (order[i] != 0)  {
				int j;
				for (j = 0; j < order[i]; j++, k++) {
					data[k] = temp[i][j];
				}
			}
			order[i] = 0;
		}
		n *= 10;
	}
}

int main()
{
	int data[11] = { 173, 122, 193, 43, 155, 14, 28, 65, 39, 81,23 };
	radixSort(data,11,3);
	for (int i = 0; i < 10; i++)
		cout << data[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
