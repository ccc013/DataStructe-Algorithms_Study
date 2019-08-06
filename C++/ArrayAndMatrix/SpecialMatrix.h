#ifndef SPECIALMATRIX_H_
#define SPECIALMATRIX_H_

/*****�ԽǾ���******/
template<class T>
class DiagonalMatrix{
private:
	// ����ά��
	int n;
	// �洢�Խ�Ԫ�ص�һά����
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
	// ��x��ΪD(i,j)
	if (i<1 || j<1 || i>n || j>n)
		throw OutOfBounds();
	if (i != j && x != 0)
		// ��������ԽǾ����������i != j ʱ��x����Ϊ0
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

/*****���ԽǾ���********/
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
	// ��x��ΪT(i,j)
	if (i<1 || j<1 || i>n || j>n)
		throw OutOfBounds();
	switch (i-j){
		case 1:
			// �ͶԽ���
			t[i - 2] = x;
			break;
		case 0:
			// ���Խ���
			t[n - 2 + i] = x;
			break;
		case -1:
			// �߶Խ���
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
		// �ͶԽ���
		return t[i - 2];
	case 0:
		// ���Խ���
		return t[n - 2 + i];
	case -1:
		// �߶Խ���
		return t[2 * n - 2 + i];
	default:
		return 0;
	}
}
/*******************/

/***�����Ǿ���***/
template<class T>
class LowerMatrix{
private:
	// ����ά��
	int n;
	// �洢�Խ�Ԫ�ص�һά����
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
	// ��x��ΪD(i,j)
	if (i<1 || j<1 || i>n || j>n)
		throw OutOfBounds();
	// ��ǰ���� i >= jʱ��(i,j)λ��������
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