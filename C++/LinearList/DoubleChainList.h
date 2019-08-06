#ifndef DOUBLECHAINLIST_H_
#define DOUBLECHAINLIST_H_
#include<iostream>

template<class T>
class DoubleNode{
	T data;
	DoubleNode<T>*left, *right;
};

template<class T>
class DoubleChainList{
private:
	DoubleNode<T>* LeftEnd, *RightEnd;
public:
	DoubleChainList(){ LeftEnd = RightEnd = 0 };
	~DoubleChainList();
	int Length() const;
	bool Find(int k, T& x)const;
	int Search(const T& x)const;
	DoubleChainList<T>& Delete(int k, T& x);
	DoubleChainList<T>& Insert(int k, const T& x);
	void Output(std::ostream & out)const;
};

#endif