#ifndef MATRIX_H_
#define MATRIX_H_
#include<iostream>
using std::ostream;

template<class T>
class Matrix{
private:
	int rows, cols;
	// 元素数组
	T *element;
public:
	Matrix(int r = 0, int c = 0);
	// 复制构造函数
	Matrix(const Matrix<T>& m);
	~Matrix(){ delete[] element; }
	int Rows() const{ return rows; }
	int Columns() const{ return cols; }
	T& operator()(int i, int j)const;
	Matrix<T>& operator=(const Matrix<T>& m);
	Matrix<T> operator+() const;
	Matrix<T> operator+(const Matrix<T>& m)const;
	Matrix<T> operator-() const;
	Matrix<T> operator-(const Matrix<T>& m)const;
	Matrix<T> operator*(const Matrix<T>& m)const;
	Matrix<T>& operator+=(const T& m);
	void Output(ostream& out) const;
};

template<class T>
Matrix<T>::Matrix(int r, int c){
	if (r < 0 || c < 0)
		throw BadInitializers();
	if ((!r || !c) && (r || c))
		throw BadInitializers();
	rows = r;
	cols = c;
	element = new T[r*c];
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& m){
	// 复制构造函数
	rows = m.rows;
	cols = m.cols;
	element = new T[rows*cols];
	int size = rows * cols;
	for (int i = 0; i < size; i++)
		element[i] = m.element[i];
}

template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& m){
	// 重载赋值运算符=
	if (this != &m){
		rows = m.rows;
		cols = m.cols;
		delete[] element;
		element = new T[rows*cols];
		int size = rows * cols;
		for (int i = 0; i < size; i++)
			element[i] = m.element[i];
	}
	return *this;
}

template<class T>
T& Matrix<T>::operator()(int i, int j)const{
	// 返回一个指向元素(i,j)的引用
	if (i<1 || i>rows || j<1 || j>cols)
		throw OutOfBounds();
	return element[(i - 1)*cols + j - 1];
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& m)const{
	// 二元减法
	if (rows != m.rows || cols != m.cols)
		throw SizeMismatch();
	Matrix<T> w(rows, cols);
	for (int i = 0; i < rows * cols; i++){
		w.element[i] = element[i] - m.element[i];
	}
	return w;
}

template<class T>
Matrix<T> Matrix<T>::operator-()const{
	// 一元减法
	Matrix<T> w(rows, cols);
	for (int i = 0; i < rows * cols; i++){
		w.element[i] = -element[i] ;
	}
	return w;
}

template<class T>
Matrix<T> Matrix<T>::operator+()const{
	// 一元加法
	Matrix<T> w(rows, cols);
	for (int i = 0; i < rows * cols; i++){
		w.element[i] = element[i];
	}
	return w;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& m)const{
	// 二元加法
	if (rows != m.rows || cols != m.cols)
		throw SizeMismatch();
	Matrix<T> w(rows, cols);
	for (int i = 0; i < rows * cols; i++){
		w.element[i] = element[i] + m.element[i];
	}
	return w;
}

template<class T>
Matrix<T>& Matrix<T>::operator+=(const T& m){
	// 增值运算符
	for (int i = 0; i < rows * cols; i++){
		element[i] += m;
	}
	return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& m)const{
	// 矩阵乘法 返回w = (*this) * m
	if (cols != m.rows)
		throw SizeMismatch();
	Matrix<T> w(rows, m.cols);
	int ct = 0, cm = 0, cw = 0;
	for (int i = 1; i <= rows; i++){
		// 计算出结果的第i行
		for (int j = 1; j <= m.cols; j++){
			// 计算w(i,j)的第一项
			T sum = element[ct] * m.element[cm];
			// 累加其余项
			for (int k = 2; k <= cols; k++){
				// 指向*this第i行的下一个元素
				ct++;
				// 指向m的第j列的下一项
				cm += m.cols;
				sum += element[ct] * m.element[cm];
			}
			// 保存w(i,j)
			w.element[cw++] = sum;
			// 重新调整至行首和下一列
			ct -= cols - 1;
			cm = j;
		}
		// 重新调整至下一行的行首和第一列
		ct += cols;
		cm = 0;
	}
	return w;
}

template<class T>
void Matrix<T>::Output(ostream& out)const{
	int size = rows * cols;
	for (int i = 0; i < size; i++){
		if (i == 0)
			out << "[";
		out << element[i] << " ";
		if (i == size - 1)
			out << "]";
		if ((i + 1) % cols == 0 && i != 0)
			out << "\n";
	}
}

template<class T>
ostream& operator<<(ostream& out, const Matrix<T>& m){
	m.Output(out);
	return out;
}


#endif