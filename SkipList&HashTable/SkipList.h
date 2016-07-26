#ifndef SKIPLIST_H_
#define SKIPLIST_H_
#include<iostream>

template<class E, class K>
class SkipList;

template<class E, class K>
class SkipNode{
	friend SkipList<E, K>;
private:
	SkipNode(int size){
		link = new SkipNode<E, K>*[size];
	}
	~SkipNode() { delete[] link; }
	K key;
	E data;
	// 一维指针数组
	SkipNode<E, k> **link;
};

template<class E,class K>
class SkipList{
private:
	int Level();
	SkipNode<E, K>* SaveSearch(const K& k);
	// 所允许的最大级数
	int MaxLevel;
	// 当前非空链的个数
	int Levels;
	// 用于确定级号
	int CutOff;
	// 一个很大的key值
	K TailKey;
	// 头节点指针
	SkipNode<E, K>* head;
	// 尾节点指针
	SkipNode<E, K>* tail;
	// 指针数组
	SkipNode<E, K>** last;

public:
	SkipList(K Large, int MaxE = 10000, float p = 0.5);
	~SkipList();
	bool Search(const K&k, E&e)const;
	SkipList<E, K>& Insert(const E& e);
	SkipList<E, K>& Delete(const K&k, E&e);
};



#endif