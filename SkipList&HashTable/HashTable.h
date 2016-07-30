#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include<iostream>

template<class E, class K>
class HashTable{
private:
	int hSearch(const K& k)const;
	// 散列函数的除数
	int D;
	// 散列数组
	E *ht;
	// 一维数组
	bool *empty;
public:
	HashTable(int divisor = 11);
	~HashTable(){ 
		delete[] ht;
		delete[] empty;
	}
	bool Search(const K& k, E& e)const;
	HashTable<E, K>& Insert(const E&e);
	HashTable<E, K>& Delete(const K&k, E& e);
	void Output(std::ostream&);
};

template<class E, class K>
HashTable<E, K>::HashTable(int divisor): D(divisor){
	// 分配散列数组
	ht = new E[D];
	empty = new bool[D];

	// 置空所有桶
	for (int i = 0; i < D; i++)
		empty[i] = true;
}

template<class E, class K>
int HashTable<E, K>::hSearch(const K& k)const{
	// 查找一个开地址表，如果存在，返回k的位置，否则返回插入点（如果有足够空间）
	// 起始桶
	int i = k % D;
	// 在起始桶开始
	int j = i;	
	do{
		if (empty[j] || ht[j] == k)
			return j;
		// 下一个桶
		j = (j + 1) % D;
	} while (j != i); // j== i 表示回到起始桶

	// 表已经满
	return j;
}

template<class E, class K>
bool HashTable<E, K>::Search(const K& k, E& e)const{
	// 搜索与k相匹配的元素并放入e，如果不存在，则返回false;
	int b = hSearch(k);
	if (empty[b] || ht[b] != k)
		return false;
	e = ht[b];
	return true;
}

template<class E, class K>
HashTable<E, K>& HashTable<E, K>::Insert(const E& e){
	// 在散列表中插入一个元素
	K k = e;
	int b = hSearch(k);

	// 检查是否能完成插入
	if (empty[b]){
		empty[b] = false;
		ht[b] = e;
		return *this;
	}

	// 不能插入，检查是否有重复值或者表满
	if (ht[b] == k){
		std::cerr << "The key " << k << " already in the HashTable\n";
		return *this;
	}
	else{
		std::cerr << "The  HashTable is full.\n";
		return *this;
	}
}

template<class E, class K>
HashTable<E, K>& HashTable<E, K>::Delete(const K& k, E& e){
	// 删除与k相匹配的元素，并放入e
	int b = hSearch(k);

	// 检查是否能进行删除操作
	if (empty[b]){
		std::cerr << "The key " << k << " is not in the HashTable\n";
		return *this;
	}

	// 可以删除
	e = ht[b];
	empty[b] = true;
	ht[b] = 0;
	int i = b;
	int j = (b+1) % D;
	// 从下一个桶开始搜索是否存在另一个起始桶一样的元素
	do{
		if (!empty[j]){
			if (ht[j] % D == i){
				empty[i] = false;
				ht[i] = ht[j];
				empty[j] = true;
				ht[j] = 0;
				i = j;
			}
		}
		j = (j + 1) % D;
	} while (j != b || empty[j]);
}

template<class E,class K>
void HashTable<E, K>::Output(std::ostream& out){
	out << "The buckets in HashTable are totally " << D << "\n";
	for (int i = 0; i < D; i++){
		if (empty[i])
			out << i << "-- empty\n";
		else
			out << i << "--" << ht[i] << "\n";
	}
}

template<class E, class K>
std::ostream& operator<<(std::ostream& out, HashTable<E, K>& h){
	h.Output(out);
	return out;
}

#endif