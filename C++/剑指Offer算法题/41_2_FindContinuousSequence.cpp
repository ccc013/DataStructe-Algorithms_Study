#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*����һ������s����ӡ�����к�Ϊs�������������У����ٺ�����������*/

// ��ӡ��������������
void PrintContinuousSequence(int small, int big){
	for (int i = small; i <= big; ++i)
		cout << i << " ";
	cout << endl;
}
// �ⷨ��Ҳ��ʹ������ָ�룬��ʾ�������е���Сֵ�����ֵ
void FindContinuousSequence(int sum){
	if (sum < 3){
		cout << "wrong input\n";
		return;
	}
	int small = 1;
	int big = 2;
	int middle = (1 + sum) / 2;
	int curSum = small + big;
	
	while (small < middle){
		if (curSum == sum)
			PrintContinuousSequence(small, big);

		while (curSum > sum && small < middle){
			// ��ǰ���кʹ���Ŀ�꣬��Ҫ��ȥ��Сֵ
			curSum -= small;
			small++;
			if (curSum == sum)
				PrintContinuousSequence(small, big);
		}
		// ��ǰ���к�С��Ŀ�꣬�������ֵ
		big++;
		curSum += big;
	}
}

void Test(int sum){
	cout << "sum numbers = " << sum << endl;
	FindContinuousSequence(sum);
}

// ����
int main(void){
	int a[] = { 0, 3, 4, 9, 22, 100 };
	for (int i = 0; i < 6; i++)
		Test(a[i]);

	system("pause");
	return 0;
}