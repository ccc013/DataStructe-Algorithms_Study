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
	count = y.Size();
	cout <<"Tree y has "<< count <<" nodes"<< endl;
	cout << "前序输出：";
	y.PreOutput();
	cout << "中序输出：";
	y.InOutput();
	cout << "后序输出：";
	y.PostOutput();
	cout << "逐层输出：";
	y.LevelOutput();

	// 计算高度
	cout << "Tree y's height = " << y.Height() << endl;

	cout << "Tree y is Empty? ";
	if (!y.IsEmpty())
		cout << "false\n";
	else
		cout << "true\n";
	// 删除树y
	cout << "Delete Tree y\n";
	y.Delete();
	cout << "Tree y is Empty? ";
	if (!y.IsEmpty())
		cout << "false\n";
	else
		cout << "true\n";

	system("pause");
	return;
}

