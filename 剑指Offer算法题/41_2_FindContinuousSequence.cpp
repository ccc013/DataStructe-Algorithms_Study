#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数）*/

// 打印连续的正数序列
void PrintContinuousSequence(int small, int big){
	for (int i = small; i <= big; ++i)
		cout << i << " ";
	cout << endl;
}
// 解法，也是使用两个指针，表示最终序列的最小值和最大值
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
			// 当前序列和大于目标，需要减去最小值
			curSum -= small;
			small++;
			if (curSum == sum)
				PrintContinuousSequence(small, big);
		}
		// 当前序列和小于目标，增大最大值
		big++;
		curSum += big;
	}
}

void Test(int sum){
	cout << "sum numbers = " << sum << endl;
	FindContinuousSequence(sum);
}

// 测试
int main(void){
	int a[] = { 0, 3, 4, 9, 22, 100 };
	for (int i = 0; i < 6; i++)
		Test(a[i]);

	system("pause");
	return 0;
}