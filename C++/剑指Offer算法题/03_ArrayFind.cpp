#include<iostream>
using std::cout;
using std::endl;
using std::cin;

// ��ά����Ĳ���
bool Find(int* matrix, int rows, int columns, int number){
	bool found = false;
	if (matrix != NULL && rows > 0 && columns > 0){
		int row = 0;
		// �����Ͻǿ�ʼ����
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
// ����
int main(void){
	int rows = 4;
	int columns = 4;
	int a[4][4] = {
		{ 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 }
	};
	int *matrix = a[0];
	// ��ά����������ҵ�����
	cout << "find 7 in matrix:" << Find(matrix, rows, columns, 7) << endl;
	// ��ά���鲻�������ҵ����֣����ִ�����������ֵ
	cout << "find 16 in matrix: " << Find(matrix, rows, columns, 16) << endl;
	// ��ά���鲻�������ҵ����֣�����С���������Сֵ
	cout << "find 0 in matrix: " << Find(matrix, rows, columns, 0) << endl;
	// ��ά���鲻�������ҵ����֣����ֽ����������ֵ����Сֵ֮��
	cout << "find 3 in matrix: " << Find(matrix, rows, columns, 3) << endl;
	int *matrix_null = NULL;
	// ���������ָ������
	cout << "find 7 in matrix: " << Find(matrix_null, rows, columns, 7) << endl;

	system("pause");
	return 0;
}