#ifndef CHAINHASHTABLE_H_
#define CHAINHASHTABLE_H_
#include<iostream>
#include"SortedChain.h"

template<class E, class K>
class ChainHashTable{
private:
	// 位置数
	int D;
	// 链表数组
	SortedChain<E, K>* ht;
public:
	ChainHashTable(int divisor = 11){
		D = divisor;
		ht = new SortedChain<E, K>[D];
	}
	~ChainHashTable(){
		delete[] ht;
	}
	bool Search(const K&k, E& e)const{
		return ht[k%D].Search(k, e);
	}
	ChainHashTable<E, K>& Insert(const K& k, E& e){
		ht[k%D].DistinctInsert(k, e);
		return *this;
	}
	ChainHashTable<E, K>& Delete(const K& k, E& e){
		ht[k%D].Delete(k, e);
		return *this;
	}
	void Output(std::ostream&) const;
};

template<class E,class K>
void ChainHashTable<E, K>::Output(std::ostream& out) const{
	out << "Output ChainHashTable:\n";
	for (int i = 0; i < D; i++){
		out << "bucket " << i << "\n";
		out << ht[i];
	}
}

template<class E, class K>
std::ostream& operator<<(std::ostream& out, const ChainHashTable<E, K>& ht){
	ht.Output(out);
	return out;
}



#endif