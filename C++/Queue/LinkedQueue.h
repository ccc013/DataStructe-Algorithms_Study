#ifndef LINKEDQUEUE_H_
#define LINKEDQUEUE_H_
#include<iostream>

template<class T>
class LinkedQueue;

template<class T>
class Node{
	friend LinkedQueue<T>;
private:
	T data;
	Node<T>* link;
};

template<class T>
class LinkedQueue{
private:
	Node<T>* front;
	Node<T>* rear;
public:
	LinkedQueue(){ front = rear = 0; }
	~LinkedQueue();
	bool IsEmpty() const{
		return ((front) ? false : true);
	}
	bool IsFull() const;
	T First() const;
	T Last() const;
	LinkedQueue<T>& Add(const T& x);
	LinkedQueue<T>& Delete(T& x);
	void Output(std::ostream&);
};

template<class T>
LinkedQueue<T>::~LinkedQueue(){
	Node<T>* next;
	while (front){
		next = front->link;
		delete front;
		front = next;
	}
}

template<class T>
bool LinkedQueue<T>::IsFull() const{
	Node<T> *p;
	try{
		p = new Node<T>;
		delete p;
		return false;
	}
	catch (NoMem){
		return true;
	}
}

template<class T>
T LinkedQueue<T>::First() const{
	if (IsEmpty())
		throw OutOfBounds();
	return front->data;
}

template<class T>
T LinkedQueue<T>::Last() const{
	if (IsEmpty())
		throw OutOfBounds();
	return rear->data;
}

template<class T>
LinkedQueue<T>& LinkedQueue<T>::Add(const T& x){
	// 添加元素x
	Node<T>* p = new Node<T>;
	p->data = x;
	p->link = 0;
	if (front)
		// 队列不为空
		rear->link = p;
	else
		// 队列为空
		front = p;
	rear = p;

	return *this;
}

template<class T>
LinkedQueue<T>& LinkedQueue<T>::Delete(T& x){
	// 删除第一个元素，并放入x
	if (IsEmpty())
		throw OutOfBounds();
	x = front->data;

	// 删除第一个节点
	Node<T>* p = front;
	front = front->link;
	delete p;

	return *this;
}

template<class T>
void LinkedQueue<T>::Output(std::ostream& out){
	if (IsEmpty()){
		out << "LinkedQueue is empty\n";
		return;
	}
	Node<T>* p = front;
	cout << "LinkedQueue--{";
	while (p){
		cout << p->data << ", ";
		p = p->link;
	}
	cout << "}\n";
}

template<class T>
std::ostream& operator<<(std::ostream& out, LinkedQueue<T>& q){
	q.Output(out);
	return out;
}


#endif