#ifndef SPECIALMATRIX_H_
#define SPECIALMATRIX_H_

/*****对角矩阵******/
template<class T>
class DiagonalMatrix{
private:
	// 矩阵维数
	int n;
	// 存储对角元素的一维数组
	T *d;		
public:
	DiagonalMatrix(int size = 10): n(size){
		d = new T[n];
	}
	~DiagonalMatrix(){ delete[] d; }
	DiagonalMatrix<T>& Store(const T& x, int i, int j);
	T Retrieve(int i, int j)const;
};

template<class T>
DiagonalMatrix<T>& DiagonalMatrix<T>::Store(const T&x, int i, int j){
	// 将x存为D(i,j)
	if (i<1 || j<1 || i>n || j>n)
		throw OutOfBounds();
	if (i != j && x != 0)
		// 必须满足对角矩阵的条件：i != j 时，x必须为0
		throw MustBeZero();
	if (i == j)
		d[i - 1] = x;
	return *this;
}

template<class T>
T DiagonalMatrix<T>::Retrieve(int i, int j)const{
	if (i<1 || j<1 || i>n || j>n)
		throw OutOfBounds();
	if (i == j)
		return d[i - 1];
	return 0;
}

/***********************/

/*****三对角矩阵********/
template<class T>
class TridiagonalMatrix{
private:
	int n;
	T *t;
public:
	TridiagonalMatrix(int size = 10) : n(size){
		t = new T[3 * n - 2];
	}
	~TridiagonalMatrix(){delete[] t;}
	TridiagonalMatrix<T>& Store(const T& x, int i, int j);
	T Retrieve(int i, int j)const;
};

template<class T>
TridiagonalMatrix<T>& TridiagonalMatrix<T>::Store(const T& x, int i, int j){
	// 把x存为T(i,j)
	if (i<1 || j<1 || i>n || j>n)
		throw OutOfBounds();
	switch (i-j){
		case 1:
			// 低对角线
			t[i - 2] = x;
			break;
		case 0:
			// 主对角线
			t[n - 2 + i] = x;
			break;
		case -1:
			// 高对角线
			t[2 * n - 2 + i] = x;
			break;
		default:
			if (x != 0)
				throw MustBeZero();
	}
	return *this;
}

template<class T>
T TridiagonalMatrix<T>::Retrieve(int i, int j)const{
	if (i<1 || j<1 || i>n || j>n)
		throw OutOfBounds();
	switch (i - j){
	case 1:
		// 低对角线
		return t[i - 2];
	case 0:
		// 主对角线
		return t[n - 2 + i];
	case -1:
		// 高对角线
		return t[2 * n - 2 + i];
	default:
		return 0;
	}
}
/*******************/

/***下三角矩阵***/
template<class T>
class LowerMatrix{
private:
	// 矩阵维数
	int n;
	// 存储对角元素的一维数组
	T *t;
public:
	LowerMatrix(int size = 10) : n(size){
		t = new T[n*(n+1)/2];
	}
	~LowerMatrix(){ delete[] t; }
	LowerMatrix<T>& Store(const T& x, int i, int j);
	T Retrieve(int i, int j)const;
};

template<class T>
LowerMatrix<T>& LowerMatrix<T>::Store(const T&x, int i, int j){
	// 将x存为D(i,j)
	if (i<1 || j<1 || i>n || j>n)
		throw OutOfBounds();
	// 当前仅当 i >= j时，(i,j)位于下三角
	if (i >= j)
		t[i*(i - 1) / 2 + j - 1] = x;
	else if (x != 0)
		throw MustBeZero();
	return *this;
}

template<class T>
T LowerMatrix<T>::Retrieve(int i, int j)const{
	if (i<1 || j<1 || i>n || j>n)
		throw OutOfBounds();
	if (i >= j)
		return t[i*(i - 1) / 2 + j - 1];
	else
		return 0;
}

#endif