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
	// ������
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
	// ͷ�ڵ�����
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
	// �����������������x
	// ɾ��x�����нڵ�
	x.a.Erase();
	// ��ȡ��������
	int terms;	// �����Ԫ����
	cout << "Enter numbers of rows, columns, and terms\n";
	in >> x.rows >> x.cols >> terms;
	// �����0��
	HeadNode<T> H;	// ��ǰ�е�ͷ�ڵ�
	H.row = 0;				// ��ǰ�к�
	// ����x�ķ�0Ԫ��
	for (int i = 1; i <= terms; i++){
		// ������һ��Ԫ��
		cout << "Enter row, column, and value of term " << i << std::endl;
		int row, col;
		T value;
		in >> row >> col >> value;
		// �����Ԫ���Ƿ����ڵ�ǰ��
		if (row > H.row){
			// ������ǵ�0�У���ѵ�ǰ�е�ͷ�ڵ�H ��ӵ�ͷ�ڵ�����x.a֮��
			if (H.row)
				x.a.Append(H);
			// Ϊ�µ�һ��׼��H
			H.row = row;
			// ������ͷָ��first=0
			H.a.Zero(); 
		}
		// �����Ԫ��
		CNode<T> *c = new CNode<T>;
		c->col = col;
		c->value = value;
		H.a.Append(*c);
	}
	// ע���������һ��
	if (H.row)
		x.a.Append(H);
	H.a.Zero();
	return in;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const LinkMatrix<T>& x){
	// �Ѿ���x���������
	ChainIterator<HeadNode<T>> p;	// ͷ�ڵ������
	// ��������ά��
	out << "rows = " << x.rows << ",columns = " << x.cols << std::endl;
	// ��hָ���һ��ͷ�ڵ�
	HeadNode<T> *h = p.Initialize(x.a);
	if (!h){
		out << "No non-zero terms\n";
		return out;
	}
	// ÿ�����һ��
	while (h){
		out << "row = " << h->row << std::endl;
		out << h->a << "\n";		// ���������
		// ��һ��ͷ�ڵ�
		h = p.Next();
	}
	return out;
}

template<class T>
void LinkMatrix<T>::Transpose(LinkMatrix<T>& b)const{
	// ת�� *this�����ѽ������b
	b.a.Erase();
	// ���������ռ�b�и���Ԫ�ص�����
	Chain<CNode<T>> *bin;
	bin = new Chain<CNode<T>>[cols + 1];
	// ͷ�ڵ������
	ChainIterator<HeadNode<T>> p;
	// h ָ��*this�ĵ�һ��ͷ�ڵ�
	HeadNode<T> *h = p.Initialize(a);
	// ��*this��Ԫ�ظ��Ƶ�������
	while (h){
		int r = h->row;
		// �����������
		ChainIterator<CNode<T>> q;
		// ��zָ��������ĵ�һ���ڵ�
		CNode<T> *z = q.Initialize(h->a);
		// ��ʱ�ڵ�
		CNode<T> x;
		// *this��r���е�Ԫ�ر��b�е�r�е�Ԫ��
		x.col = r;
		// ���*this��r�е����з�0Ԫ��
		while (z){
			x.value = z->value;
			bin[z->col].Append(x);
			z = q.Next();
		}
		h = p.Next();
	}
	// ����b��ά��
	b.rows = cols;
	b.cols = rows;
	// װ��b��ͷ�ڵ�����
	HeadNode<T> H;
	// ��������
	for (int i = 1; i <= cols; i++){
		if (!bin[i].isEmpty()){
			// ת�þ���ĵ�i��
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