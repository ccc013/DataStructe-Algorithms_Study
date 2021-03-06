#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/* 机器人的运动范围。给定一个m*n的方格，机器人从(0,0)开始移动，每次可以上下左右移动一格，
    但是不能进入行坐标和列坐标的数位之和大于k的格子
*/
// 获取一个数字的数位之和
int getDigitSum(int number){
	int sum = 0;
	while (number > 0){
		sum += number % 10;
		number /= 10;
	}
	return sum;
}
// 判断机器人能否进入坐标为(row, col)的方格
bool check(int threshold, int rows, int cols, int row, int col, bool* visited){
	if (row >= 0 && row < rows && col >= 0 && col < cols
		&& getDigitSum(row) + getDigitSum(col) <= threshold
		&& !visited[row * cols + col])
		return true;

	return false;
}

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited){
	int count = 0;
	if (check(threshold, rows, cols, row, col, visited)){
		visited[row * cols + col] = true;
		count =1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
			+ movingCountCore(threshold, rows, cols, row + 1, col, visited)
			+ movingCountCore(threshold, rows, cols, row, col - 1, visited)
			+ movingCountCore(threshold, rows, cols, row, col + 1, visited);
	}
	return count;
}

int movingCount(int threshold, int rows, int cols){
	bool* visited = new bool[rows * cols];
	for (int i = 0; i < rows * cols; ++i)
		visited[i] = false;
	int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
	delete[] visited;
	return count;
}

// ==================== Test Code ====================
void test(char* testName, int threshold, int rows, int cols, int expected)
{
	if (testName != NULL)
		printf("%s begins: ", testName);

	if (movingCount(threshold, rows, cols) == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

void test1()
{
	test("Test1", 5, 10, 10, 21);
}

void test2()
{
	test("Test2", 15, 20, 20, 359);
}

void test3()
{
	test("Test3", 10, 1, 100, 29);
}

void test4()
{
	test("Test4", 10, 1, 10, 10);
}

void test5()
{
	test("Test5", 15, 100, 1, 79);
}

void test6()
{
	test("Test6", 15, 10, 1, 10);
}

void test7()
{
	test("Test7", 15, 1, 1, 1);
}

void test8()
{
	test("Test8", -10, 10, 10, 0);
}

// 测试
int main(void){
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();

	system("pause");
	return 0;
}