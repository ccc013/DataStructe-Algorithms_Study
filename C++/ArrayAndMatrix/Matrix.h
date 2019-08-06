#ifndef MATRIX_H_
#define MATRIX_H_
#include<iostream>
using std::ostream;

template<class T>
class Matrix{
private:
	int rows, cols;
	// Ԫ������
	T *element;
public:
	Matrix(int r = 0, int c = 0);
	// ���ƹ��캯��
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
	// ���ƹ��캯��
	rows = m.rows;
	cols = m.cols;
	element = new T[rows*cols];
	int size = rows * cols;
	for (int i = 0; i < size; i++)
		element[i] = m.element[i];
}

template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& m){
	// ���ظ�ֵ�����=
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
	// ����һ��ָ��Ԫ��(i,j)������
	if (i<1 || i>rows || j<1 || j>cols)
		throw OutOfBounds();
	return element[(i - 1)*cols + j - 1];
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& m)const{
	// ��Ԫ����
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
	// һԪ����
	Matrix<T> w(rows, cols);
	for (int i = 0; i < rows * cols; i++){
		w.element[i] = -element[i] ;
	}
	return w;
}

template<class T>
Matrix<T> Matrix<T>::operator+()const{
	// һԪ�ӷ�
	Matrix<T> w(rows, cols);
	for (int i = 0; i < rows * cols; i++){
		w.element[i] = element[i];
	}
	return w;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& m)const{
	// ��Ԫ�ӷ�
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
	// ��ֵ�����
	for (int i = 0; i < rows * cols; i++){
		element[i] += m;
	}
	return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& m)const{
	// ����˷� ����w = (*this) * m
	if (cols != m.rows)
		throw SizeMismatch();
	Matrix<T> w(rows, m.cols);
	int ct = 0, cm = 0, cw = 0;
	for (int i = 1; i <= rows; i++){
		// ���������ĵ�i��
		for (int j = 1; j <= m.cols; j++){
			// ����w(i,j)�ĵ�һ��
			T sum = element[ct] * m.element[cm];
			// �ۼ�������
			for (int k = 2; k <= cols; k++){
				// ָ��*this��i�е���һ��Ԫ��
				ct++;
				// ָ��m�ĵ�j�е���һ��
				cm += m.cols;
				sum += element[ct] * m.element[cm];
			}
			// ����w(i,j)
			w.element[cw++] = sum;
			// ���µ��������׺���һ��
			ct -= cols - 1;
			cm = j;
		}
		// ���µ�������һ�е����׺͵�һ��
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