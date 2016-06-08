#ifndef RESIZELINEARLIST_H_
#define RESIZELINEARLIST_H_
#include<iostream>

template<class T>
class ResizeLinearList
{
private:
	int MaxSize;
	T *element;
	int length;		// 当前线性表的长度
public:
	ResizeLinearList();
	~ResizeLinearList(){ delete[] element; }
	bool isEmpty() const{ return length == 0; }
	int Length() const { return length; }
	//动态调整数组大小
	bool Resize(int resizeCount);
	// 返回第k个元素至x中
	bool Find(int k, T&x) const;
	// 返回x所在的位置
	int Search(const T& x) const;
	// 删除第k个元素并将它返回至x中
	ResizeLinearList<T>& Delete(int k, T&x);
	// 在第k个元素之后插入x
	ResizeLinearList<T>& Insert(int k, const T& x);
	void Output(std::ostream &out) const;
};

template<class T>
ResizeLinearList<T>::ResizeLinearList(){
	MaxSize = 1;
	element = new T[MaxSize];
	length = 0;
}
// 返回第k个元素至x中
template<class T>
bool ResizeLinearList<T>::Find(int k, T&x) const{
	if (k <1 || k>length)
		return false;
	x = element[k - 1];
	return true;
}

// 返回x所在的位置
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
	// 新数组的大小必须大于现有的数组元素个数
	if (resizeCount <= length){
		std::cerr << "should give a larger numbers than current array numbers\n";
		return false;
	}
	// 更新数组的容量
	MaxSize = resizeCount;
	T * newElement = new T[resizeCount];
	for (int i = 0; i < length; i++)
		newElement[i] = element[i];
	delete[] element;
	element = newElement;
	return true;
}

// 删除第k个元素并将它返回至x中
template<class T>
ResizeLinearList<T>& ResizeLinearList<T>::Delete(int k, T&x){
	// 如果不存在第k个元素，则引发异常OutOfBounds
	if (Find(k, x)){
		// 将第k个元素后的元素向前移动一个位置
		for (int i = k; i < length; i++)
			element[i - 1] = element[i];
		length--;
		// 如果当前元素数量等于1/4的容量，则将最大容量缩小一半
		if (length == (int)MaxSize * 0.25)
			Resize((int)0.5 * MaxSize);
		return *this;
	}
	else
		throw OutOfBounds();
}

// 在第k个元素之后插入x
template<class T>
ResizeLinearList<T>& ResizeLinearList<T>::Insert(int k, const T&x){
	// 如果不存在第k个元素，则引发异常OutOfBounds
	if (k<0 || k>length)
		throw OutOfBounds();
	// 如果表已满，则增加2倍容量
	if (length == MaxSize)
		Resize(2*MaxSize);
	// 向后移动一个位置
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
// 重载 <<
template<class T>
std::ostream& operator<<(std::ostream&out, const ResizeLinearList<T>& x){
	x.Output(out);
	return out;
}


#endif