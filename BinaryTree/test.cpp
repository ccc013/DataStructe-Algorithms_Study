#include<iostream>
#include"xcept.h"
#include"BinaryTree.h"

using std::cout;
using std::endl;
using std::cin;

int count = 0;
BinaryTree<int>a, x, y, z;

template<class T>
void ct(BinaryTreeNode<T>* t){
	count++;
}


void main(void){
	y.MakeTree(1, a, a);
	z.MakeTree(2, a, a);
	x.MakeTree(3, y, z);
	y.MakeTree(4, x, a);
	y.PreOrder(ct);
	cout <<"Tree y has "<< count <<" nodes"<< endl;

	system("pause");
	return;
}

