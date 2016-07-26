#include<iostream>
#include<ctime>
#include"xcept.h"
#include"SortedChain.h"

using std::cout;
using std::endl;
using std::cin;

void testSortedChain(){
	SortedChain<int, int> sC;
	for (int i = 0; i < 10; i++)
		sC.DistinctInsert(i*i,i * 2 + 5);
	cout << sC;
	cout << "Length = " << sC.Length() << endl;
	
	int e = 0;
	sC.Search(5, e);
	cout << "Search 5-->" << e << endl;
	sC.Delete(9, e);
	cout << "Delete 9-->" << e << endl;
	for (int i = 5; i <10; i++)
		sC.Insert(i * 2 + 5);
	cout << sC;
	cout << "Length = " << sC.Length() << endl;
	for (int i = 10; i <15; i++)
		sC.DistinctInsert(i*i,i*2 + 5);
	cout << sC;
	cout << "Length = " << sC.Length() << endl;
}

int main(){

	testSortedChain();

	system("pause");
	return 0;
}

