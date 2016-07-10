#ifndef STACK_H_
#define STACK_H_
#include<iostream>

template<class T>
class Stack{
private:
	// 栈顶
	int top;
	// 最大的栈顶值
	int MaxTop;
	// 堆栈元素数组
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
	// 构造函数
	MaxTop = MaxStackSize - 1;
	stack = new T[MaxStackSize];
	top = -1;
}

template<class T>
T Stack<T>::Top()const{
	// 返回栈顶元素
	if (IsEmpty())
		throw OutOfBounds();
	else
		return stack[top];
}

template<class T>
Stack<T>& Stack<T>::Add(const T& x){
	// 添加元素
	if (IsFull())
		throw NoMem();
	stack[++top] = x;
	return *this;
}

template<class T>
Stack<T>& Stack<T>::Delete(T& x){
	// 删除栈顶元素，并将其传送入x
	if (IsEmpty())
		throw OutOfBounds();
	x = stack[top--];
	return *this;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const Stack<T>& x){
	int pos = x.top;
	if (x.IsEmpty())
		std::cout << "There is no elements in stack";
	while (pos != -1){
		std::cout << x.stack[pos] << " ";
		pos--;
	}
	std::cout << "\n";
	return out;
}

#endif