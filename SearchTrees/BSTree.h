#ifndef BSTREE_H_
#define BSTREE_H_
#include"BinaryTree.h"

template<class E,class K>
class BSTree : public BinaryTree<E>{
public:
	bool Search(const K&k, E& e) const;
	BSTree<E, K>& Insert(const E& e);
	BSTree<E, K>& Delete(const K&k, E& e);
	void Ascend(){ InOutput(); }
};

template<class E,class K>
bool BSTree<E, K>::Search(const K&k, E &e) const{
	// 搜索与k匹配的元素
	BinaryTreeNode<E> *p = root;
	while (p){
		if (k < p->data)
			p = p->LeftChild;
		else if (k>p->data)
			p = p->RightChild;
		else{
			// 找到元素
			e = p->data;
			return true;
		}
	}
	return false;
}

template<class E, class K>
BSTree<E, K>& BSTree<E, K>::Insert(const E& e){
	// 如果不出现重复，则插入e
	BinaryTreeNode<E> *p = root, *pp = 0;	// p是搜索节点，pp是p的父节点
	// 寻找插入点
	while (p){
		pp = p;
		if (e < p->data)
			p = p->LeftChild;
		else if (e>p->data)
			p = p->RightChild;
		else{
			// 出现重复
			std::cerr << e << " has exists in tree!\n";
			return *this;
		}
	}

	BinaryTreeNode<E> *r = new BinaryTreeNode<E>(e);
	if (root){
		if (e < pp->data)
			pp->LeftChild = r;
		else
			pp->RightChild = r;
	}
	else
		root = r;

	return *this;
}

template<class E,class K>
BSTree<E, K>& BSTree<E, K>::Delete(const K& k, E& e){
	// 删除关键值是k的元素，并将其放入e

	// 将p指向关键值是k的节点
	BinaryTreeNode<E> *p = root, *pp = 0;

	while (p && p->data != k){
		pp = p;
		if (k < p->data)
			p = p->LeftChild;
		else
			p = p->RightChild;
	}
	if (!p)
		throw BadInput();

	e = p->data;
	// 对树进行重构，处理p有两个孩子的情形
	if (p->LeftChild && p->RightChild){
		// 转换成有0或1个孩子的情形，在p的左子树中寻找最大元素
		BinaryTreeNode<E> *s = p->LeftChild, *ps = p;
		while (s->RightChild){
			ps = s;
			s = s->RightChild;
		}

		// 将最大元素从s移动到p
		p->data = s->data;
		p = s;
		pp = ps;
	}

	// 对于p最多有一个孩子
	BinaryTreeNode<E> *c;
	if (p->LeftChild)
		c = p->LeftChild;
	else
		c = p->RightChild;

	// 删除p
	if (p == root)
		root = c;
	else{
		if (p == pp->LeftChild)
			pp->LeftChild = c;
		else
			pp->RightChild = c;
	}
	delete p;

	return *this;
}


#endif