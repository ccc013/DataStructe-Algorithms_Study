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
	// 非0元素的数目
	int terms;
	// 存储非0元素的数组
	Term<T> *a;
	// 数组a的大小
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

// 重载<<
template<class T>
std::ostream& operator<<(std::ostream& out, const SparseMatrix<T>& x){
	// 输出矩阵的特征
	out << "rows = " << x.rows << " columns = " << x.rows << std::endl;
	out << "nonzeros terms = " << x.terms << std::endl;
	// 输出非0元素，每行1个
	for (int i = 0; i < x.terms; i++)
		out << "a(" << x.a[i].row << ", " << x.a[i].col << ") = " << x.a[i].value << std::endl;
	return out;
}

// 重载>>
template<class T>
std::istream& operator>>(std::istream& in, SparseMatrix<T>& x){
	// 输入矩阵的特征
	std::cout << "Enter number of rows, columns, and terms\n";
	in >> x.rows >> x.cols >> x.terms;
	if (x.terms > x.MaxTerms)
		throw NoMem();
	// 输入矩阵元素
	for (int i = 0; i < x.terms; i++){
		cout << "Enter row, column, and value of term " << (i + 1) << std::endl;
		in >> x.a[i].row >> x.a[i].col >> x.a[i].value;
	}
	return in;
}

template<class T>
void SparseMatrix<T>::Transpose(SparseMatrix<T>& b)const{
	// 把*this的转置结果送入b中
	// 验证b有足够空间
	if (terms > b.MaxTerms)
		throw NoMem();
	// 设置转置特征
	b.cols = rows;
	b.rows = cols;
	b.terms = terms;
	// 初始化
	int *ColSize, *RowNext;
	ColSize = new int[cols + 1];
	RowNext = new int[rows + 1];
	for (int i = 1; i <= cols; i++)
		ColSize[i] = 0;
	// 计算*this每一列的非0元素数量
	for (int i = 0; i < terms; i++)
		ColSize[a[i].col]++;
	// 给出b中每一行的起始点
	RowNext[1] = 0;
	for (int i = 2; i <= cols; i++)
		RowNext[i] = RowNext[i - 1] + ColSize[i - 1];

	// 执行转置操作
	for (int i = 0; i < terms; i++){
		// 在b中的位置
		int j = RowNext[a[i].col]++;
		b.a[j].row = a[i].col;
		b.a[j].col = a[i].row;
		b.a[j].value = a[i].value;
	}
}

template<class T>
void SparseMatrix<T>::Append(const Term<T>& t){
	// 把一个非0元素t添加到 *this之中
	if (terms >= MaxTerms)
		throw NoMem();
	a[terms] = t;
	terms++;
}

template<class T>
void SparseMatrix<T>::Add(const SparseMatrix<T>& b, SparseMatrix<T>& c)const{
	// 计算 c = (*this) + b
	// 验证可行性
	if (rows != b.rows || cols != b.cols)
		throw SizeMismatch();
	// 设置结果矩阵c的特征
	c.rows = rows;
	c.cols = cols;
	c.terms = 0;
	// 定义*this 和b 的游标
	int ct = 0, cb = 0;
	while (ct < terms && cb < b.terms){
		// 每一个元素的行主索引
		int indt = a[ct].row * cols + a[ct].col;
		int indb = b.a[cb].row * cols + b.a[cb].col;
		if (indt < indb){
			// b的元素在后面
			c.Append(a[ct]);
			ct++;
		}
		else{
			if (indt == indb){
				// 位置相同
				if (a[ct].value + b.a[cb].value){
					// 仅当和不为0时，才添加到c中
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
				// b的元素在前面
				c.Append(b.a[cb]);
				cb++;
			}
		}
	}
	// 复制剩余元素
	for (; ct < terms; ct++)
		c.Append(a[ct]);
	for (; cb < b.terms; cb++)
		c.Append(b.a[cb]);
}



#endif