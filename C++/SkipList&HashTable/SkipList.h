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
	// 一维指针数组
	SkipNode<E, K> **link;
};

template<class E,class K>
class SkipList{
private:
	int Level();
	SkipNode<E, K>* SaveSearch(const K& k);
	// 所允许的最大级数
	int MaxLevel;
	// 当前非空链的个数
	int Levels;
	// 用于确定级号
	int CutOff;
	// 一个很大的key值
	K TailKey;
	// 头节点指针
	SkipNode<E, K>* head;
	// 尾节点指针
	SkipNode<E, K>* tail;
	// 指针数组
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
	// 初始化随机发生器
	srand((unsigned)time(NULL));
	// 对级号进行初始化
	Levels = 0;

	// 创建头节点、尾节点以及数组last
	head = new SkipNode<E, K>(MaxLevel + 1);
	tail = new SkipNode<E, K>(0);
	last = new SkipNode<E, K> *[MaxLevel + 1];
	tail->data = Large;

	// 将所有级均置空，即将head指向tail
	for (int i = 0; i <= MaxLevel; i++)
		head->link[i] = tail;
}

template<class E, class K>
SkipList<E, K>::~SkipList(){
	SkipNode<E, K>* next;

	// 通过删除0级链来删除所有节点
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
	// 搜索与k相匹配的元素，并将找到的元素放入e，如果不存在则返回false
	if (k >= TailKey)
		return false;
	// 调整指针p，使其恰好指向可能与k相匹配的节点的前一个节点
	SkipNode<E, K>*p = head;
	for (int i = Levels; i >= 0; i--){
	// 逐级向下
		while (p->link[i]->data < k)
			// 在第i级链中搜索
			p = p->link[i];
	}
		
	// 检查是否下一个节点拥有关键值k
	e = p->link[0]->data;
	return (e == k);
}

template<class E, class K>
SkipNode<E, K>* SkipList<E, K>::SaveSearch(const K& k){
	// 搜索k并保存最终所得到的位置
	SkipNode<E, K>*p = head;
	for (int i = Levels; i >= 0; i--){
		// 逐级向下
		while (p->link[i]->data < k)
			// 在第i级链中搜索
			p = p->link[i];
		last[i] = p;
	}
	return (p->link[0]);
}

template<class E, class K>
int SkipList<E, K>::Level(){
	// 产生一个随机级号，该级号<= MaxLevel
	int lev = 0;
	while (rand() <= CutOff)
		lev++;
	return (lev <= MaxLevel) ? lev : MaxLevel;
}

template<class E, class K>
SkipList<E, K>& SkipList<E, K>::Insert(const E& e){
	// 如果不存在重复，则插入e
	K k = e;
	if (k >= TailKey){
		std::cerr << "The key is larger than " << TailKey << "\n";
		return *this;
	}
	// 检查是否重复
	SkipNode<E, K>*p = SaveSearch(k);
	if (p->data == e){
		std::cerr << "The key is already in SkipList\n";
		return *this;
	}

	// 不重复，为新节点确定级号
	int lev = Level();
	if (lev > Levels){
		lev = ++Levels;
		last[lev] = head;
	}

	// 产生新节点，并将新节点插入p之后
	SkipNode<E, K>*y = new SkipNode<E, K>(lev + 1);
	y->data = e;
	for (int i = 0; i <= lev; i++){
		// 插入到第i级链
		y->link[i] = last[i]->link[i];
		last[i]->link[i] = y;
	}

	return *this;
}

template<class E, class K>
SkipList<E, K>& SkipList<E, K>::Delete(const K&k, E&e){
	// 删除与k相匹配的元素，并将删除的元素放入e。
	if (k >= TailKey){
		std::cerr << "The key is larger than " << TailKey << "\n";
		return *this;
	}
	// 检查是否存在与k相匹配的元素
	SkipNode<E, K>*p = SaveSearch(k);
	if (p->data != e){
		std::cerr << "The key is already in SkipList\n";
		return *this;
	}
	// 从跳表中删除节点
	for (int i = 0; i <= Levels && last[i]->link[i] == p; i++)
		last[i]->link[i] = p->link[i];

	// 修改级数
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