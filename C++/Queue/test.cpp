#include<iostream>
#include<ctime>
#include"xcept.h"
#include"Queue.h"
#include"LinkedQueue.h"

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

void testLinkedQueue(){
	LinkedQueue<int> q;
	for (int i = 0; i < 10; i++)
		q.Add(i + 5);
	cout << q;
	cout << "queue is full?" << q.IsFull() << endl;

	int x;
	q.Delete(x);
	cout << "delete a element from queue, it is " << x << endl;
	cout << q;

	for (int i = 0; i < 5; i++)
		q.Add(i * 5);
	cout << q;
}

int main(){

	testLinkedQueue();

	system("pause");
	return 0;
}

