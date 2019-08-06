#ifndef WINNERTREE_H_
#define WINNERTREE_H_
#include<iostream>

template<class T>
class WinnerTree{
private:
	int MaxSize;
	int n;
	// 最底层的外部节点
	int LowExt;	
	int offset;
	// 赢者树数组
	int *t;
	// 元素数组
	T *e;
	void Play(int p, int lc, int rc, int(*winner)(T a[], int b, int c));
public:
	WinnerTree(int TreeSize = 10);
	~WinnerTree(){ delete[] t; }
	void Initialize(T a[], int size, int(*winner)(T a[], int b, int c));
	int Winner() const{ return (n) ? t[1] : 0 };
	int Winner(int i)const{ return (i < n) ? t[i] : 0; }
	void RePlay(int i, int(*winner)(T a[], int b, int c));
	void Output(std::ostream&);
};

template<class T>
WinnerTree<T>::WinnerTree(int TreeSize) : MaxSize(TreeSize),n(0){
	t = new int[MaxSize];
}

template<class T>
void WinnerTree<T>::Initialize(T a[], int size, int(*winner)(T a[], int b, int c)){
	if (size > MaxSize || size < 2)
		throw BadInput();

	n = size;
	e = a;

	// 计算 s = 2^log(n-1)
	int i, s;
	for (s = 1; 2 * s <= n - 1; s += s);

	LowExt = 2 * (n - s);
	offset = 2 * s - 1;

	// 最底层外部节点的比赛
	for (i = 2; i <= LowExt; i += 2)
		Play((offset + i) / 2, i - 1, i, winner);
	// 处理其余外部节点
	if (n % 2){
		// n是奇数的时候，内部节点和外部节点的比赛
		Play(n / 2, t[n - 1], LowExt + 1, winner);
		i = LowExt + 3;
	}
else
	i = LowExt + 2;

	// i是最左剩余节点
	for (; i <= n; i += 2)
		Play((i - LowExt + n - 1) / 2, i - 1, i, winner);

}

template<class T>
void WinnerTree<T>::Play(int p, int lc, int rc, int(*winner)(T a[], int b, int c)){
	// 在t[p]处开始比赛
	t[p] = winner(e, lc, rc);

	// 若在右孩子处，则可能有多场比赛
	while (p > 1 && p % 2){
		t[p / 2] = winner(e, t[p - 1], t[p]);
		// 到父节点
		p /= 2;
	}

}

template<class T>
void WinnerTree<T>::RePlay(int i, int(*winner)(T a[], int b, int c)){
	// 针对元素i重新组织比赛
	if (i <= 0 || i > n)
		throw OutOfBounds();

	int p, lc, rc;
	// 找到第一个比赛节点及其子女
	if (i <= LowExt){
		// 从最底层开始
		p = (offset + i) / 2;
		lc = 2 * p - offset;
		rc = lc + 1;
	}
	else{
		p = (i - LowExt + n - 1) / 2;
		if (2 * p == n - 1){
			lc = t[2 * p];
			rc = i;
		}
		else{
			lc = 2 * p - n + 1 + LowExt;
			rc = lc + 1;
		}
	}
	t[p] = winner(e, lc, rc);

	// 剩余节点的比赛
	p /= 2; // 移到父节点
	for (; p >= 1; p /= 2){
		t[p] = winner(e, t[2 * p], t[2 * p + 1]);
	}

}

template<class T>
void WinnerTree<T>::Output(std::ostream& out){
	if (n == 0){
		out << "empty winnerTree\n";
		return;
	}

	for (int i = 2; i <= n; i++){
		out << t[i-1] << ", ";
	}
	out << "\n";
}

template<class T>
std::ostream& operator<<(std::ostream& out, WinnerTree<T>& w){
	w.Output(out);
	return out;
}

#endif