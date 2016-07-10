#include<iostream>
#include<ctime>
#include"xcept.h"
#include"Stack.h"
#include"llist.h"

using std::cout;
using std::endl;
using std::cin;

void testStack(){
	Stack<int> stack1(10);
	cout << "show a empty stack\n";
	cout << stack1;
	for (int i = 0; i < 10; i++)
		stack1.Add(i + 2);
	cout << "stack is Full?\n";
	if (stack1.IsFull())
		cout << "Yes\n";
	else
		cout << "No\n";
	cout << "show Stack1\n";
	cout << stack1;
	
	int x;
	stack1.Delete(x);
	cout << "pop stack1, it is " << x << ".The remain elements are\n";
	cout << stack1;

}


int main(){

	testStack();

	system("pause");
	return 0;
}

