#ifndef CIRCULARLIST_H_
#define CIRCULARLIST_H_
#include<iostream>


template<class T>
class CircularList{
private:
	// ָ���һ���ڵ��ָ��
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
	// ����ͷ�ڵ�Ŀյ�ѭ������
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
	// ���������е�Ԫ������
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
	// Ѱ�������еĵ�k��Ԫ�أ������䴫����x
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
	// �ڴ���ͷ�ڵ��ѭ�������в���x
	ChainNode<T>* current = first->link;
	int index = 1;
	first->data = x;	// ��x����ͷ�ڵ�
	while (current->data != x){
		current = current->link;
		index++;
	}
	// �ж��Ƿ�������ͷ�ڵ�
	return ((current == first) ? 0 : index);
}

template<class T>
void CircularList<T>::Output(std::ostream& out)const{
	//  ������Ԫ�����������
	ChainNode<T> *current;
	for (current = first->link; current != first; current = current->link){
		out << current->data << " ";
	}
}

// ���� <<
template<class T>
std::ostream& operator<<(std::ostream& out, const CircularList<T>& x){
	x.Output(out);
	return out;
}

template<class T>
CircularList<T>& CircularList<T>::Insert(int k, const T& x){
	// �ڵ�k��Ԫ�غ������x
	if (k < 0)
		throw OutOfBounds();
	ChainNode<T>* current = first->link;
	for (int index = 1; index < k && current != first; index++)
		current = current->link;
	if (k>0 && current == first)
		// �����ڵ�k��Ԫ��
		throw OutOfBounds();
	ChainNode<T>* newNode = new ChainNode<T>;
	newNode->data = x;
	if (k){
		newNode->link = current->link;
		current->link = newNode;
	}
	else{
		// k=0����Ϊ��һ��Ԫ�ز���
		newNode->link = first->link;
		first->link = newNode;
	}

	return *this;
}

template<class T>
CircularList<T>& CircularList<T>::Delete(int k, T&x){
	// �ѵ�k��Ԫ��ȡ��x��Ȼ��ɾ����k��Ԫ��
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
			// �����ڵ�k��Ԫ��
			throw OutOfBounds();
		// ���ڵ�k��Ԫ��
		current = q->link;
		q->link = current->link;
	}
	x = current->data;
	delete current;
	return *this;
}


#endif