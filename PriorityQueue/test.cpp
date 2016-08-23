#include<iostream>
#include"xcept.h"
#include"MaxHeap.h"
#include"MaxHBLT.h"

using std::cout;
using std::endl;
using std::cin;

void testMaxHeap(){
	MaxHeap<int> heap(10);
	int a[] = {20,12,35,15,10,80,30,17,2,1};
	//heap.Initialize(a, 10, 12);
	for (int i = 0; i < 10; i++){
		heap.Insert(i * 2 + 5);
	}
	cout << heap;
	int x;
	heap.DeleteMax(x);
	cout << heap;
	cout << "initialize a array:\n";
	heap.Initialize(a, 10, 12);
	cout << heap;
	cout << "delete max\n";
	heap.DeleteMax(x);
	cout << heap;
}

void testMaxHBLT(){
	MaxHBLT<int> h;
	for (int i = 0; i < 10; i++){
		int val = i * 2 + 5;
		h.Insert(val);
	}
	cout << "first insert 10 numbers: ";
	h.PreOut();
	int x;
	h.DeleteMax(x);
	cout << "Delete max, and now HBLT:\n";
	h.PreOut();

	MaxHBLT<int> h2;
	int a[] = { 20, 12, 35, 15, 10, 80, 30, 17, 2, 1 };
	h2.Initialize(a, 10);
	cout << "Initialize another HBLT: ";
	h2.PreOut();

	h.Meld(h2);
	cout << "meld two HBLTs:";
	h.PreOut();
}


int main(void){
	testMaxHBLT();

	system("pause");
	return 0;
}

