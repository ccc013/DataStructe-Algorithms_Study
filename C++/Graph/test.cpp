#include<iostream>
#include"xcept.h"
#include"GraphTest.h"

using std::cout;
using std::endl;
using std::cin;

void testGraph(){
	int vertices = 8;
	AdjacencyWDigraph<int> g(vertices, 0);	// 加权有向图
	AdjacencyWGraph<int> gg(vertices, 0);	// 加权图
	AdjacencyDigraph g3(vertices);					// 有向图
	AdjacencyGraph g4(vertices);					// 图
	for (int i = 0; i < vertices; i++){
		for (int j = 0; j < vertices; j++){
			if (i % 2 == 0 && j % 3 == 0){
				g.Add(i, j, 1);
				gg.Add(i, j, 2);
				g3.Add(i, j);
				g4.Add(i, j);
			}
		}
	}
	cout << "WDGraph:\n";
	cout << g;
	
	cout << "OutDegree(0) = " << g.OutDegree(0) << ", InDegree(0)= " << g.InDegree(0) << "\n";
	cout << "Vertices = " << g.Vertices() << ", Edges=" << g.Edges() << "\n";

	cout << "WGraph:\n";
	cout << gg;
	cout << "Degree(1) = " << gg.Degree(1) << ",Degree(2)="<<gg.Degree(2)<<"\n";

	cout << "DGraph:\n";
	cout << g3;

	cout << "Graph:\n";
	cout << g4;
}


int main(void){
	testGraph();

	system("pause");
	return 0;
}

