#include<iostream>
#include"xcept.h"
#include"BSTree.h"

using std::cout;
using std::endl;
using std::cin;

void testBSTree(){
	BSTree<int, int> t;
	int a[] = { 12, 3, 21, 2, 5, 6, 7, 11, 0, 20 };
	for (int i = 0; i < 10; i++)
		t.Insert(a[i]);
	cout << "BSTree t:\n";
	t.Ascend();

	int aa = 0;
	t.Delete(0,aa);
	cout << "delete 0, t now is ";
	t.Ascend();

	t.Delete(5, aa);
	cout << "delete 5, t now is ";
	t.Ascend();

	t.Search(6, aa);
	cout << "search 6, get " << aa << endl;
}


int main(void){
	testBSTree();

	system("pause");
	return 0;
}

