#ifndef SKIPLIST_H_
#define SKIPLIST_H_
#include<iostream>
#include<ctime>

template<class E, class K>
class SkipList;

class element{
	friend int main(void);
public:
	operator long() const{ return key; }
	element& operator=(long y){
		key = y;
		return *this;
	}
private:
	int data;
	long key;
};

template<class E, class K>
class SkipNode{
	friend SkipList<E, K>;
private:
	SkipNode(int size){
		link = new SkipNode<E, K>*[size];
	}
	~SkipNode() { delete[] link; }
	
	E data;
	// һάָ������
	SkipNode<E, K> **link;
};

template<class E,class K>
class SkipList{
private:
	int Level();
	SkipNode<E, K>* SaveSearch(const K& k);
	// ������������
	int MaxLevel;
	// ��ǰ�ǿ����ĸ���
	int Levels;
	// ����ȷ������
	int CutOff;
	// һ���ܴ��keyֵ
	K TailKey;
	// ͷ�ڵ�ָ��
	SkipNode<E, K>* head;
	// β�ڵ�ָ��
	SkipNode<E, K>* tail;
	// ָ������
	SkipNode<E, K>** last;

public:
	SkipList(K Large, int MaxE = 10000, float p = 0.5);
	~SkipList();
	bool Search(const K&k, E&e)const;
	SkipList<E, K>& Insert(const E& e);
	SkipList<E, K>& Delete(const K&k, E&e);
	void Output(std::ostream&);
};

template<class E, class K>
SkipList<E, K>::SkipList(K Large, int MaxE, float p){
	CutOff = p * RAND_MAX;
	MaxLevel = ceil(log(MaxE) / log(1 / p)) - 1;
	TailKey = Large;
	// ��ʼ�����������
	srand((unsigned)time(NULL));
	// �Լ��Ž��г�ʼ��
	Levels = 0;

	// ����ͷ�ڵ㡢β�ڵ��Լ�����last
	head = new SkipNode<E, K>(MaxLevel + 1);
	tail = new SkipNode<E, K>(0);
	last = new SkipNode<E, K> *[MaxLevel + 1];
	tail->data = Large;

	// �����м����ÿգ�����headָ��tail
	for (int i = 0; i <= MaxLevel; i++)
		head->link[i] = tail;
}

template<class E, class K>
SkipList<E, K>::~SkipList(){
	SkipNode<E, K>* next;

	// ͨ��ɾ��0������ɾ�����нڵ�
	while (head != tail){
		next = head->link[0];
		delete head;
		head = next;
	}

	delete tail;

	delete[] last;
}

template<class E, class K>
bool SkipList<E, K>::Search(const K& k, E& e)const{
	// ������k��ƥ���Ԫ�أ������ҵ���Ԫ�ط���e������������򷵻�false
	if (k >= TailKey)
		return false;
	// ����ָ��p��ʹ��ǡ��ָ�������k��ƥ��Ľڵ��ǰһ���ڵ�
	SkipNode<E, K>*p = head;
	for (int i = Levels; i >= 0; i--){
	// ������
		while (p->link[i]->data < k)
			// �ڵ�i����������
			p = p->link[i];
	}
		
	// ����Ƿ���һ���ڵ�ӵ�йؼ�ֵk
	e = p->link[0]->data;
	return (e == k);
}

template<class E, class K>
SkipNode<E, K>* SkipList<E, K>::SaveSearch(const K& k){
	// ����k�������������õ���λ��
	SkipNode<E, K>*p = head;
	for (int i = Levels; i >= 0; i--){
		// ������
		while (p->link[i]->data < k)
			// �ڵ�i����������
			p = p->link[i];
		last[i] = p;
	}
	return (p->link[0]);
}

template<class E, class K>
int SkipList<E, K>::Level(){
	// ����һ��������ţ��ü���<= MaxLevel
	int lev = 0;
	while (rand() <= CutOff)
		lev++;
	return (lev <= MaxLevel) ? lev : MaxLevel;
}

template<class E, class K>
SkipList<E, K>& SkipList<E, K>::Insert(const E& e){
	// ����������ظ��������e
	K k = e;
	if (k >= TailKey){
		std::cerr << "The key is larger than " << TailKey << "\n";
		return *this;
	}
	// ����Ƿ��ظ�
	SkipNode<E, K>*p = SaveSearch(k);
	if (p->data == e){
		std::cerr << "The key is already in SkipList\n";
		return *this;
	}

	// ���ظ���Ϊ�½ڵ�ȷ������
	int lev = Level();
	if (lev > Levels){
		lev = ++Levels;
		last[lev] = head;
	}

	// �����½ڵ㣬�����½ڵ����p֮��
	SkipNode<E, K>*y = new SkipNode<E, K>(lev + 1);
	y->data = e;
	for (int i = 0; i <= lev; i++){
		// ���뵽��i����
		y->link[i] = last[i]->link[i];
		last[i]->link[i] = y;
	}

	return *this;
}

template<class E, class K>
SkipList<E, K>& SkipList<E, K>::Delete(const K&k, E&e){
	// ɾ����k��ƥ���Ԫ�أ�����ɾ����Ԫ�ط���e��
	if (k >= TailKey){
		std::cerr << "The key is larger than " << TailKey << "\n";
		return *this;
	}
	// ����Ƿ������k��ƥ���Ԫ��
	SkipNode<E, K>*p = SaveSearch(k);
	if (p->data != e){
		std::cerr << "The key is already in SkipList\n";
		return *this;
	}
	// ��������ɾ���ڵ�
	for (int i = 0; i <= Levels && last[i]->link[i] == p; i++)
		last[i]->link[i] = p->link[i];

	// �޸ļ���
	while (Levels > 0 && head->link[Levels] == tail)
		Levels--;

	e = p->data;
	delete p;
	return *this;
}

template<class E, class K>
void SkipList<E, K>::Output(std::ostream& out){
	SkipNode<E, K>*p = head;
	out << "SkipList:\n";
	for (int i = 0; i <= Levels; i++){
		out << i << " level: ";
		p = p->link[i];
		while (p != tail){
			out << p->data ;
			p = p->link[i];
			if (p != tail)
				out << "-->";
		}
		out << "\n";
		p = head;
	}
}

template<class E, class K>
std::ostream& operator<<(std::ostream& out, SkipList<E, K>& s){
	s.Output(out);
	return out;
}

#endif