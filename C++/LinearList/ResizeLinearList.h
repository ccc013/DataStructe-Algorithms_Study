#ifndef RESIZELINEARLIST_H_
#define RESIZELINEARLIST_H_
#include<iostream>

template<class T>
class ResizeLinearList
{
private:
	int MaxSize;
	T *element;
	int length;		// ��ǰ���Ա�ĳ���
public:
	ResizeLinearList();
	~ResizeLinearList(){ delete[] element; }
	bool isEmpty() const{ return length == 0; }
	int Length() const { return length; }
	//��̬���������С
	bool Resize(int resizeCount);
	// ���ص�k��Ԫ����x��
	bool Find(int k, T&x) const;
	// ����x���ڵ�λ��
	int Search(const T& x) const;
	// ɾ����k��Ԫ�ز�����������x��
	ResizeLinearList<T>& Delete(int k, T&x);
	// �ڵ�k��Ԫ��֮�����x
	ResizeLinearList<T>& Insert(int k, const T& x);
	void Output(std::ostream &out) const;
};

template<class T>
ResizeLinearList<T>::ResizeLinearList(){
	MaxSize = 1;
	element = new T[MaxSize];
	length = 0;
}
// ���ص�k��Ԫ����x��
template<class T>
bool ResizeLinearList<T>::Find(int k, T&x) const{
	if (k <1 || k>length)
		return false;
	x = element[k - 1];
	return true;
}

// ����x���ڵ�λ��
template<class T>
int ResizeLinearList<T>::Search(const T& x) const{
	for (int i = 0; i < length; i++){
		if (element[i] == x)
			return ++i;
	}
	return 0;
}

template<class T>
bool ResizeLinearList<T>::Resize(int resizeCount){
	// ������Ĵ�С����������е�����Ԫ�ظ���
	if (resizeCount <= length){
		std::cerr << "should give a larger numbers than current array numbers\n";
		return false;
	}
	// �������������
	MaxSize = resizeCount;
	T * newElement = new T[resizeCount];
	for (int i = 0; i < length; i++)
		newElement[i] = element[i];
	delete[] element;
	element = newElement;
	return true;
}

// ɾ����k��Ԫ�ز�����������x��
template<class T>
ResizeLinearList<T>& ResizeLinearList<T>::Delete(int k, T&x){
	// ��������ڵ�k��Ԫ�أ��������쳣OutOfBounds
	if (Find(k, x)){
		// ����k��Ԫ�غ��Ԫ����ǰ�ƶ�һ��λ��
		for (int i = k; i < length; i++)
			element[i - 1] = element[i];
		length--;
		// �����ǰԪ����������1/4�������������������Сһ��
		if (length == (int)MaxSize * 0.25)
			Resize((int)0.5 * MaxSize);
		return *this;
	}
	else
		throw OutOfBounds();
}

// �ڵ�k��Ԫ��֮�����x
template<class T>
ResizeLinearList<T>& ResizeLinearList<T>::Insert(int k, const T&x){
	// ��������ڵ�k��Ԫ�أ��������쳣OutOfBounds
	if (k<0 || k>length)
		throw OutOfBounds();
	// �����������������2������
	if (length == MaxSize)
		Resize(2*MaxSize);
	// ����ƶ�һ��λ��
	for (int i = length - 1; i >= k; i--)
		element[i + 1] = element[i];
	element[k] = x;
	length++;
	return *this;
}

template<class T>
void ResizeLinearList<T>::Output(std::ostream &out)const{
	for (int i = 0; i < length; i++)
		out << element[i] << " ";
}
// ���� <<
template<class T>
std::ostream& operator<<(std::ostream&out, const ResizeLinearList<T>& x){
	x.Output(out);
	return out;
}


#endif