#ifndef CHAIN_H_
#define CHAIN_H_
#include<iostream>
// 必须先声明，否则友元模板类之间无法直接访问，会出现未定义的错误。
template<class T>
class Chain;
template<class T>
class ChainIterator;
template<class T>
class CircularList;

template<class T>
class ChainNode{
	friend Chain<T>;
	friend ChainIterator<T>;
	friend CircularList<T>;
private:
	T data;
	ChainNode<T> * link;
};
template<class T>
class Chain{
	friend ChainIterator<T>;
private:
	// 指向第一个节点的指针
	ChainNode<T> *first;
	// 指向最后一个节点的指针
	ChainNode<T> *last;
public:
	Chain(){ first = 0; }
	~Chain();
	bool isEmpty() const{ return first == 0; }
	int Length() const;
	bool Find(int k, T& x)const;
	int Search(const T& x)const;
	Chain<T>& Delete(int k, T& x);
	Chain<T>& Insert(int k, const T&x);
	void Output(std::ostream& out)const;
	// 删除链表中的所有节点
	void Erase();
	void Zero() { first = 0; }
	// 在链表末尾右端添加一个元素
	Chain<T> & Append(const T& x);
};

// 链表遍历器类
template<class T>
class ChainIterator{
private:
	ChainNode<T> *location;
public:
	T* Initialize(const Chain<T>& c){
		location = c.first;
		if (location)
			return &location->data;
		return 0;
	}
	T* Next(){
		if (!location)
			// 链表为空
			return 0;
		location = location->link;
		if (location)
			return &location->data;
		return 0;
	}
};

template<class T>
void Output(const Chain<T>& X){
	int *x;
	ChainIterator<T> c;
	x = c.Initialize(X);
	while (x){
		cout << *x << ' ';
		x = c.Next();
	}
	cout << endl;
}

template<class T>
Chain<T>::~Chain(){
	// 删除链表中的所有节点
	ChainNode<T> *next;
	while (first){
		next = first->link;
		delete first;
		first = next;
	}
}

template<class T>
int Chain<T>::Length() const{
	// 返回链表中的元素总数
	ChainNode<T> *current = first;
	int len = 0;
	while (current){
		len++;
		current = current->link;
	}
	return len;
}

template<class T>
bool Chain<T>::Find(int k, T&x)const{
	// 寻找链表中的第k个元素，并将其传送者x
	if (k < 1)
		return false;
	ChainNode<T> *current = first;
	// current的索引
	int index = 1;	
	while (index < k && current){
		current = current->link;
		index++;
	}
	if (current){
		x = current->data;
		return true;
	}
	// 不存在第k个元素
	return false;
}

template<class T>
int Chain<T>::Search(const T& x)const{
	// 寻找x，如果发现x，则返回x的位置
	ChainNode<T> *current = first;
	// current的索引
	int index = 1;
	while (current && current->data != x){
		index++;
		current = current->link;
	}
	if (current)
		return index;
	return 0;
}

template<class T>
void Chain<T>::Output(std::ostream& out)const{
	//  将链表元素送至输出流
	ChainNode<T> *current;
	for (current = first; current; current = current->link){
		out << current->data << " ";
	}
}

// 重载 <<
template<class T>
std::ostream& operator<<(std::ostream& out, const Chain<T>& x){
	x.Output(out);
	return out;
}

template<class T>
Chain<T>& Chain<T>::Delete(int k, T&x){
	// 把第k个元素取至x，然后删除第k个元素
	if (k < 1 || !first)
		// 不存在第k个元素
		throw OutOfBounds();
	// p最终指向第k个节点
	ChainNode<T> *p = first;
	if (k == 1)
		// p已经指向第k个元素
		first = first->link;
	else{
		// q用于移动到第k-1个节点
		ChainNode<T>*q = first;
		for (int index = 1; index < k - 1 && q; index++)
			q = q->link;
		if (!q || !q->link)
			// 不存在第k个元素
			throw OutOfBounds();
		// 存在第k个元素
		p = q->link;
		// 如果刚好是第k个节点是最后一个节点
		if (p == last)
			last = q;
		// 让上一个节点指向待删除节点后面的节点
		q->link = p->link;
	}
	// 保存第k个元素的值，然后释放节点
	x = p->data;
	delete p;
	return *this;
}

template<class T>
Chain<T>& Chain<T>::Insert(int k, const T& x){
	// 在第k个元素后面插入x
	if (k < 0)
		throw OutOfBounds();
	ChainNode<T> *p = first;
	for (int index = 1; index < k && p; index++)
		p = p->link;
	if (k>0 && !p)
		// 不存在第k个元素
		throw OutOfBounds();
	ChainNode<T> *newNode = new ChainNode<T>;
	newNode->data = x;
	if (k){
		newNode->link = p->link;
		p->link = newNode;
	}
	else{
		// k=0,即作为第一个元素插入
		newNode->link = first;
		first = newNode;
	}
	// 如果新插入的节点是最后一个节点
	if (!newNode->link)
		last = newNode;
	return *this;
}

// 删除链表中的所有节点
template<class T>
void Chain<T>::Erase(){
	ChainNode<T> *next;
	while (first){
		next = first->link;
		delete first;
		first = next;
	}
}

// 在链表末尾右端添加一个元素
template<class T>
Chain<T>& Chain<T>::Append(const T&x){
	ChainNode<T> *newNode;
	newNode = new ChainNode<T>;
	newNode->data = x;
	newNode->link = 0;
	if (first){
		// 链表非空
		last->link = newNode;
		last = newNode;
	}
	else{
		first = last = newNode;
	}
	return *this;
}

#endif