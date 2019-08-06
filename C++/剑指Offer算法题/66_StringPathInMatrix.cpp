#include<iostream>
#include<vector>
#include <deque>
using std::deque;
using std::vector;
using std::cout;
using std::endl;
using std::cin;

/* 请设计一个函数，用来判断一个矩阵中是否存在一条包含某字符串所有字符的路径。 */
bool hasPathCore(char* matrix, int rows, int cols, int row, int col, char* str,
	int& pathLength, bool* visited){
	if (str[pathLength] == '\0')
		return true;
	bool hasPath = false;
	if (row >= 0 && row < rows && col >= 0 && col < cols
		&& matrix[row * cols + col] == str[pathLength] && !visited[row * cols + col]){
		// 当前字符等于路径中第i个字符
		++pathLength;
		// 设置当前字符已经被访问过
		visited[row*cols + col] = true;
		// 分别往左，上，右，下四个方向继续搜索
		hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited);
		if (!hasPath){
			// 搜索了当前位置相邻四个方向都没有下一个目标字符，则需要回到前一个字符，重新定位
			--pathLength;
			visited[row*cols + col] = false;
		}
	}
	return hasPath;
}
bool hasPath(char* matrix, int rows, int cols, char* str){
	if (matrix == NULL || rows < 1 || cols < 1 || str == NULL)
		return false;
	bool *visited = new bool[rows * cols];
	memset(visited, 0, rows*cols);

	int pathLength = 0;
	for (int row = 0; row < rows; row++){
		for (int col = 0; col < cols; col++){
			if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
				return true;
		}
	}
	delete[] visited;
	return false;
}
// ==================== Test Code ====================
void Test(char* testName, char* matrix, int rows, int cols, char* str, bool expected)
{
	if (testName != NULL)
		printf("%s begins: ", testName);

	if (hasPath(matrix, rows, cols, str) == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

//ABCE
//SFCS
//ADEE

//ABCCED
void Test1()
{
	char matrix[] = "ABCESFCSADEE";
	char* str = "ABCCED";

	Test("Test1", (char*)matrix, 3, 4, str, true);
}

//ABCE
//SFCS
//ADEE

//SEE
void Test2()
{
	char matrix[] = "ABCESFCSADEE";
	char* str = "SEE";

	Test("Test2", (char*)matrix, 3, 4, str, true);
}

//ABCE
//SFCS
//ADEE

//ABCB
void Test3()
{
	char matrix[] = "ABCESFCSADEE";
	char* str = "ABCB";

	Test("Test3", (char*)matrix, 3, 4, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SLHECCEIDEJFGGFIE
void Test4()
{
	char matrix[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	char* str = "SLHECCEIDEJFGGFIE";

	Test("Test4", (char*)matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEM
void Test5()
{
	char matrix[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	char* str = "SGGFIECVAASABCEHJIGQEM";

	Test("Test5", (char*)matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEEJIGOEM
void Test6()
{
	char matrix[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	char* str = "SGGFIECVAASABCEEJIGOEM";

	Test("Test6", (char*)matrix, 5, 8, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEMS
void Test7()
{
	char matrix[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	char* str = "SGGFIECVAASABCEHJIGQEMS";

	Test("Test7", (char*)matrix, 5, 8, str, false);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAA
void Test8()
{
	char matrix[] = "AAAAAAAAAAAA";
	char* str = "AAAAAAAAAAAA";

	Test("Test8", (char*)matrix, 3, 4, str, true);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAAA
void Test9()
{
	char matrix[] = "AAAAAAAAAAAA";
	char* str = "AAAAAAAAAAAAA";

	Test("Test9", (char*)matrix, 3, 4, str, false);
}

//A

//A
void Test10()
{
	char matrix[] = "A";
	char* str = "A";

	Test("Test10", (char*)matrix, 1, 1, str, true);
}

//A

//B
void Test11()
{
	char matrix[] = "A";
	char* str = "B";

	Test("Test11", (char*)matrix, 1, 1, str, false);
}

// 测试
int main(void){
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	Test9();
	Test10();
	Test11();

	system("pause");
	return 0;
}