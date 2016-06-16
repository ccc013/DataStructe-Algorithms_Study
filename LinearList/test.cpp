#include<iostream>
#include"ResizeLinearList.h"
#include"llist.h"
#include"xcept.h"
#include"ChainList.h"
#include"CircularList.h"
#include"IndirectList.h"

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

void testChainList(){
	try{
		cout << "test ChainList\n";
		Chain<int> L;
		cout << "Length = " << L.Length() << endl;
		cout << "IsEmpty = " << L.isEmpty() << endl;
		for (int i = 0; i < 10; i++){
			L.Insert(i, i * 2);
		}
		Output(L);
		int z;
		L.Find(1, z);
		cout << "First element is " << z << endl;
		cout << "Length = " << L.Length() << endl;
		L.Delete(3, z);
		cout << "Deleted element is " << z << endl;
		Output(L);
		L.Append(66);
		cout << "list is " << L << endl;
		L.Erase();
		cout << "list is " << L << endl;
	}
	catch (...){
		std::cerr << "An exception has occured" << endl;
	}
	
}

void testCircularList(){
	try{
		cout << "test CircularList\n";
		CircularList<int> L;
		cout << "Length = " << L.Length() << endl;
		cout << "IsEmpty = " << L.isEmpty() << endl;
		for (int i = 0; i < 5; i++){
			L.Insert(i, i + 3);
		}
		cout << "List is " << L << endl;
		int z;
		L.Find(3, z);
		cout << "The 3th element is " << z << endl;
		cout << "Length = " << L.Length() << endl;
		L.Delete(3, z);
		cout << "Deleted element is " << z << endl;
		cout << "List is " << L << endl;
	}
	catch (...){
		std::cerr << "An exception has occured" << endl;
	}
}

void testIndirectList(){
	try{
		cout << "test IndirectList\n";
		IndrectList<int> L(20);
		cout << "Length = " << L.Length() << endl;
		cout << "IsEmpty = " << L.isEmpty() << endl;
		for (int i = 0; i < 5; i++){
			L.Insert(i, i + 1);
		}
		cout << "List is " << L << endl;
		int z;
		L.Find(3, z);
		cout << "The 3th element is " << z << endl;
		cout << "Length = " << L.Length() << endl;
		L.Delete(3, z);
		cout << "Deleted element is " << z << endl;
		cout << "List is " << L << endl;
		for (int j = L.Length(); j < 20; j++)
			L.Insert(j, j * 2);
		cout << "after insert, List is " << L << endl;
		cout << "Search List:\n";
		cout << "10 is in List's " << L.Search(10) << "th location.\n";
	}
	catch (...){
		std::cerr << "An exception has occured" << endl;
	}
}

int main(){

	// testLinearList
	//testLinearList();

	// test ResizeLinearList
	//testResizeLinearList();

	// test ChainList
	//testChainList();

	// test CircularList
	//testCircularList();

	// test IndirectList
	testIndirectList();

	system("pause");
	return 0;
}

