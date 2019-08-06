#ifndef LINEARLIST_H_
#define LINEARLIST_H_
#include<iostream>

template<class T>
class LinearList
{
private:
	int MaxSize;
	T *element;
	int length;		// ��ǰ���Ա�ĳ���
protected:
	int GetMaxSize() const{
		return MaxSize;
	}
public:
	LinearList(int MaxListSize = 10);
	~LinearList(){ delete[] element; }
	bool isEmpty() const{ return length == 0; }
	int Length() const { return length; }
	// ���ص�k��Ԫ����x��
	bool Find(int k, T&x) const;
	// ����x���ڵ�λ��
	int Search(const T& x) const;
	// ɾ����k��Ԫ�ز�����������x��
	LinearList<T>& Delete(int k, T&x);
	// �ڵ�k��Ԫ��֮�����x
	LinearList<T>& Insert(int k, const T& x);
	void Output(std::ostream &out) const;

};


template<class T>
LinearList<T>::LinearList(int MaxListSize){
	MaxSize = MaxListSize;
	element = new T[MaxSize];
	length = 0;
}

// ���ص�k��Ԫ����x��
template<class T>
bool LinearList<T>::Find(int k, T&x) const{
	if (k <1 || k>length)
		return false;
	x = element[k - 1];
	return true;
}

// ����x���ڵ�λ��
template<class T>
int LinearList<T>::Search(const T& x) const{
	for (int i = 0; i < length; i++){
		if (element[i] == x)
			return ++i;
	}
	return 0;
}

// ɾ����k��Ԫ�ز�����������x��
template<class T>
LinearList<T>& LinearList<T>::Delete(int k, T&x){
	// ��������ڵ�k��Ԫ�أ��������쳣OutOfBounds
	if (Find(k, x)){
		// ����k��Ԫ�غ��Ԫ����ǰ�ƶ�һ��λ��
		for (int i = k; i < length; i++)
			element[i - 1] = element[i];
		length--;
		return *this;
	}
	else
		throw OutOfBounds();
}

// �ڵ�k��Ԫ��֮�����x
template<class T>
LinearList<T>& LinearList<T>::Insert(int k, const T&x){
	// ��������ڵ�k��Ԫ�أ��������쳣OutOfBounds
	if (k<0 || k>length)
		throw OutOfBounds();
	// ������������������쳣NoMem
	if (length == MaxSize)
		throw NoMem();
	// ����ƶ�һ��λ��
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
// ���� <<
template<class T>
std::ostream& operator<<(std::ostream&out, const LinearList<T>& x){
	x.Output(out);
	return out;
}
#endif