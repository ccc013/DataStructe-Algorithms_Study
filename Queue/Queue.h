#ifndef QUEUE_H_
#define QUEUE_H_
#include<iostream>

template<class T>
class Queue{
private:
	// 与第一个元素在逆时针方向上相差一个位置
	int front;
	// 指向最后一个元素
	int rear;
	int MaxSize;
	T* queue;
public:
	Queue(int MaxQueueSize = 10);
	~Queue(){ delete[] queue; }
	bool IsEmpty() const { return front == rear; }
	bool IsFull() const {
		return (((rear + 1) % MaxSize == front) ? 1 : 0);
	}
	T First() const;
	T Last() const;
	Queue<T>& Add(const T& x);
	Queue<T>& Delete(T& x);
	void Output(std::ostream&);
};

template<class T>
Queue<T>::Queue(int MaxQueueSize) : MaxSize(MaxQueueSize+1),front(0),rear(0){
	// 创建一个容量为MaxQueueSize的空队列
	queue = new T[MaxSize];
}

template<class T>
T Queue<T>::First() const{
	if (IsEmpty())
		throw OutOfBounds();
	return queue[(front + 1) % MaxSize];
}

template<class T>
T Queue<T>::Last() const{
	if (IsEmpty())
		throw OutOfBounds();
	return queue[rear];
}

template<class T>
Queue<T>& Queue<T>::Add(const T& x){
	// 将x添加到队列的尾部
	if (IsFull())
		throw NoMem();
	rear = (rear + 1) % MaxSize;
	queue[rear] = x;
	return *this;
}

template<class T>
Queue<T>& Queue<T>::Delete(T& x){
	// 删除第一个元素，并将其送入x
	if (IsEmpty())
		throw OutOfBounds();
	front = (front + 1)&MaxSize;
	x = queue[front];
	return *this;
}

template<class T>
void Queue<T>::Output(std::ostream& out){
	if (IsEmpty()){
		out << "Queue is empty\n";
		return;
	}
	int first = (front+1)%MaxSize;
	while (first <= rear){
		out << queue[first++] << " ";
	}
	out << "\n";
}

template<class T>
std::ostream& operator<<(std::ostream& out, Queue<T>& q){
	q.Output(out);
	return out;
}


#endif