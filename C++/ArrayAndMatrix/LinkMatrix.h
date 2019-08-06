#ifndef LINKMATRIX_H_
#define LINKMATRIX_H_
#include<iostream>
#include"ChainList.h"

template<class T>
class CNode{
public:
	int col;
	T value;

	int operator!=(const CNode<T>& y){
		return (value != y.value);
	}
	void Output(std::ostream& out)const{
		out << "column = " << col << ", value= " << value;
	}
};

template<class T>
std::ostream& operator<<(std::ostream& out, const CNode<T>& x){
	x.Output(out);
	out << std::endl;
	return out;
}

template<class T>
class HeadNode{
public:
	int row;
	// 行链表
	Chain<CNode<T>> a;
	int operator!=(const HeadNode<T>& y){
		return (row != y.row);
	}
	void Output(std::ostream& out)const{
		out << "row = " << row;
	}
};
template<class T>
std::ostream& operator<<(std::ostream& out, const HeadNode<T>& x){
	x.Output(out);
	out << std::endl;
	return out;
}

template<class T>
class LinkMatrix{
private:
	int rows, cols;
	// 头节点链表
	Chain<HeadNode<T>> a;
public:
	LinkMatrix(){}
	~LinkMatrix(){}
	void Transpose(LinkMatrix<T>& b)const;
	void Add(const LinkMatrix<T>& b, LinkMatrix<T>& c)const;
	template<class T>
	friend std::ostream& operator<<(std::ostream&, const LinkMatrix<T>&);
	template<class T>
	friend std::istream& operator>>(std::istream&, LinkMatrix<T>&);
};

template<class T>
std::istream& operator>>(std::istream& in, LinkMatrix<T>& x){
	// 从输入流中输入矩阵x
	// 删除x中所有节点
	x.a.Erase();
	// 获取矩阵特征
	int terms;	// 输入的元素数
	cout << "Enter numbers of rows, columns, and terms\n";
	in >> x.rows >> x.cols >> terms;
	// 虚设第0行
	HeadNode<T> H;	// 当前行的头节点
	H.row = 0;				// 当前行号
	// 输入x的非0元素
	for (int i = 1; i <= terms; i++){
		// 输入下一个元素
		cout << "Enter row, column, and value of term " << i << std::endl;
		int row, col;
		T value;
		in >> row >> col >> value;
		// 检查新元素是否属于当前行
		if (row > H.row){
			// 如果不是第0行，则把当前行的头节点H 添加到头节点链表x.a之中
			if (H.row)
				x.a.Append(H);
			// 为新的一行准备H
			H.row = row;
			// 置链表头指针first=0
			H.a.Zero(); 
		}
		// 添加新元素
		CNode<T> *c = new CNode<T>;
		c->col = col;
		c->value = value;
		H.a.Append(*c);
	}
	// 注意矩阵的最后一行
	if (H.row)
		x.a.Append(H);
	H.a.Zero();
	return in;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const LinkMatrix<T>& x){
	// 把矩阵x送至输出流
	ChainIterator<HeadNode<T>> p;	// 头节点遍历器
	// 输出矩阵的维数
	out << "rows = " << x.rows << ",columns = " << x.cols << std::endl;
	// 将h指向第一个头节点
	HeadNode<T> *h = p.Initialize(x.a);
	if (!h){
		out << "No non-zero terms\n";
		return out;
	}
	// 每次输出一行
	while (h){
		out << "row = " << h->row << std::endl;
		out << h->a << "\n";		// 输出行链表；
		// 下一个头节点
		h = p.Next();
	}
	return out;
}

template<class T>
void LinkMatrix<T>::Transpose(LinkMatrix<T>& b)const{
	// 转置 *this，并把结果放入b
	b.a.Erase();
	// 创建用来收集b中各行元素的箱子
	Chain<CNode<T>> *bin;
	bin = new Chain<CNode<T>>[cols + 1];
	// 头节点遍历器
	ChainIterator<HeadNode<T>> p;
	// h 指向*this的第一个头节点
	HeadNode<T> *h = p.Initialize(a);
	// 把*this的元素复制到箱子中
	while (h){
		int r = h->row;
		// 行链表遍历器
		ChainIterator<CNode<T>> q;
		// 将z指向行链表的第一个节点
		CNode<T> *z = q.Initialize(h->a);
		// 临时节点
		CNode<T> x;
		// *this第r行中的元素变成b中第r列的元素
		x.col = r;
		// 检查*this第r行的所有非0元素
		while (z){
			x.value = z->value;
			bin[z->col].Append(x);
			z = q.Next();
		}
		h = p.Next();
	}
	// 设置b的维数
	b.rows = cols;
	b.cols = rows;
	// 装配b的头节点链表
	HeadNode<T> H;
	// 搜索箱子
	for (int i = 1; i <= cols; i++){
		if (!bin[i].isEmpty()){
			// 转置矩阵的第i行
			H.row = i;
			H.a = bin[i];
			b.a.Append(H);
			bin[i].Zero();
		}
	}
	H.a.Zero();
	delete[] bin;
}

#endif