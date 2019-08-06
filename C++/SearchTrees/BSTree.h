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
	// ������kƥ���Ԫ��
	BinaryTreeNode<E> *p = root;
	while (p){
		if (k < p->data)
			p = p->LeftChild;
		else if (k>p->data)
			p = p->RightChild;
		else{
			// �ҵ�Ԫ��
			e = p->data;
			return true;
		}
	}
	return false;
}

template<class E, class K>
BSTree<E, K>& BSTree<E, K>::Insert(const E& e){
	// ����������ظ��������e
	BinaryTreeNode<E> *p = root, *pp = 0;	// p�������ڵ㣬pp��p�ĸ��ڵ�
	// Ѱ�Ҳ����
	while (p){
		pp = p;
		if (e < p->data)
			p = p->LeftChild;
		else if (e>p->data)
			p = p->RightChild;
		else{
			// �����ظ�
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
	// ɾ���ؼ�ֵ��k��Ԫ�أ����������e

	// ��pָ��ؼ�ֵ��k�Ľڵ�
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
	// ���������ع�������p���������ӵ�����
	if (p->LeftChild && p->RightChild){
		// ת������0��1�����ӵ����Σ���p����������Ѱ�����Ԫ��
		BinaryTreeNode<E> *s = p->LeftChild, *ps = p;
		while (s->RightChild){
			ps = s;
			s = s->RightChild;
		}

		// �����Ԫ�ش�s�ƶ���p
		p->data = s->data;
		p = s;
		pp = ps;
	}

	// ����p�����һ������
	BinaryTreeNode<E> *c;
	if (p->LeftChild)
		c = p->LeftChild;
	else
		c = p->RightChild;

	// ɾ��p
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