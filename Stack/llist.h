#ifndef LINEARLIST_H_
#define LINEARLIST_H_
#include<iostream>

template<class T>
class LinearList
{
private:
	int MaxSize;
	T *element;
	int length;		// 当前线性表的长度
protected:
	int GetMaxSize() const{
		return MaxSize;
	}
public:
	LinearList(int MaxListSize = 10);
	~LinearList(){ delete[] element; }
	bool isEmpty() const{ return length == 0; }
	int Length() const { return length; }
	// 返回第k个元素至x中
	bool Find(int k, T&x) const;
	// 返回x所在的位置
	int Search(const T& x) const;
	// 删除第k个元素并将它返回至x中
	LinearList<T>& Delete(int k, T&x);
	// 在第k个元素之后插入x
	LinearList<T>& Insert(int k, const T& x);
	void Output(std::ostream &out) const;

};


template<class T>
LinearList<T>::LinearList(int MaxListSize){
	MaxSize = MaxListSize;
	element = new T[MaxSize];
	length = 0;
}

// 返回第k个元素至x中
template<class T>
bool LinearList<T>::Find(int k, T&x) const{
	if (k <1 || k>length)
		return false;
	x = element[k - 1];
	return true;
}

// 返回x所在的位置
template<class T>
int LinearList<T>::Search(const T& x) const{
	for (int i = 0; i < length; i++){
		if (element[i] == x)
			return ++i;
	}
	return 0;
}

// 删除第k个元素并将它返回至x中
template<class T>
LinearList<T>& LinearList<T>::Delete(int k, T&x){
	// 如果不存在第k个元素，则引发异常OutOfBounds
	if (Find(k, x)){
		// 将第k个元素后的元素向前移动一个位置
		for (int i = k; i < length; i++)
			element[i - 1] = element[i];
		length--;
		return *this;
	}
	else
		throw OutOfBounds();
}

// 在第k个元素之后插入x
template<class T>
LinearList<T>& LinearList<T>::Insert(int k, const T&x){
	// 如果不存在第k个元素，则引发异常OutOfBounds
	if (k<0 || k>length)
		throw OutOfBounds();
	// 如果表已满，则引发异常NoMem
	if (length == MaxSize)
		throw NoMem();
	// 向后移动一个位置
	for (int i = length - 1; i >= k; i--)
		element[i + 1] = element[i];
	element[k] = x;
	length++;
	return *this;
}

template<class T>
void LinearList<T>::Output(std::ostream &out)const{
	for (int i = 0; i < length; i++)
		out << element[i] << " ";
}
// 重载 <<
template<class T>
std::ostream& operator<<(std::ostream&out, const LinearList<T>& x){
	x.Output(out);
	return out;
}
#endif