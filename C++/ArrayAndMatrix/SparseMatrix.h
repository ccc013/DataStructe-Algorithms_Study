#ifndef SPARSEMATRIX_H_
#define SPARSEMATRIX_H_
#include<iostream>

template<class T>
class Term{
public:
	int row, col;
	T value;
};

template<class T>
class SparseMatrix{
private:
	void Append(const Term<T>& t);
	int rows, cols;
	// ��0Ԫ�ص���Ŀ
	int terms;
	// �洢��0Ԫ�ص�����
	Term<T> *a;
	// ����a�Ĵ�С
	int MaxTerms;
public:
	SparseMatrix(int maxTerms = 0);
	~SparseMatrix(){ delete[] a; }
	void Transpose(SparseMatrix<T>& b)	const;
	void Add(const SparseMatrix<T> &b, SparseMatrix<T>&c)const;

	template<class T>
	friend std::ostream& operator<<(std::ostream&, const SparseMatrix<T>&);
	template<class T>
	friend std::istream& operator>>(std::istream&, SparseMatrix<T>&);
};

template<class T>
SparseMatrix<T>::SparseMatrix(int maxTerms){
	if (maxTerms < 1)
		throw BadInitializers();
	MaxTerms = maxTerms;
	a = new Term<T>[maxTerms];
	terms = rows = cols = 0;
}

// ����<<
template<class T>
std::ostream& operator<<(std::ostream& out, const SparseMatrix<T>& x){
	// ������������
	out << "rows = " << x.rows << " columns = " << x.rows << std::endl;
	out << "nonzeros terms = " << x.terms << std::endl;
	// �����0Ԫ�أ�ÿ��1��
	for (int i = 0; i < x.terms; i++)
		out << "a(" << x.a[i].row << ", " << x.a[i].col << ") = " << x.a[i].value << std::endl;
	return out;
}

// ����>>
template<class T>
std::istream& operator>>(std::istream& in, SparseMatrix<T>& x){
	// ������������
	std::cout << "Enter number of rows, columns, and terms\n";
	in >> x.rows >> x.cols >> x.terms;
	if (x.terms > x.MaxTerms)
		throw NoMem();
	// �������Ԫ��
	for (int i = 0; i < x.terms; i++){
		cout << "Enter row, column, and value of term " << (i + 1) << std::endl;
		in >> x.a[i].row >> x.a[i].col >> x.a[i].value;
	}
	return in;
}

template<class T>
void SparseMatrix<T>::Transpose(SparseMatrix<T>& b)const{
	// ��*this��ת�ý������b��
	// ��֤b���㹻�ռ�
	if (terms > b.MaxTerms)
		throw NoMem();
	// ����ת������
	b.cols = rows;
	b.rows = cols;
	b.terms = terms;
	// ��ʼ��
	int *ColSize, *RowNext;
	ColSize = new int[cols + 1];
	RowNext = new int[rows + 1];
	for (int i = 1; i <= cols; i++)
		ColSize[i] = 0;
	// ����*thisÿһ�еķ�0Ԫ������
	for (int i = 0; i < terms; i++)
		ColSize[a[i].col]++;
	// ����b��ÿһ�е���ʼ��
	RowNext[1] = 0;
	for (int i = 2; i <= cols; i++)
		RowNext[i] = RowNext[i - 1] + ColSize[i - 1];

	// ִ��ת�ò���
	for (int i = 0; i < terms; i++){
		// ��b�е�λ��
		int j = RowNext[a[i].col]++;
		b.a[j].row = a[i].col;
		b.a[j].col = a[i].row;
		b.a[j].value = a[i].value;
	}
}

template<class T>
void SparseMatrix<T>::Append(const Term<T>& t){
	// ��һ����0Ԫ��t��ӵ� *this֮��
	if (terms >= MaxTerms)
		throw NoMem();
	a[terms] = t;
	terms++;
}

template<class T>
void SparseMatrix<T>::Add(const SparseMatrix<T>& b, SparseMatrix<T>& c)const{
	// ���� c = (*this) + b
	// ��֤������
	if (rows != b.rows || cols != b.cols)
		throw SizeMismatch();
	// ���ý������c������
	c.rows = rows;
	c.cols = cols;
	c.terms = 0;
	// ����*this ��b ���α�
	int ct = 0, cb = 0;
	while (ct < terms && cb < b.terms){
		// ÿһ��Ԫ�ص���������
		int indt = a[ct].row * cols + a[ct].col;
		int indb = b.a[cb].row * cols + b.a[cb].col;
		if (indt < indb){
			// b��Ԫ���ں���
			c.Append(a[ct]);
			ct++;
		}
		else{
			if (indt == indb){
				// λ����ͬ
				if (a[ct].value + b.a[cb].value){
					// �����Ͳ�Ϊ0ʱ������ӵ�c��
					Term<T> t;
					t.row = a[ct].row;
					t.col = a[ct].col;
					t.value = a[ct].value + b.a[cb].value;
					c.Append(t);
				}
				ct++;
				cb++;
			}
			else{
				// b��Ԫ����ǰ��
				c.Append(b.a[cb]);
				cb++;
			}
		}
	}
	// ����ʣ��Ԫ��
	for (; ct < terms; ct++)
		c.Append(a[ct]);
	for (; cb < b.terms; cb++)
		c.Append(b.a[cb]);
}



#endif