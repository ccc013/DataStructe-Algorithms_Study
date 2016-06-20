#include<iostream>
#include<ctime>
#include"xcept.h"
#include"Array1D.h"

using std::cout;
using std::endl;
using std::cin;

void testArray1D(){
	Array1D<int> a(10);
	Array1D<int> b(10);

	for (int i = 0; i < 10; i++)
		a[i] = i * 2;
	
	cout << "a is \n";
	for (int i = 0; i < 10; i++)
		cout << a[i] <<" ";
	cout << endl;

	b = a;
	cout << "b=a, so b is \n";
	for (int i = 0; i < 10; i++)
		cout << b[i] << " ";
	cout << endl;

	cout << "c= a+b,so c :\n";
	Array1D<int> c(10);
	c = a + b;
	for (int i = 0; i < 10; i++)
		cout << c[i] << " ";
	cout << endl;

	Array1D<int> d(10) ;
	cout << "a*c = \n";
	d = a*c;
	for (int i = 0; i < 10; i++)
		cout << d[i] << " ";
	cout << endl;

	Array1D<int> e(10);
	cout << "c-b = \n";
	e = c - b;
	for (int i = 0; i < 10; i++)
		cout << e[i] << " ";
	cout << endl;
}

int main(){

	testArray1D();

	system("pause");
	return 0;
}

