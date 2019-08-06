#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void radixSort(int data[], int size, int k) {
	// size�����鳤�ȣ�k����������ֵ����λ��
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
			// �õ���ǰ��λ�ϵ���ֵ
			int lsd = ((data[i] / n) % 10);
			temp[lsd][order[lsd]] = data[i];
			// ������λֵΪlsd�ĸ���
			order[lsd]++;
		}
		// ��������  
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
		cout << a[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
