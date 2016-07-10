#include<iostream>
#include<ctime>
#include"xcept.h"
#include"inheritStack.h"
#include"llist.h"

using std::cout;
using std::endl;
using std::cin;

void testStack(){
	Stack<int> stack1(10);
	for (int i = 0; i < 10; i++)
		stack1.Add(i + 5);
	cout << "show Stack1\n";
	cout << stack1;

}


int main(){

	testStack();

	system("pause");
	return 0;
}

