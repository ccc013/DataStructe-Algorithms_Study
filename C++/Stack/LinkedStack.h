#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_
#include<iostream>
using std::ostream;
template<class T>
class LinkedStack;

template<class T>
class Node{
	friend LinkedStack<T>;
private:
	T data;
	Node<T>* link;
};

template<class T>
class LinkedStack{
private:
	Node<T>* top;
public:
	LinkedStack(){ top = 0; }
	~LinkedStack();
	bool IsEmpty() const{ return top == 0; }
	bool IsFull() const;
	T Top()const;
	LinkedStack<T>& Add(const T& x);
	LinkedStack<T>& Delete(T& x);
	void Output(ostream&);
};

// 析构函数
template<class T>
LinkedStack<T>::~LinkedStack(){
	Node<T>* next;
	while (top){
		next = top->link;
		delete top;
		top = next;
	}
}

template<class T>
bool LinkedStack<T>::IsFull()const{
	try{
		Node<T>* p = new Node<T>;
		delete p;
		return false;
	}
	catch (NoMem){
		return true;
	}
}

template<class T>
T LinkedStack<T>::Top()const{
	if (IsEmpty())
		throw OutOfBounds();
	return top->data;
}

template<class T>
LinkedStack<T>& LinkedStack<T>::Add(const T& x){
	// 添加元素x
	Node<T>* p = new Node<T>;
	p->data = x;
	p->link = top;
	top = p;
	return *this;
}

template<class T>
LinkedStack<T>& LinkedStack<T>::Delete(T& x){
	// 删除元素，并传给x返回
	if (IsEmpty())
		throw OutOfBounds();
	x = top->data;
	Node<T>* p = top;
	top = top->link;
	delete p;
	return *this;
}

template<class T>
void LinkedStack<T>::Output(ostream& out){
	if (IsEmpty())
		out << "There is no elements in LinkedStack";
	Node<T>* p = top;
	while (p){
		out << p->data << " ";
		p = p->link;
	}
	out << "\n";
}

template<class T>
ostream& operator<<(ostream& out,LinkedStack<T>& x){
	x.Output(out);
	return out;
}

#endif