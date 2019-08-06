#include<iostream>
#include "CQueue.h"
using std::cout;
using std::endl;
using std::cin;

// ≤‚ ‘
int main(void){
	CQueue<int> q1;
	q1.appendTail(2);
	cout << q1.deleteHead() << endl;
	for (int i = 1; i < 10; i++)
		q1.appendTail(i * 2);
	while (!q1.empty())
		cout << q1.deleteHead() << " ";
	cout << endl;

	system("pause");
	return 0;
}