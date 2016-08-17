#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include<iostream>
#include"LinkedQueue.h"
using std::cout;

template<class T>
class BinaryTree;

template<class T>
class BinaryTreeNode{
	friend BinaryTree<T>;
	friend void Visit(BinaryTreeNode<T> *);
	friend void InOrder(BinaryTreeNode<T> *);
	friend void PreOrder(BinaryTreeNode<T> *);
	friend void Infix(BinaryTreeNode<T>*);
	friend void PostOrder(BinaryTreeNode<T> *);
	friend void LevelOrder(BinaryTreeNode<T> *);
private:
	T data;
	BinaryTreeNode<T>* LeftChild, *RightChild;
public:
	BinaryTreeNode(){
		LeftChild = RightChild = 0;
	}
	BinaryTreeNode(const T& e){
		data = e;
		LeftChild = RightChild = 0;
	}
	BinaryTreeNode(const T&e, BinaryTreeNode *l, BinaryTreeNode* r){
		data = e;
		LeftChild = l;
		RightChild = r;
	}
};

template<class T>
void PreOrder(BinaryTreeNode<T>* t){
	if (t){
		// 访问根节点
		Visit(t);
		// 前序遍历左子树
		PreOrder(t->LeftChild);
		// 前序遍历右子树
		PreOrder(t->RightChild);
	}
}

template<class T>
void InOrder(BinaryTreeNode<T>* t){
	if (t){
		// 中序遍历左子树
		InOrder(t->LeftChild);
		Visit(t);
		InOrder(t->RightChild);
	}
}

template<class T>
void PostOrder(BinaryTreeNode<T>* t){
	if (t){
		// 后序遍历左子树
		PostOrder(t->LeftChild);
		PostOrder(t->RightChild);
		Visit(t);
	}
}

template<class T>
void Infix(BinaryTreeNode<T> *t){
	// 输出完全括号的中缀表达式
	if (t){
		cout << "(";
		// 左操作数
		Infix(t->LeftChild);
		// 操作符
		cout << t->data;
		// 右操作数
		Infix(t->RightChild);
		cout << ")";
	}
}

template<class T>
void LevelOrder(BinaryTreeNode<T>* t){
	// 对*t逐层遍历
	LinkedQueue<BinaryTreeNode<T>*>	 Q;
	while (t){
		Visit(t);
		// 将t的右孩子放入队列
		if (t->LeftChild)
			Q.Add(t->LeftChild);
		if (t->RightChild)
			Q.Add(t->RightChild);
		// 访问下一个节点
		try{
			Q.Delete(t);
		}
		catch (OutOfBounds){
			return;
		}
	}
}

/*类BinaryTree*/
template<class T>
class BinaryTree{
private:
	BinaryTreeNode<T> *root;	// 根节点指针
	void PreOrder(void(*Visit)(BinaryTreeNode<T>*u), BinaryTreeNode<T>* t);
	void Inorder(void(*Visit)(BinaryTreeNode<T>*u), BinaryTreeNode<T>* t);
	void PostOrder(void(*Visit)(BinaryTreeNode<T>*u), BinaryTreeNode<T>* t);
public:
	BinaryTree(){ root = 0; }
	~BinaryTree(){};
	bool IsEmpty() const{
		return ((root) ? false : true);
	}
	bool Root(T& x)const;
	void MakeTree(const T& element, BinaryTree<T>& left, BinaryTree<T>& right);
	void BreakTree(T& element, BinaryTree<T>& left, BinaryTree<T>& right);
	void PreOrder(void(*Visit)(BinaryTreeNode<T>*u)){
		PreOrder(Visit, root);
	}
	void Inorder(void(*Visit)(BinaryTreeNode<T>*u)){
		Inorder(Visit, root);
	}
	void PostOrder(void(*Visit)(BinaryTreeNode<T>*u)){
		PostOrder(Visit, root);
	}
	void LevelOrder(void(*Visit)(BinaryTreeNode<T>*u));

};

template<class T>
bool BinaryTree<T>::Root(T& x)const{
	// 取根节点的data域，放入x，如果没有则返回false
	if (root){
		x = root->data;
		return true;
	}
else
	return false;
}

template<class T>
void BinaryTree<T>::MakeTree(const T& element, BinaryTree<T>& left, BinaryTree<T>& right){
	// 将left，right和element合并成一棵新树，并且要求left和right及this必须是不同的树。

	// 创建新树
	root = new BinaryTreeNode<T>(element, left.root, right.root);

	// 阻止访问left和right
	left.root = right.root = 0;
}

template<class T>
void BinaryTree<T>::BreakTree(T& element, BinaryTree<T>& left, BinaryTree<T>& right){
	// left,right 和this必须是不同的树
	if (!root)
		// 空树
		throw BadInput();

	// 分解树
	element = root->data;
	left.root = root->LeftChild;
	right.root = root->RightChild;

	delete root;
	root = 0;
}

template<class T>
void BinaryTree<T>::PreOrder(void(*Visit)(BinaryTreeNode<T>*u), BinaryTreeNode<T>* t){
	// 前序遍历
	if (t){
		Visit(t);
		PreOrder(Visit, t->LeftChild);
		PreOrder(Visit, t->RightChild);
	}
}

template<class T>
void BinaryTree<T>::Inorder(void(*Visit)(BinaryTreeNode<T>*u), BinaryTreeNode<T>* t){
	// 中序遍历
	if (t){
		Inorder(Visit, t->LeftChild);
		Visit(t);
		Inorder(Visit, t->RightChild);
	}
}

template<class T>
void BinaryTree<T>::PostOrder(void(*Visit)(BinaryTreeNode<T>*u), BinaryTreeNode<T>* t){
	// 后序遍历
	if (t){
		PostOrder(Visit, t->LeftChild);
		PostOrder(Visit, t->RightChild);
		Visit(t);
	}
}

template<class T>
void BinaryTree<T>::LevelOrder(void(*Visit)(BinaryTreeNode<T>* u)){
	// 逐层遍历
	LinkedQueue<BinaryTreeNode<T>*>Q;
	BinaryTreeNode<T> *t;
	t = root;
	while (t){
		Visit(t);
		// 将t的右孩子放入队列
		if (t->LeftChild)
			Q.Add(t->LeftChild);
		if (t->RightChild)
			Q.Add(t->RightChild);
		// 访问下一个节点
		try{
			Q.Delete(t);
		}
		catch (OutOfBounds){
			return;
		}
	}
}

#endif