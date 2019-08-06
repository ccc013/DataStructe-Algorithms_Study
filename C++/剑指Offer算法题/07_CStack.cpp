#include<iostream>
#include "CStack.h"
using std::cout;
using std::endl;
using std::cin;

// ≤‚ ‘
int main(void){
	CStack<int> s;
	for (int i = 0; i < 3; i++)
		s.append(i);
	while (!s.empty())
		cout << s.remove() << " ";
	cout << endl;
	s.append(3);
	s.append(2);
	cout << s.remove() << endl;
	s.append(5);
	while (!s.empty())
		cout << s.remove() << " ";
	cout << endl;

	system("pause");
	return 0;
}