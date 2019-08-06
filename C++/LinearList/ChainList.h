#ifndef CHAIN_H_
#define CHAIN_H_
#include<iostream>
// ������������������Ԫģ����֮���޷�ֱ�ӷ��ʣ������δ����Ĵ���
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
	// ָ���һ���ڵ��ָ��
	ChainNode<T> *first;
	// ָ�����һ���ڵ��ָ��
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
	// ɾ�������е����нڵ�
	void Erase();
	void Zero() { first = 0; }
	// ������ĩβ�Ҷ����һ��Ԫ��
	Chain<T> & Append(const T& x);
	// ��������
	void BinSort(int range, int(*value)(T& x));
};

// �����������
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
			// ����Ϊ��
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
	// ɾ�������е����нڵ�
	ChainNode<T> *next;
	while (first){
		next = first->link;
		delete first;
		first = next;
	}
}

template<class T>
int Chain<T>::Length() const{
	// ���������е�Ԫ������
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
	// Ѱ�������еĵ�k��Ԫ�أ������䴫����x
	if (k < 1)
		return false;
	ChainNode<T> *current = first;
	// current������
	int index = 1;	
	while (index < k && current){
		current = current->link;
		index++;
	}
	if (current){
		x = current->data;
		return true;
	}
	// �����ڵ�k��Ԫ��
	return false;
}

template<class T>
int Chain<T>::Search(const T& x)const{
	// Ѱ��x���������x���򷵻�x��λ��
	ChainNode<T> *current = first;
	// current������
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
	//  ������Ԫ�����������
	ChainNode<T> *current;
	for (current = first; current; current = current->link){
		out << current->data << " ";
	}
}

// ���� <<
template<class T>
std::ostream& operator<<(std::ostream& out, const Chain<T>& x){
	x.Output(out);
	return out;
}

template<class T>
Chain<T>& Chain<T>::Delete(int k, T&x){
	// �ѵ�k��Ԫ��ȡ��x��Ȼ��ɾ����k��Ԫ��
	if (k < 1 || !first)
		// �����ڵ�k��Ԫ��
		throw OutOfBounds();
	// p����ָ���k���ڵ�
	ChainNode<T> *p = first;
	if (k == 1)
		// p�Ѿ�ָ���k��Ԫ��
		first = first->link;
	else{
		// q�����ƶ�����k-1���ڵ�
		ChainNode<T>*q = first;
		for (int index = 1; index < k - 1 && q; index++)
			q = q->link;
		if (!q || !q->link)
			// �����ڵ�k��Ԫ��
			throw OutOfBounds();
		// ���ڵ�k��Ԫ��
		p = q->link;
		// ����պ��ǵ�k���ڵ������һ���ڵ�
		if (p == last)
			last = q;
		// ����һ���ڵ�ָ���ɾ���ڵ����Ľڵ�
		q->link = p->link;
	}
	// �����k��Ԫ�ص�ֵ��Ȼ���ͷŽڵ�
	x = p->data;
	delete p;
	return *this;
}

template<class T>
Chain<T>& Chain<T>::Insert(int k, const T& x){
	// �ڵ�k��Ԫ�غ������x
	if (k < 0)
		throw OutOfBounds();
	ChainNode<T> *p = first;
	for (int index = 1; index < k && p; index++)
		p = p->link;
	if (k>0 && !p)
		// �����ڵ�k��Ԫ��
		throw OutOfBounds();
	ChainNode<T> *newNode = new ChainNode<T>;
	newNode->data = x;
	if (k){
		newNode->link = p->link;
		p->link = newNode;
	}
	else{
		// k=0,����Ϊ��һ��Ԫ�ز���
		newNode->link = first;
		first = newNode;
	}
	// ����²���Ľڵ������һ���ڵ�
	if (!newNode->link)
		last = newNode;
	return *this;
}

// ɾ�������е����нڵ�
template<class T>
void Chain<T>::Erase(){
	ChainNode<T> *next;
	while (first){
		next = first->link;
		delete first;
		first = next;
	}
}

// ������ĩβ�Ҷ����һ��Ԫ��
template<class T>
Chain<T>& Chain<T>::Append(const T&x){
	ChainNode<T> *newNode;
	newNode = new ChainNode<T>;
	newNode->data = x;
	newNode->link = 0;
	if (first){
		// ����ǿ�
		last->link = newNode;
		last = newNode;
	}
	else{
		first = last = newNode;
	}
	return *this;
}

template<class T>
void Chain<T>::BinSort(int range,int (*value)(T& x)){
	// ����������
	int b;	
	ChainNode<T> **bottom, **top;
	// ���ӳ�ʼ��
	bottom = new ChainNode<T> *[range + 1];
	top = new ChainNode<T> *[range + 1];
	for (b = 0; b <= range; b++)
		bottom[b] = 0;
	// �ѽڵ���䵽���������У�
	for (; first; first = first->link){
		b =value( first->data);
		if (bottom[b]){
			// ���ӷǿ�
			top[b]->link = first;
			top[b] = first;
		}
		else{
			bottom[b] = top[b] = first;
		}
	}
	// �ռ��������е�Ԫ�أ�����һ����������
	ChainNode<T>*y = 0;
	for (b = 0; b <= range; b++){
		if (bottom[b]){
			// ���ӷǿ�
			if (y){
				// ���ǵ�һ���ǿյ�����
				y->link = bottom[b];
			}
			else{
				// ��һ���ǿյ�����
				first = bottom[b];
			}
			y = top[b];
		}
	}
	if (y)
		y->link = 0;
	delete[] bottom;
	delete[] top;
}

#endif