#ifndef SORTEDCHAIN_H_
#define SORTEDCHAIN_H_
#include<iostream>

template<class E, class K>
class SortedChain;

template<class E,class K>
class SortedChainNode{
	friend SortedChain<E, K>;
private:
	K key;
	E data;
	SortedChainNode<E,K> * link;
};

template<class E, class K>
class SortedChain{
private:
	SortedChainNode<E, K>* first;
public:
	SortedChain(){ first = 0; }
	~SortedChain();
	bool IsEmpty() const { return first == 0; }
	int Length() const;
	bool Search(const K& k, E& e)const;
	SortedChain<E, K>& Delete(const K& k, E&e);
	SortedChain<E, K>& Insert(const E& e);
	SortedChain<E, K>& DistinctInsert(const K& k, const E& e);
	void Output(std::ostream&) const;
};

template<class E, class K>
SortedChain<E, K>::~SortedChain(){
	SortedChainNode<E, K>* next;
	while (first){
		next = first->link;
		delete first;
		first = next;
	}
}

template<class E, class K>
int SortedChain<E, K>::Length() const{
	SortedChainNode<E, K>*p = first;
	int len = 0;
	while (p){
		len++;
		p = p->link;
	}
	return len;
}

template<class E, class K>
bool SortedChain<E, K>::Search(const K& k, E& e)const{
	// ������kƥ���Ԫ�أ��������e�����û��ƥ���Ԫ�أ��򷵻�false

	SortedChainNode<E, K>* p = first;

	// ������K��ƥ���Ԫ��
	for (; p&& p->key != k; p = p->link){
	}
	if (p&&p->key == k){
		e = p->data;
		return true;
	}
	else{
		std::cout << "There is no key--" << k << " in sortedChain\n";
	}
	return false;
}

template<class E, class K>
SortedChain<E, K>& SortedChain<E, K>::Delete(const K& k, E& e){
	// ɾ����k��ƥ���Ԫ�أ����������e

	SortedChainNode<E, K>* p = first;
	// ����p
	SortedChainNode<E, K>* tp = 0;

	for (; p && p->key != k; tp = p, p = p->link){
	}

	if (p && p->key == k){
		e = p->data;
		// ��������ɾ��p��ָ���Ԫ��
		if (tp)
			tp->link = p->link;
		else
			// p�������׽ڵ�
			first = p->link;
		
		delete p;	
	}else
		std::cout << "There is no key--" << k << " in sortedChain\n";

	return *this;
}

template<class E, class K>
SortedChain<E, K>& SortedChain<E, K>::DistinctInsert(const K& k,const E& e){
	// ������в����ڹؼ�ֵ��e��ͬ��Ԫ�أ������e�����������쳣BadInput

	SortedChainNode<E, K>* p = first;
	// ����p
	SortedChainNode<E, K>* tp = 0;

	// �ƶ�tp�Ա��e���뵽tp֮��
	for (; p && p->key != k; tp = p, p = p->link);

	if (p && p->key == k){
		std::cout << "There is already key--" << k << " in sortedChain,please choose another key.\n";
		return *this;
	}

	// ��û�г����ظ��ؼ�ֵ�������һ���ؼ�ֵΪe���½ڵ�
	SortedChainNode<E, K>* q = new SortedChainNode<E, K>;
	q->data = e;
	q->key = k;
	// ���½ڵ���뵽tp֮��
	q->link = p;
	if (tp)
		tp->link = q;
	else
		first = q;

	return *this;
}

template<class E, class K>
SortedChain<E, K>& SortedChain<E, K>::Insert(const E& e){
	// ����e���������ظ��ؼ��֣����������쳣BadInput

	SortedChainNode<E, K>* p = first;
	// ����p
	SortedChainNode<E, K>* tp = 0;

	// �ƶ�tp�Ա��e���뵽tp֮��
	for (; p && p->data < e; tp = p, p = p->link){
	}
	
	SortedChainNode<E, K>* q = new SortedChainNode<E, K>;
	q->data = e;
	q->key = e;
	// ���½ڵ���뵽tp֮��
	q->link = p;
	if (tp)
		tp->link = q;
	else
		first = q;

	return *this;
}

template<class E,class K>
void SortedChain<E, K>::Output(std::ostream& out)const{
	SortedChainNode<E, K>*p = first;
	out << "SortedChain:\n";
	int i = 0;
	for (; p; p = p->link){
		out <<"key--"<<p->key<<",data--"<< p->data << ", ";
		i++;
		if (i % 5 == 0 && i != 0)
			out << "\n";
	}
	out << "\n";
}

// ���� <<
template<class E,class K>
std::ostream& operator<<(std::ostream& out, const SortedChain<E,K>& x){
	x.Output(out);
	return out;
}

#endif