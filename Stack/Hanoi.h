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
	// 把n个碟子从塔x移动到塔y，可借助于塔z
	// 碟子编号
	int d; 
	if (n > 0){
		TowersOfHanoi(n - 1, x, z, y);
		// 从x中移动走一个碟子
		S[x]->Delete(d);
		// 放到y上
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
	// 预处理程序
	Hanoi X;
	X.S[1] = new Stack<int>(n);
	X.S[2] = new Stack<int>(n);
	X.S[3] = new Stack<int>(n);

	for (int d = n; d > 0; d--)
		// 将碟子放到塔1上
		X.S[1]->Add(d);

	X.TowersOfHanoi(n, 1, 2, 3);
}

#endif