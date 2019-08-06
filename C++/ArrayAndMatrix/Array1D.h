#ifndef ARRAY1D_H_
#define ARRAY1D_H_

#include<iostream>

template<class T>
class Array1D{
private:
	int size;
	T *element;		// һά����
public:
	Array1D(int size = 0);
	// ���ƹ��캯��
	Array1D(const Array1D<T>& x);	
	~Array1D(){ delete[] element; }
	T& operator[](int i)const;
	int Size(){ return size; }
	Array1D<T>& operator=(const Array1D<T>& v);
	// һԪ�ӷ�������
	Array1D<T> operator+()const;
	Array1D<T> operator+(const Array1D<T>& v)const;
	// һԪ����������
	Array1D<T> operator-() const;
	Array1D<T> operator-(const Array1D<T>& v)const;
	Array1D<T> operator*(const Array1D<T>& v)const;
	Array1D<T>& operator+=(const T& x);
};

template<class T>
Array1D<T>::Array1D(int sz){
	if (sz <= 0)
		throw BadInitializers();
	size = sz;
	element = new T[size];
}

template<class T>
Array1D<T>::Array1D(const Array1D<T>& v){
	// ���ƹ��캯��
	size = v.size;
	element = new T[size];
	for (int i = 0; i < size; i++)
		element[i] = v.element[i];
}

template<class T>
T& Array1D<T>::operator[](int i)const{
	// ���ص�i��Ԫ�ص�����
	if (i < 0 || i >= size)
		throw OutOfBounds();
	return element[i];
}

template<class T>
Array1D<T>& Array1D<T>::operator=(const Array1D<T>& v){
	// ���ظ�ֵ�����
	if (this != &v){
		// �������Ҹ�ֵ
		size = v.size;
		delete[] element;
		element = new T[size];
		// ����Ԫ��
		for (int i = 0; i < size; i++)
			element[i] = v.element[i];
	}
	return *this;
}

// ��Ԫ����������
template<class T>
Array1D<T> Array1D<T>::operator-(const Array1D<T>& v)const{
	// ���� w = (*this) - v
	if (size != v.size)
		throw SizeMismatch();
	Array1D<T> w(size);
	for (int i = 0; i < size; i++)
		w.element[i] = element[i] - v.element[i];
	return w;
}

// һԪ����������
template<class T>
Array1D<T> Array1D<T>::operator-() const{
	// ���� w = -(*this)
	Array1D<T> w(size);
	for (int i = 0; i < size; i++)
		w.element[i] = -element[i];
	return w;
}

template<class T>
Array1D<T>& Array1D<T>::operator+=(const T& x){
	for (int i = 0; i < size; i++)
		element[i] += x;
	return *this;
}

// һԪ�ӷ�������
template<class T>
Array1D<T> Array1D<T>::operator+() const{
	Array1D<T> w(size);
	for (int i = 0; i < size; i++)
		w.element[i] = +element[i];
	return w;
}

// ��Ԫ�ӷ�������
template<class T>
Array1D<T> Array1D<T>::operator+(const Array1D<T>& v) const{
	if (size != v.size)
		throw SizeMismatch();
	Array1D<T> w(size);
	for (int i = 0; i < size; i++)
		w.element[i] = element[i] + v.element[i];
	return w;
}

template<class T>
Array1D<T> Array1D<T>::operator*(const Array1D<T>& v) const{
	if (size != v.size)
		throw SizeMismatch();
	Array1D<T> w(size);
	for (int i = 0; i < size; i++)
		w.element[i] = element[i] * v.element[i];
	return w;
}

#endif