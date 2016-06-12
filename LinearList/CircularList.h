#ifndef CIRCULARLIST_H_
#define CIRCULARLIST_H_
#include<iostream>


template<class T>
class CircularList{
private:
	// 指向第一个节点的指针
	ChainNode<T> *first;
public:
	CircularList();
	~CircularList();
	bool isEmpty() const{ return first->link == first; }
	int Length() const;
	bool Find(int k, T& x)const;
	int Search(const T& x)const;
	CircularList<T>& Delete(int k, T& x);
	CircularList<T>& Insert(int k, const T&x);
	void Output(std::ostream& out)const;
};

template<class T>
CircularList<T>::CircularList(){
	// 带有头节点的空的循环链表
	first = new ChainNode<T>;
	first->link = first;
}

template<class T>
CircularList<T>::~CircularList(){
	ChainNode<T>* current = first->link;
	while (current != first){
		first->link = current->link;
		delete current;
		current = first->link;
	}
}

template<class T>
int CircularList<T>::Length() const{
	// 返回链表中的元素总数
	ChainNode<T>* current = first->link;
	int len = 0;
	while (current != first){
		len++;
		current = current->link;
	}
	return len;
}

template<class T>
bool CircularList<T>::Find(int k, T&x)const{
	// 寻找链表中的第k个元素，并将其传送者x
	if (k < 1)
		return false;
	ChainNode<T>* p = first->link;
	int index = 1;
	while (index < k && p->link != first){
		index++;
		p = p->link;
	}
	if (p->link != first){
		x = p->data;
		return true;
	}
	return false;
}

template<class T>
int CircularList<T>::Search(const T& x)const{
	// 在带有头节点的循环链表中查找x
	ChainNode<T>* current = first->link;
	int index = 1;
	first->data = x;	// 把x放入头节点
	while (current->data != x){
		current = current->link;
		index++;
	}
	// 判断是否是链表头节点
	return ((current == first) ? 0 : index);
}

template<class T>
void CircularList<T>::Output(std::ostream& out)const{
	//  将链表元素送至输出流
	ChainNode<T> *current;
	for (current = first->link; current != first; current = current->link){
		out << current->data << " ";
	}
}

// 重载 <<
template<class T>
std::ostream& operator<<(std::ostream& out, const CircularList<T>& x){
	x.Output(out);
	return out;
}

template<class T>
CircularList<T>& CircularList<T>::Insert(int k, const T& x){
	// 在第k个元素后面插入x
	if (k < 0)
		throw OutOfBounds();
	ChainNode<T>* current = first->link;
	for (int index = 1; index < k && current != first; index++)
		current = current->link;
	if (k>0 && current == first)
		// 不存在第k个元素
		throw OutOfBounds();
	ChainNode<T>* newNode = new ChainNode<T>;
	newNode->data = x;
	if (k){
		newNode->link = current->link;
		current->link = newNode;
	}
	else{
		// k=0，作为第一个元素插入
		newNode->link = first->link;
		first->link = newNode;
	}

	return *this;
}

template<class T>
CircularList<T>& CircularList<T>::Delete(int k, T&x){
	// 把第k个元素取至x，然后删除第k个元素
	if (k < 1 || first->link == first)
		throw OutOfBounds();
	ChainNode<T>* current = first->link;
	if (k == 1){
		first->link = current->link;
	}
	else{
		ChainNode<T>* q = first->link;
		int index = 1;
		for (; index < k - 1 && q != first; index++)
			q = q->link;
		if (q == first || q->link == first)
			// 不存在第k个元素
			throw OutOfBounds();
		// 存在第k个元素
		current = q->link;
		q->link = current->link;
	}
	x = current->data;
	delete current;
	return *this;
}


#endif