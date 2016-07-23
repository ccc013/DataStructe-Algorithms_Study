#include<iostream>
#include<ctime>
#include"xcept.h"
#include"Queue.h"


using std::cout;
using std::endl;
using std::cin;

void testQueue(){
	Queue<int> q(12);
	for (int i = 0; i < 6; i++)
		q.Add(i * 2 + 6);
	cout << "Now queue contains--";
	cout << q;
	cout << "queue is full?" << q.IsFull() << endl;

	int x;
	q.Delete(x);
	cout << "delete a element from queue, it is " << x << endl;
	cout << "Now queue contains--" << q;
}

int main(){

	testQueue();

	system("pause");
	return 0;
}

