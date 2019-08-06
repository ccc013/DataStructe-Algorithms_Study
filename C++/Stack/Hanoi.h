#ifndef HANOI_H_
#define HANOI_H_

#include"Stack.h"
#include<iostream>

class Hanoi{
	friend void useTowersOfHanoi(int);
public:
	void TowersOfHanoi(int n, int x, int y, int z);
	void ShowState();
private:
	Stack<int> *S[4];
};

void Hanoi::TowersOfHanoi(int n, int x, int y, int z){
	// ��n�����Ӵ���x�ƶ�����y���ɽ�������z
	// ���ӱ��
	int d; 
	if (n > 0){
		TowersOfHanoi(n - 1, x, z, y);
		// ��x���ƶ���һ������
		S[x]->Delete(d);
		// �ŵ�y��
		S[y]->Add(d);
		ShowState();
		TowersOfHanoi(n - 1, z, y, x);
	}
}

void Hanoi::ShowState(){
	std::cout << "current state:\n";
	std::cout << "Tower1: " << S[1] << std::endl;
	std::cout << "Tower2: " << S[2] << std::endl;
	std::cout << "Tower3: " << S[3] << std::endl;
}

void useTowersOfHanoi(int n){
	// Ԥ�������
	Hanoi X;
	X.S[1] = new Stack<int>(n);
	X.S[2] = new Stack<int>(n);
	X.S[3] = new Stack<int>(n);

	for (int d = n; d > 0; d--)
		// �����ӷŵ���1��
		X.S[1]->Add(d);

	X.TowersOfHanoi(n, 1, 2, 3);
}

#endif