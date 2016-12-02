#include<iostream>

using std::cout;
using std::endl;
using std::cin;

// 输入一个矩阵，按照从外向里顺时针的顺序依次打印出每个数字
// 实现打印一圈
void PrintMatrixInCircle(int** numbers, int columns, int rows, int start){
	int endX = columns - 1 - start;
	int endY = rows - 1 - start;

	// 从左到右打印一行
	for (int i = start; i <= endX; ++i){
		int number = numbers[start][i];
		cout << number << " ";
	}
	// 从上到下打印一列
	if (start < endY){
		// 保证终止行号大于起始行号，i从start+1开始，避免打印重复的数值
		for (int i = start + 1; i <= endY; ++i){
			int number = numbers[i][endX];
			cout << number << " ";
		}
	}
	// 从右到左打印一行
	if (start < endX && start < endY){
		// 至少需要有两行两列
		for (int i = endX - 1; i >= start; --i){
			int number = numbers[endY][i];
			cout << number << " ";
		}
	}
	// 从下到上打印一列
	if (start < endX && start < endY - 1){
		// 至少要有三行两列，即终止行号要比起始行号至少大2
		for (int i = endY - 1; i >= start+1; --i){
			int number = numbers[i][start];
			cout << number << " ";
		}
	}
}

void PrintMatrixClockwisely(int **numbers, int columns, int rows){
	if (numbers == NULL || columns <= 0 || rows <= 0)
		return;
	int start = 0;
	while (columns > start * 2 && rows > start * 2){
		PrintMatrixInCircle(numbers, columns, rows, start);
		++start;
		cout << endl;
	}
}
// 创建一个二维数组
void create2DArray(int ** &pa, int columns, int rows){
	pa = new int *[rows];
	for (int r = 0; r < rows; r++){
		pa[r] = new int[columns];
		for (int c = 0; c < columns; c++){
			pa[r][c] = r * 1 + c;
		}
	}
}
// 打印二维数组
void print2DArray(int **pa, int columns, int rows){
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < columns; c++){
			cout << pa[r][c] << " ";
		}
		cout << endl;
	}
}
// 删除二维数组
void delete2DArray(int ** &x, int rows){
	for (int i = 0; i < rows; i++)
		delete[]x[i];
	delete[] x;
	x = 0;
}

// 测试
int main(void){
	// 多行多列的数组
	int **pa = NULL;
	create2DArray(pa, 4, 4);
	print2DArray(pa, 4, 4);
	cout << "顺时针由外向里打印数组：\n";
	PrintMatrixClockwisely(pa, 4, 4);
	cout << endl;
	// 一列数组
	create2DArray(pa, 1, 4);
	print2DArray(pa, 1, 4);
	cout << "顺时针由外向里打印数组：\n";
	PrintMatrixClockwisely(pa, 1, 4);
	cout << endl;
	// 一行数组
	create2DArray(pa, 4, 1);
	print2DArray(pa, 4, 1);
	cout << "顺时针由外向里打印数组：\n";
	PrintMatrixClockwisely(pa, 4, 1);
	cout << endl;
	// 一行一列数组
	create2DArray(pa, 1, 1);
	print2DArray(pa, 1, 1);
	cout << "顺时针由外向里打印数组：\n";
	PrintMatrixClockwisely(pa, 1, 1);
	cout << endl;
	delete2DArray(pa, 1);

	system("pause");
	return 0;
}