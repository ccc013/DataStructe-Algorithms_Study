#include<iostream>
#include<ctime>
#include"xcept.h"
#include"SortedChain.h"
#include"SkipList.h"
#include"HashTable.h"
#include"ChainHashTable.h"

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

void testSkipList(){
	SkipList<int, int> sk(100);
	for (int i = 0; i < 12; i++)
		sk.Insert(i * 2 + 2);
	cout << sk;
	int e;
	int k = 12;
	sk.Search(k, e);
	cout << "search " << k << " in skiplist, get e = " << e << "\n";
	sk.Delete(k, e);
	cout << "delete " << k << "\n";
	cout << sk;
}

void testHashTable(){
	HashTable<int, int> h(11);
	h.Insert(80);
	h.Insert(40);
	h.Insert(65);
	cout << h;
	h.Insert(24);
	h.Insert(58);
	h.Insert(35);
	h.Insert(48);
	h.Insert(98);
	cout << h;
	int e;
	cout << "Search 58\n";
	h.Search(58, e);
	cout << e << endl;
	h.Delete(80, e);
	cout << "Delete 80\n" << h;
	cout << "Search 80\n";
	h.Search(80, e);
	cout << "Search 58 again\n";
	h.Search(58, e);
	cout << e << endl;
}

void testChainHashTable(){
	ChainHashTable<int, int> ht(11);
	for (int i = 0; i <= 10; i++){
		int e = i * 2 + 10;
		ht.Insert(i, e);
	}
	cout << ht;
	int e;
	ht.Delete(5, e);
	cout << "delete key = " << 5 << ", value = " << e << "\n";
	cout << ht;
	ht.Search(10, e);
	cout << "search key = " << 10 << ", value = " << e << "\n";
	for (int i = 0; i < 10; i++){
		int e = i * 3 + 10;
		ht.Insert(i, e);
	}
	cout << ht;
}

int main(){

	testChainHashTable();

	system("pause");
	return 0;
}

