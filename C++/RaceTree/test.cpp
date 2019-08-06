#include<iostream>
#include"xcept.h"
#include"WinnerTree.h"

using std::cout;
using std::endl;
using std::cin;

template<class T>
int win(T a[], int b, int c){
	return (a[b] < a[c]) ? a[c] : a[b];
}

void testWinnerTree(){
	WinnerTree<int> t(5);
	int a[] = { 10, 2, 3, 5, 7 };
	t.Initialize(a, 5, win);
	cout << t << endl;
}

int main(void){
	testWinnerTree();

	system("pause");
	return 0;
}

