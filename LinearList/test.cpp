#include<iostream>
#include"ResizeLinearList.h"
#include"llist.h"
#include"xcept.h"

using std::cout;
using std::endl;
using std::cin;

void testLinearList(){
	try{
		cout << "test LinearList\n";
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
}

void testResizeLinearList(){
	try{
		cout << "test ResizeLinearList\n";
		ResizeLinearList<int> L;
		cout << "Length = " << L.Length() << endl;
		cout << "IsEmpty = " << L.isEmpty() << endl;
		for (int i = 0; i < 5; i++){
			L.Insert(i, i + 5);
		}
		cout << "List is " << L << endl;
		int z;
		L.Find(3, z);
		cout << "First element is " << z << endl;
		cout << "Length = " << L.Length() << endl;
		L.Delete(3, z);
		cout << "Deleted element is " << z << endl;
		cout << "List is " << L << endl;
	}
	catch (...){
		std::cerr << "An exception has occured" << endl;
	}
}

int main(){

	// testLinearList
	testLinearList();

	// test ResizeLinearList
	testResizeLinearList();

	system("pause");
	return 0;
}

