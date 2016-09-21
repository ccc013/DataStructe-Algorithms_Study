#ifndef GRAPH_H_
#define GRAPH_H_
#include<iostream>

template<class T>
class AdjacencyWGraph;

// 加权有向图的耗费邻接矩阵类
template<class T>
class AdjacencyWDigraph{
	friend AdjacencyWGraph<T>;
private:
	T NoEdge;	// 用于没有边存在的情形
	int n;			// 顶点数目
	int e;			// 边数
	T **a;			// 二维数组
public:
	AdjacencyWDigraph(int Vertices = 10, T noEdge = 0);
	~AdjacencyWDigraph(){ Delete2DArray(a, n); }
	void Delete2DArray(T ** &a, int rows){
		for (int i = 0; i < rows; i++){
			delete[] a[i];
		}
		delete[] a;
		a = 0;
	}
	bool Exist(int i, int j)const;
	int Edges()const{ return e; }
	int Vertices() const{ return n; }
	AdjacencyWDigraph<T>& Add(int i, int j, const T& w);
	AdjacencyWDigraph<T>& Delete(int i, int j);
	int OutDegree(int i)const;
	int InDegree(int i)const;
	void Output(std::ostream&);
};

template<class T>
AdjacencyWDigraph<T>::AdjacencyWDigraph(int Vertices, T noEdge){
	n = Vertices;
	e = 0;
	NoEdge = noEdge;
	// 创建一个二维数组
	a = new T *[n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	// 初始化为没有边的图
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			a[i][j] = NoEdge;
	}

}

template<class T>
bool AdjacencyWDigraph<T>::Exist(int i, int j)const{
	if (i<0 || j<0 || i>=n || j>=n || a[i][j] == NoEdge)
		return false;
	return true;
}

template<class T>
AdjacencyWDigraph<T>& AdjacencyWDigraph<T>::Add(int i, int j, const T& w){
	// 插入边(i,j)
	if (i<0 || j<0 || i>=n || j>=n || i == j || a[i][j] != NoEdge){
		std::cerr << "There is no (" << i << ", " << j << ").\n";
		return *this;
	}
	a[i][j] = w;
	e++;
	return *this;
}

template<class T>
AdjacencyWDigraph<T>& AdjacencyWDigraph<T>::Delete(int i, int j){
	// 删除边(i,j)
	if (i<0 || j<0 || i>=n || j>=n || a[i][j] == NoEdge){
		std::cerr << "There is no (" << i << ", " << j << ").\n";
		return *this;
	}
	a[i][j] = NoEdge;
	e--;
	return *this;
}

template<class T>
int AdjacencyWDigraph<T>::OutDegree(int i) const{
	// 返回顶点i的出度
	if (i<0 || i>=n){
		std::cerr << "There is no (" << i << ", " << ").\n";
		return 0;
	}
	int sum = 0;
	for (int j = 0; j < n; j++){
		if (a[i][j] != NoEdge)
			sum++;
	}
	return sum;
}

template<class T>
int AdjacencyWDigraph<T>::InDegree(int i) const{
	// 返回顶点i的入度
	if (i<0 || i>=n){
		std::cerr << "There is no (" << i << ", " << ").\n";
		return 0;
	}
	int sum = 0;
	for (int j = 0; j < n; j++){
		if (a[j][i] != NoEdge)
			sum++;
	}
	return sum;
}

template<class T>
void AdjacencyWDigraph<T>::Output(std::ostream& out){
	int sum = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			sum++;
			out << "(" << i << ", " << j << ") = " << a[i][j] << ", ";
			if (sum % 3 == 0)
				out << "\n";
		}
	}
	out << "\n";
}

template<class T>
std::ostream& operator<<(std::ostream& out, AdjacencyWDigraph<T>& x){
	x.Output(out);
	return out;
}

// 加权图的耗费邻接矩阵类
template<class T>
class AdjacencyWGraph : public AdjacencyWDigraph<T>{
public:
	AdjacencyWGraph(int Vertices = 10, T noEdge = 0) : AdjacencyWDigraph<T>(Vertices, noEdge){}
	AdjacencyWGraph<T>& Add(int i, int j, const T& w){
		AdjacencyWDigraph<T>::Add(i, j, w);
		a[j][i] = w;
		return *this;
	}
	AdjacencyWGraph<T>& Delete(int i, int j){
		AdjacencyWDigraph<T>::Delete(i, j);
		a[j][i] = NoEdge;
		return *this;
	}
	int Degree(int i) const{ return OutDegree(i); }
};

// 有向图的邻接矩阵类
class AdjacencyDigraph : public AdjacencyWDigraph<int>{
public:
	AdjacencyDigraph(int Vertices = 0) : AdjacencyWDigraph<int>(Vertices, 0){}
	AdjacencyDigraph& Add(int i, int j){
		AdjacencyWDigraph<int>::Add(i, j, 1);
		return *this;
	}
	AdjacencyDigraph& Delete(int i, int j){
		AdjacencyWDigraph<int>::Delete(i, j);
		return *this;
	}
};

// 图的邻接矩阵
class AdjacencyGraph : public AdjacencyWGraph<int>{
public :
	AdjacencyGraph(int Vertices = 10) : AdjacencyWGraph<int>(Vertices, 0) {}
	AdjacencyGraph& Add(int i, int j)
	{
		AdjacencyWGraph<int> :: Add(i, j, 1);
		return *this;
	}
	AdjacencyGraph& Delete(int i, int j)
	{
		AdjacencyWGraph<int> :: Delete(i, j);
		return *this;
	}
};

#endif