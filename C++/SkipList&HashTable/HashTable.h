#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include<iostream>

template<class E, class K>
class HashTable{
private:
	int hSearch(const K& k)const;
	// ɢ�к����ĳ���
	int D;
	// ɢ������
	E *ht;
	// һά����
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
	// ����ɢ������
	ht = new E[D];
	empty = new bool[D];

	// �ÿ�����Ͱ
	for (int i = 0; i < D; i++)
		empty[i] = true;
}

template<class E, class K>
int HashTable<E, K>::hSearch(const K& k)const{
	// ����һ������ַ��������ڣ�����k��λ�ã����򷵻ز���㣨������㹻�ռ䣩
	// ��ʼͰ
	int i = k % D;
	// ����ʼͰ��ʼ
	int j = i;	
	do{
		if (empty[j] || ht[j] == k)
			return j;
		// ��һ��Ͱ
		j = (j + 1) % D;
	} while (j != i); // j== i ��ʾ�ص���ʼͰ

	// ���Ѿ���
	return j;
}

template<class E, class K>
bool HashTable<E, K>::Search(const K& k, E& e)const{
	// ������k��ƥ���Ԫ�ز�����e����������ڣ��򷵻�false;
	int b = hSearch(k);
	if (empty[b] || ht[b] != k)
		return false;
	e = ht[b];
	return true;
}

template<class E, class K>
HashTable<E, K>& HashTable<E, K>::Insert(const E& e){
	// ��ɢ�б��в���һ��Ԫ��
	K k = e;
	int b = hSearch(k);

	// ����Ƿ�����ɲ���
	if (empty[b]){
		empty[b] = false;
		ht[b] = e;
		return *this;
	}

	// ���ܲ��룬����Ƿ����ظ�ֵ���߱���
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
	// ɾ����k��ƥ���Ԫ�أ�������e
	int b = hSearch(k);

	// ����Ƿ��ܽ���ɾ������
	if (empty[b]){
		std::cerr << "The key " << k << " is not in the HashTable\n";
		return *this;
	}

	// ����ɾ��
	e = ht[b];
	empty[b] = true;
	ht[b] = 0;
	int i = b;
	int j = (b+1) % D;
	// ����һ��Ͱ��ʼ�����Ƿ������һ����ʼͰһ����Ԫ��
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