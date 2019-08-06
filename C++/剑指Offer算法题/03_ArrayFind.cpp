#include<iostream>
using std::cout;
using std::endl;
using std::cin;

// 二维数组的查找
bool Find(int* matrix, int rows, int columns, int number){
	bool found = false;
	if (matrix != NULL && rows > 0 && columns > 0){
		int row = 0;
		// 从右上角开始查找
		int column = columns - 1;
		while (row < rows && column >= 0){
			if (matrix[row * columns + column] == number){
				found = true;
				break;
			}
			else if (matrix[row * columns + column] > number)
				column--;
			else
				row++;
		}
	}
	return found;
}
// 测试
int main(void){
	int rows = 4;
	int columns = 4;
	int a[4][4] = {
		{ 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 }
	};
	int *matrix = a[0];
	// 二维数组包含查找的数字
	cout << "find 7 in matrix:" << Find(matrix, rows, columns, 7) << endl;
	// 二维数组不包含查找的数字，数字大于数组的最大值
	cout << "find 16 in matrix: " << Find(matrix, rows, columns, 16) << endl;
	// 二维数组不包含查找的数字，数字小于数组的最小值
	cout << "find 0 in matrix: " << Find(matrix, rows, columns, 0) << endl;
	// 二维数组不包含查找的数字，数字介于数组最大值和最小值之间
	cout << "find 3 in matrix: " << Find(matrix, rows, columns, 3) << endl;
	int *matrix_null = NULL;
	// 测试输入空指针的情况
	cout << "find 7 in matrix: " << Find(matrix_null, rows, columns, 7) << endl;

	system("pause");
	return 0;
}