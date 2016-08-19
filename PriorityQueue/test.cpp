#include<iostream>
#include"xcept.h"
#include"MaxHeap.h"

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

int main(void){
	testMaxHeap();

	system("pause");
	return 0;
}

