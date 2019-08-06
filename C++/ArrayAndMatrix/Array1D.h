#ifndef ARRAY1D_H_
#define ARRAY1D_H_

#include<iostream>

template<class T>
class Array1D{
private:
	int size;
	T *element;		// 一维数组
public:
	Array1D(int size = 0);
	// 复制构造函数
	Array1D(const Array1D<T>& x);	
	~Array1D(){ delete[] element; }
	T& operator[](int i)const;
	int Size(){ return size; }
	Array1D<T>& operator=(const Array1D<T>& v);
	// 一元加法操作符
	Array1D<T> operator+()const;
	Array1D<T> operator+(const Array1D<T>& v)const;
	// 一元减法操作法
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
	// 复制构造函数
	size = v.size;
	element = new T[size];
	for (int i = 0; i < size; i++)
		element[i] = v.element[i];
}

template<class T>
T& Array1D<T>::operator[](int i)const{
	// 返回第i个元素的引用
	if (i < 0 || i >= size)
		throw OutOfBounds();
	return element[i];
}

template<class T>
Array1D<T>& Array1D<T>::operator=(const Array1D<T>& v){
	// 重载赋值运算符
	if (this != &v){
		// 不是自我赋值
		size = v.size;
		delete[] element;
		element = new T[size];
		// 复制元素
		for (int i = 0; i < size; i++)
			element[i] = v.element[i];
	}
	return *this;
}

// 二元减法操作符
template<class T>
Array1D<T> Array1D<T>::operator-(const Array1D<T>& v)const{
	// 返回 w = (*this) - v
	if (size != v.size)
		throw SizeMismatch();
	Array1D<T> w(size);
	for (int i = 0; i < size; i++)
		w.element[i] = element[i] - v.element[i];
	return w;
}

// 一元减法操作符
template<class T>
Array1D<T> Array1D<T>::operator-() const{
	// 返回 w = -(*this)
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

// 一元加法操作符
template<class T>
Array1D<T> Array1D<T>::operator+() const{
	Array1D<T> w(size);
	for (int i = 0; i < size; i++)
		w.element[i] = +element[i];
	return w;
}

// 二元加法操作符
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