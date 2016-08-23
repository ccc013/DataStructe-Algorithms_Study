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
		// 后序遍历
		if (t){
			PostOrder(Visit, t->LeftChild);
			PostOrder(Visit, t->RightChild);
			Visit(t);
		}
	}
	void PreOrder(void(*Visit)(HBLTNode<T>*u), HBLTNode<T>* t){
		// 前序遍历
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
	// 合并两棵根分别是*x和*y的左高树，返回指向新根 x的指针
	if (!y)
		return;
	if (!x){
		x = y;
		return;
	}
	if (x->data < y->data){
		// 交换x和y
		HBLTNode<T> * temp = y;
		y = x;
		x = temp;
	}
	Meld(x->RightChild, y);
	if (!x->LeftChild){
		// 左子树为空,交换子树
		x->LeftChild = x->RightChild;
		x->RightChild = 0;
		x->s = 1;
	}
	else{
		if (x->LeftChild->s < x->RightChild->s){
			// 交换左右子树
			HBLTNode<T> * temp = x->RightChild;
			x->RightChild = x->LeftChild;
			x->LeftChild = temp;
		}
		x->s = x->RightChild->s + 1;
	}
}

template<class T>
MaxHBLT<T>& MaxHBLT<T>::Insert(const T& x){
	// 将x插入左高树
	HBLTNode<T>* q = new HBLTNode<T>(x, 1);
	// 将q与原树合并
	Meld(root, q);
	return *this;
}

template<class T>
MaxHBLT<T>& MaxHBLT<T>::DeleteMax(T& x){
	// 删除最大元素，并将其放入x
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
	// 初始化有n个元素的HBLT树
	Queue<HBLTNode<T>*>Q(n);
	// 删除老节点
	Free(root);
	for (int i = 1; i <= n; i++){
		HBLTNode<T>* q = new HBLTNode<T>(a[i-1], 1);
		Q.Add(q);
	}

	// 不断合并队列中的树；
	HBLTNode<T>*b, *c;
	for (int i = 1; i <= n - 1; i++) {
		Q.Delete(b).Delete(c);
		Meld(b, c);
		// 将合并后得到的树放入对了
		Q.Add(b);
	}

	if (n)
		Q.Delete(root);
}

#endif