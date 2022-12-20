#include <iostream>
#include "graph.h"

using namespace std;

int main(int argc, char *argv[]) {
	Graph g(true);
	g.addEdge(2, 1, 1.2);
	g.addEdge(2, 3, 1.9);
	g.addEdge(3, 5, 1.5);
	g.addEdge(4, 5, 1.2);
	g.addEdge(5, 6, 7.8);
	g.addEdge(5, 7, 3.5);
	g.addEdge(5, 8, 2.2);
	g.addEdge(6, 4, 1.1);
	g.addEdge(7, 6, 2.4);
	g.addEdge(9, 5, 1.8);
	g.addEdge(10, 9, 1.9);
	g.addEdge(11, 2, 1.4);
	
	cout << "Representation of Graph:" << endl;
	g.printGraph();
	
	cout << endl << "shortest distance from node 2 to 6 is:" << endl;
}