#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2-10为数字本身，A是1，J,Q,K分别是11,12,13，而大小王可以是任意数字*/
int compare(const void *arg1, const void *arg2){
	return *(int *)arg1 - *(int *)arg2;
}

bool isContinuous(int* numbers, int length){
	if (numbers == NULL || length < 1)
		return false;
	// 数组排序
	qsort(numbers, length, sizeof(int), compare);
	int numberOfZero = 0;
	int numberOfGap = 0;
	// 统计数组中0的个数
	for (int i = 0; i < length && numbers[i] == 0; i++)
		++numberOfZero;
	// 统计数组中的间隔数目
	int small = numberOfZero;
	int big = small + 1;
	while (big < length){
		// 两个数相等，有对子，不可能是顺子
		if (numbers[small] == numbers[big])
			return false;
		numberOfGap += numbers[big] - numbers[small] - 1;
		small = big;
		big++;
	}
	return (numberOfGap > numberOfZero) ? false : true;
}

void Test(int* numbers, int length){
	if (numbers == NULL || length < 1){
		cout << "wrong input" << endl;
		return;
	}
	else{
		cout << "input array: ";
		for (int i = 0; i < length; i++)
			cout << numbers[i] << " ";
		cout << endl;
	}
	if (isContinuous(numbers, length))
		cout << "array is continuous\n";
	else
		cout << "array isn't continuous\n";
}

// 测试
int main(void){
	int t1[] = { 0, 1, 3, 4, 5 };
	Test(t1, 5);
	int t2[] = { 0, 0, 2, 4, 5 };
	Test(t2, 5);
	int t3[] = { 9, 5, 7, 6, 8 };
	Test(t3, 5);
	int t4[] = { 1, 3, 9, 2, 1 };
	Test(t4, 5);
	int t5[] = { 11, 2, 3, 13, 10 };
	Test(t5, 5);
	Test(NULL, 5);
	

	system("pause");
	return 0;
}