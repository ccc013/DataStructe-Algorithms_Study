#ifndef INDRECTLIST_H_
#define INDRECTLIST_H_
#include<iostream>

template<class T>
class IndrectList{
private:
	T **table;		// 一维T类型指针数组
	int length, MaxSize;
public:
	IndrectList(int MaxListSize = 10);
	~IndrectList();
	bool isEmpty() const{ return length == 0; }
	int Length() const { return length; }
	bool Find(int k, T&x)const;
	int Search(const T& x)const;
	IndrectList<T>& Delete(int k, T& x);
	IndrectList<T>& Insert(int k, const T& x);
	void Output(std::ostream& out)const;
};

template<class T>
IndrectList<T>::IndrectList(int MaxListSize){
	MaxSize = MaxListSize;
	table = new T *[MaxSize];
	length = 0;
}

template<class T>
IndrectList<T>::~IndrectList(){
	// 删除表
	for (int i = 0; i < length; i++)
		delete table[i];
	delete[] table;
}

template<class T>
bool IndrectList<T>::Find(int k, T& x)const{
	if (k<1 || k>length)
		return false;
	x = *table[k - 1];
	return true;
}

template<class T>
int IndrectList<T>::Search(const T& x)const{
	// 返回x所处位置，如果没有则返回0；
	for (int i = 0; i < length; i++){
		if (*table[i] == x)
			return ++i;
	}
	return 0;
}


template<class T>
IndrectList<T>& IndrectList<T>::Delete(int k, T&x){
	if (Find(k, x)){
		// 向前移动指针
		for (int i = k; i < length; i++)
			table[i - 1] = table[i];
		length--;
		return *this;
	}
else 
	throw OutOfBounds();
}

template<class T>
IndrectList<T>& IndrectList<T>::Insert(int k, const T& x){
	if (k<0 || k>length)
		throw OutOfBounds();
	if (length == MaxSize)
		throw NoMem();
	// 向后移动一位
	for (int i = length - 1; i >= k; i--)
		table[i + 1] = table[i];
	table[k] = new T;
	*table[k] = x;
	length++;
	return *this;
}

template<class T>
void IndrectList<T>::Output(std::ostream &out)const{
	for (int i = 0; i < length; i++)
		out << *table[i] << " ";
}
// 重载 <<
template<class T>
std::ostream& operator<<(std::ostream&out, const IndrectList<T>& x){
	x.Output(out);
	return out;
}

#endif