#include<iostream>
#include"xcept.h"
#include"GraphTest.h"

using std::cout;
using std::endl;
using std::cin;

void testGraph(){
	AdjacencyWDigraph<int> g(12, 0);
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 12; j++){
			if (i % 2 == 0 && j % 3 == 0){
				g.Add(i, j, 1);
			}
		}
	}
	cout << "Graph:\n";
	cout << g;
	cout << "OutDegree(0) = " << g.OutDegree(0) << ", InDegree(0)= " << g.InDegree(0) << "\n";
	cout << "Vertices = " << g.Vertices() << ", Edges=" << g.Edges() << "\n";
}


int main(void){
	testGraph();

	system("pause");
	return 0;
}

