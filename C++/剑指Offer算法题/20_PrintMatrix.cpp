#include<iostream>

using std::cout;
using std::endl;
using std::cin;

// ����һ�����󣬰��մ�������˳ʱ���˳�����δ�ӡ��ÿ������
// ʵ�ִ�ӡһȦ
void PrintMatrixInCircle(int** numbers, int columns, int rows, int start){
	int endX = columns - 1 - start;
	int endY = rows - 1 - start;

	// �����Ҵ�ӡһ��
	for (int i = start; i <= endX; ++i){
		int number = numbers[start][i];
		cout << number << " ";
	}
	// ���ϵ��´�ӡһ��
	if (start < endY){
		// ��֤��ֹ�кŴ�����ʼ�кţ�i��start+1��ʼ�������ӡ�ظ�����ֵ
		for (int i = start + 1; i <= endY; ++i){
			int number = numbers[i][endX];
			cout << number << " ";
		}
	}
	// ���ҵ����ӡһ��
	if (start < endX && start < endY){
		// ������Ҫ����������
		for (int i = endX - 1; i >= start; --i){
			int number = numbers[endY][i];
			cout << number << " ";
		}
	}
	// ���µ��ϴ�ӡһ��
	if (start < endX && start < endY - 1){
		// ����Ҫ���������У�����ֹ�к�Ҫ����ʼ�к����ٴ�2
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
// ����һ����ά����
void create2DArray(int ** &pa, int columns, int rows){
	pa = new int *[rows];
	for (int r = 0; r < rows; r++){
		pa[r] = new int[columns];
		for (int c = 0; c < columns; c++){
			pa[r][c] = r * 1 + c;
		}
	}
}
// ��ӡ��ά����
void print2DArray(int **pa, int columns, int rows){
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < columns; c++){
			cout << pa[r][c] << " ";
		}
		cout << endl;
	}
}
// ɾ����ά����
void delete2DArray(int ** &x, int rows){
	for (int i = 0; i < rows; i++)
		delete[]x[i];
	delete[] x;
	x = 0;
}

// ����
int main(void){
	// ���ж��е�����
	int **pa = NULL;
	create2DArray(pa, 4, 4);
	print2DArray(pa, 4, 4);
	cout << "˳ʱ�����������ӡ���飺\n";
	PrintMatrixClockwisely(pa, 4, 4);
	cout << endl;
	// һ������
	create2DArray(pa, 1, 4);
	print2DArray(pa, 1, 4);
	cout << "˳ʱ�����������ӡ���飺\n";
	PrintMatrixClockwisely(pa, 1, 4);
	cout << endl;
	// һ������
	create2DArray(pa, 4, 1);
	print2DArray(pa, 4, 1);
	cout << "˳ʱ�����������ӡ���飺\n";
	PrintMatrixClockwisely(pa, 4, 1);
	cout << endl;
	// һ��һ������
	create2DArray(pa, 1, 1);
	print2DArray(pa, 1, 1);
	cout << "˳ʱ�����������ӡ���飺\n";
	PrintMatrixClockwisely(pa, 1, 1);
	cout << endl;
	delete2DArray(pa, 1);

	system("pause");
	return 0;
}