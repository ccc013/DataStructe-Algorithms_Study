#include<iostream>
#include<list>
using std::list;
using std::cout;
using std::endl;
using std::cin;

/*0,1，...,n-1这n个数字排成一个圆圈，从数字0开始依次删除第m个数字，求剩下的最后一个数字*/

// 解法1，用环形链表模拟圆圈,时间复杂度是O(mn)
int LastRemaining(unsigned int n, unsigned int m){
	if (n < 1 || m < 1)
		return -1;
	unsigned int i = 0;
	// 使用模板库中的list模拟环形链表
	list<int> numbers;
	for (i = 0; i < n; i++)
		numbers.push_back(i);
	list<int>::iterator current = numbers.begin();
	while (numbers.size() > 1){
		for (int i = 1; i < m; ++i){
			// 找到第m个数字，如果找到末尾，需要从头开始遍历
			current++;
			if (current == numbers.end())
				current = numbers.begin();
		}
		list<int>::iterator next = ++current;
		if (next == numbers.end())
			next = numbers.begin();
		--current;
		// 删除数字
		numbers.erase(current);
		current = next;
	}
	return *(current);
}

// 解法2，时间复杂度是O(n)
int LastRemaining_2(unsigned int n, unsigned int m){
	if (n < 1 || m < 1)
		return -1;

	int last = 0;
	for (int i = 2; i <= n; i++)
		last = (last + m) % i;

	return last;
}

void Test(int numbers, int m){
	cout << "numbers = " << numbers << ", delete " << m << " values." << endl;
	cout << "Solution1: ";
	int resVal = LastRemaining(numbers, m);
	if (resVal > -1)
		cout << "the last remaining values = " << resVal << endl;
	else
		cout << "wrong input\n";

	cout << "Solution2: ";
	resVal = LastRemaining_2(numbers, m);
	if (resVal > -1)
		cout << "the last remaining values = " << resVal << endl;
	else
		cout << "wrong input\n";
}

// 测试
int main(void){
	Test(5, 2);
	Test(5, 3);
	Test(6, 8);
	Test(0, 2);
	Test(3000, 1250);
	

	system("pause");
	return 0;
}