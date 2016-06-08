#include<iostream>
#include"llist.h"
#include"xcept.h"


int main(){
	using std::cout;
	using std::endl;
	using std::cin;

	try{
		LinearList<int> L(5);
		cout << "Length = " << L.Length() << endl;
		cout << "IsEmpty = " << L.isEmpty() << endl;
		L.Insert(0, 2).Insert(1, 6);
		cout << "List is " << L << endl;
		int z;
		L.Find(1, z);
		cout << "First element is " << z << endl;
		cout << "Length = " << L.Length() << endl;
		L.Delete(1, z);
		cout << "Deleted element is " << z << endl;
		cout << "List is " << L << endl;
	}
	catch (...){
		std::cerr << "An exception has occured" << endl;
	}

	system("pause");
	return 0;
}

