#ifndef STACK_H_
#define STACK_H_
#include<iostream>

template<class T>
class Stack{
private:
	// ջ��
	int top;
	// ����ջ��ֵ
	int MaxTop;
	// ��ջԪ������
	T* stack;
public:
	Stack(int MaxStackSize = 10);
	~Stack(){ delete[] stack; }
	bool IsEmpty() const{ return top == -1; }
	bool IsFull() const { return top == MaxTop; }
	T Top() const;
	Stack<T>& Add(const T& x);
	Stack<T>& Delete(T& x);
	template<class T>
	friend std::ostream& operator<<(std::ostream&, const Stack<T>&);
};

template<class T>
Stack<T>::Stack(int MaxStackSize){
	// ���캯��
	MaxTop = MaxStackSize - 1;
	stack = new T[MaxStackSize];
	top = -1;
}

template<class T>
T Stack<T>::Top()const{
	// ����ջ��Ԫ��
	if (IsEmpty())
		throw OutOfBounds();
	else
		return stack[top];
}

template<class T>
Stack<T>& Stack<T>::Add(const T& x){
	// ���Ԫ��
	if (IsFull())
		throw NoMem();
	stack[++top] = x;
	return *this;
}

template<class T>
Stack<T>& Stack<T>::Delete(T& x){
	// ɾ��ջ��Ԫ�أ������䴫����x
	if (IsEmpty())
		throw OutOfBounds();
	x = stack[top--];
	return *this;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const Stack<T>& x){
	int pos = x.top;
	if (x.IsEmpty())
		out << "There is no elements in stack";
	while (pos != -1){
		out << x.stack[pos] << " ";
		pos--;
	}
	out << "\n";
	return out;
}

#endif