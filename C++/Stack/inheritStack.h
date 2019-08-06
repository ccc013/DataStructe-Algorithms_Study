#ifndef INHERITSTACK_H_
#define INHERITSTACK_H_
#include<iostream>

template<class T>
class Stack : private LinearList<T>
{
public:
	Stack(int MaxStackSize = 10) : LinearList<T>(MaxStackSize){}
	bool IsEmpty() const{
		return LinearList<T>::isEmpty();
	}
	bool IsFull() const{
		return (Length() == GetMaxSize());
	}
	T Top() const;
	Stack<T>& Add(const T& x);
	Stack<T>& Delete(T& x);
	void Output(std::ostream& out)const;
};

template<class T>
T Stack<T>::Top() const{
	if (IsEmpty())
		throw OutOfBounds();
	T x;
	Find(Length(), x);
	return x;
}

template<class T>
Stack<T>& Stack<T>::Add(const T& x){
	Insert(Length(), x);
	return *this;
}

template<class T>
Stack<T>& Stack<T>::Delete(T& x){
	LinearList<T>::Delete(Length(), x);
	return *this;
}

template<class T>
void Stack<T>::Output(std::ostream& out)const{
	
	for (int i = 0; i < length; i++)
		out << element[i] << " ";
	out << "\n";
}

// жиди <<
template<class T>
std::ostream& operator<<(std::ostream&out, const Stack<T>& x){
	x.Output(out);
	return out;
}


#endif