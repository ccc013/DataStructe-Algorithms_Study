#ifndef MAXHBLT_H_
#define MAXHBLT_H_
#include<iostream>
#include"Queue.h"

template<class T>
class MaxHBLT;

template<class T>
class HBLTNode{
	friend MaxHBLT<T>;
private:
	int s;
	T data;
	HBLTNode<T>* LeftChild, *RightChild;
public:
	HBLTNode(const T&e, const int sh){
		data = e;
		s = sh;
		LeftChild = RightChild = 0;
	}
};


template<class T>
class MaxHBLT{
private:
	HBLTNode<T> *root;
	void PostOrder(void(*Visit)(HBLTNode<T>*u), HBLTNode<T>* t){
		// �������
		if (t){
			PostOrder(Visit, t->LeftChild);
			PostOrder(Visit, t->RightChild);
			Visit(t);
		}
	}
	void PreOrder(void(*Visit)(HBLTNode<T>*u), HBLTNode<T>* t){
		// ǰ�����
		if (t){
			Visit(t);
			PreOrder(Visit, t->LeftChild);
			PreOrder(Visit, t->RightChild);
		}
	}
	static void Output(HBLTNode<T>*t){
		cout << t->data << ", ";
	}
	static void free(HBLTNode<T>* t){
		delete t;
	}
	void Free(HBLTNode<T> *t){
		PostOrder(free, t);
		t = 0;
	}
	void Meld(HBLTNode<T> * &x, HBLTNode<T>* y);
public:
	MaxHBLT(){ root = 0; }
	~MaxHBLT(){ Free(root); }
	T Max(){
		if (!root)
			throw OutOfBounds();
		return root->data;
	}
	MaxHBLT<T>& Insert(const T& x);
	MaxHBLT<T>& DeleteMax(T& x);
	MaxHBLT<T>& Meld(MaxHBLT<T>& x){
		Meld(root, x.root);
		x.root = 0;
		return *this;
	}
	void Initialize(T a[], int n);
	void PreOut(){
		std::cout << "PreOutput:\n";
		PreOrder(Output, root);
		std::cout << "\n";
	}
};

template<class T>
void MaxHBLT<T>::Meld(HBLTNode<T>* &x, HBLTNode<T>* y){
	// �ϲ����ø��ֱ���*x��*y�������������ָ���¸� x��ָ��
	if (!y)
		return;
	if (!x){
		x = y;
		return;
	}
	if (x->data < y->data){
		// ����x��y
		HBLTNode<T> * temp = y;
		y = x;
		x = temp;
	}
	Meld(x->RightChild, y);
	if (!x->LeftChild){
		// ������Ϊ��,��������
		x->LeftChild = x->RightChild;
		x->RightChild = 0;
		x->s = 1;
	}
	else{
		if (x->LeftChild->s < x->RightChild->s){
			// ������������
			HBLTNode<T> * temp = x->RightChild;
			x->RightChild = x->LeftChild;
			x->LeftChild = temp;
		}
		x->s = x->RightChild->s + 1;
	}
}

template<class T>
MaxHBLT<T>& MaxHBLT<T>::Insert(const T& x){
	// ��x���������
	HBLTNode<T>* q = new HBLTNode<T>(x, 1);
	// ��q��ԭ���ϲ�
	Meld(root, q);
	return *this;
}

template<class T>
MaxHBLT<T>& MaxHBLT<T>::DeleteMax(T& x){
	// ɾ�����Ԫ�أ����������x
	if (!root)
		throw OutOfBounds();

	x = root->data;
	HBLTNode<T>*L = root->LeftChild;
	HBLTNode<T>*R = root->RightChild;
	delete root;
	root = L;
	Meld(root, R);
	return *this;
}

template<class T>
void MaxHBLT<T>::Initialize(T a[], int n){
	// ��ʼ����n��Ԫ�ص�HBLT��
	Queue<HBLTNode<T>*>Q(n);
	// ɾ���Ͻڵ�
	Free(root);
	for (int i = 1; i <= n; i++){
		HBLTNode<T>* q = new HBLTNode<T>(a[i-1], 1);
		Q.Add(q);
	}

	// ���Ϻϲ������е�����
	HBLTNode<T>*b, *c;
	for (int i = 1; i <= n - 1; i++) {
		Q.Delete(b).Delete(c);
		Meld(b, c);
		// ���ϲ���õ������������
		Q.Add(b);
	}

	if (n)
		Q.Delete(root);
}

#endif