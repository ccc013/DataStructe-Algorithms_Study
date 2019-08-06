#ifndef NODE_H_
#define NODE_H_
#include<iostream>

// ������������Ľڵ�
class Node{
	
public:
	int score;
	char *name;
	int exam1, exam2, exam3;

	int operator!=(Node x)const{
		return (score != x.score || name[0] != x.name[0]);
	}
	operator int() const { return score; }
	friend std::ostream& operator<<(std::ostream& out, const Node & x);
	friend void BinSort(Chain<Node>& X, int range);
};

std::ostream& operator<<(std::ostream & out, const Node & x){
	out  << x.name[0] << ":  exam1= "<<x.exam1 <<",  exam2= "<<x.exam2<<", exam3= "<<x.exam3;
	out << "\n";
	return out;
}

// ��������
void BinSort(Chain<Node>& X, int range){
	// ����������
	int len = X.Length();
	Node x;
	Chain<Node>* bin;
	bin = new Chain<Node>[range + 1];
	// ���䵽ÿ��������
	for (int i = 1; i <= len; i++){
		X.Delete(1, x);
		bin[x.score].Insert(0, x);
	}
	// ���������ռ���Ԫ��
	for (int j = range; j >= 0; j--){
		while (!bin[j].isEmpty()){
			bin[j].Delete(1, x);
			X.Insert(0, x);
		}
	}
	delete[] bin;
}

#endif