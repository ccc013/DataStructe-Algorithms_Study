#include<iostream>
#include<ctime>
#include"xcept.h"
#include"Array1D.h"
#include"Array2D.h"
#include"Matrix.h"
#include"SpecialMatrix.h"
#include"SparseMatrix.h"
#include"LinkMatrix.h"

using std::cout;
using std::endl;
using std::cin;

void testArray1D(){
	Array1D<int> a(10);
	Array1D<int> b(10);

	for (int i = 0; i < 10; i++)
		a[i] = i * 2;
	
	cout << "a is \n";
	for (int i = 0; i < 10; i++)
		cout << a[i] <<" ";
	cout << endl;

	b = a;
	cout << "b=a, so b is \n";
	for (int i = 0; i < 10; i++)
		cout << b[i] << " ";
	cout << endl;

	cout << "c= a+b,so c :\n";
	Array1D<int> c(10);
	c = a + b;
	for (int i = 0; i < 10; i++)
		cout << c[i] << " ";
	cout << endl;

	Array1D<int> d(10) ;
	cout << "a*c = \n";
	d = a*c;
	for (int i = 0; i < 10; i++)
		cout << d[i] << " ";
	cout << endl;

	Array1D<int> e(10);
	cout << "c-b = \n";
	e = c - b;
	for (int i = 0; i < 10; i++)
		cout << e[i] << " ";
	cout << endl;
}

void testArray2D(){
	Array2D<int> a(5,3);
	Array2D<int> b(3, 5);
	cout << "new 2D Array a:\n";
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 3; j++){
			(a[i])[j] = i * 3 + j;
		}
	}
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 5; j++){
			(b[i])[j] = i * 2 + j;
		}
	}

	a.show();
	cout << "new 2D Array b:\n";
	b.show();
	cout << "a*b = \n";
	Array2D<int> c(5, 5);
	c = a*b;
	c.show();

}

void testMatrix(){
	try{
		Matrix<int> m1(2, 2);
		Matrix<int> m2(2, 4);
		Matrix<int> m11(2, 2);
		for (int i = 1; i <= 2; i++){
			for (int j = 1; j <= 2; j++){
				m1(i, j) = i * 2 + j;
				m11(i, j) = i * 3 + j + 1;
			}
		}
		for (int i = 1; i <= 2; i++){
			for (int j = 1; j <= 4; j++){
				m2(i, j) = i *3 + j+1;
			}
		}
		cout << "show m1:\n";
		cout << m1;
		cout << "show m2:\n";
		cout << m2;
		cout << "show m11:\n";
		cout << m11;

		Matrix<int> m3;
		Matrix<int> m4;
		m3 = m1 * m2;
		cout << "m3 = m1 * m2:\n";
		cout << m3;

		m4 = m11 - m1;
		cout << "m4 = m11 - m1:\n";
		cout << m4;

		cout << "-m2\n";
		cout << -m2;

		cout << "m4 = m11+m1\n";
		m4 = m11 + m1;
		cout << m4;

		cout << "every element plus 10 for m1\n";
		m1 += 10;
		cout << m1;
	}
	catch (...){
		std::cerr << "errors!\n";
	}
}

void testSpecialMatrix(){
	try{
		DiagonalMatrix<int> DMatrix(3);
		TridiagonalMatrix<int> TDMatrix(3);
		LowerMatrix<int> LDMatrix(3);
		for (int i = 1; i <= 3; i++){
			for (int j = 1; j <= 3; j++){
				if (i==j)
					DMatrix.Store(i * 3 + j, i, j);
				if (i - j == 1 || i == j || i - j == -1)
					TDMatrix.Store(i * 2 + j, i, j);
				if (i >= j)
					LDMatrix.Store(i + j * 2, i, j);
			}
		}
		cout << "show a 3*3 DiagonalMatrix:\n";
		for (int i = 1; i <= 3; i++){
			for (int j = 1; j <= 3; j++){
				cout << DMatrix.Retrieve(i, j) << " ";
			}
			cout << "\n";
		}

		cout << "show a 3*3 TriDiagonalMatrix:\n";
		for (int i = 1; i <= 3; i++){
			for (int j = 1; j <= 3; j++){
				cout << TDMatrix.Retrieve(i, j) << " ";
			}
			cout << "\n";
		}

		cout << "show a 3*3 LowerDiagonalMatrix:\n";
		for (int i = 1; i <= 3; i++){
			for (int j = 1; j <= 3; j++){
				cout << LDMatrix.Retrieve(i, j) << " ";
			}
			cout << "\n";
		}
	}
	catch (...){
		std::cerr << "errors!\n";
	}
}

void testSparseMatrix(){
	try{
		int Maxterms = 6;
		SparseMatrix<int> SMatrix(Maxterms);
		SparseMatrix<int> SMatrix_tranpose(Maxterms);
		SparseMatrix<int> SMatrix_total(2*Maxterms);
		cout << "create a sparseMatrix\n";
		cin >> SMatrix;
		cout << "show sparseMatrix\n";
		cout << SMatrix;

		SMatrix.Transpose(SMatrix_tranpose);
		cout << "Tranpose SMatrix, the result is\n";
		cout << SMatrix_tranpose;

		SMatrix.Add(SMatrix_tranpose, SMatrix_total);
		cout << "SMatrix + SMatrix_tranpose:\n";
		cout << SMatrix_total;

	}
	catch (...){
		std::cerr << "errors!\n";
	}
}

void testLinkMatrix(){
	try{
		LinkMatrix<int> LM1;
		LinkMatrix<int> LM2;
		cout << "input 3*3 LinkMatrix\n";
		cin >> LM1;

		cout << "show\n";
		cout << LM1;

		cout << "tranpose LM1\n";
		LM1.Transpose(LM2);
		cout << LM2;

	}
	catch (...){
		std::cerr << "errors!\n";
	}
}
int main(){

	testLinkMatrix();

	system("pause");
	return 0;
}

