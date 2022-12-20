#include "graph.h"

#include <iostream>
#include <map>

using namespace std;

//constructor
Graph::Graph(bool _isDirected=false) {
	isDirected = _isDirected;
}

//adds edge to graph
void Graph::addEdge(int v1, int v2, double weight) {
	if(isDirected) {
		adjList[v1][v2] = weight;
	} else {
		adjList[v1][v2] = weight;
		adjList[v2][v1] = weight;
	}
}

//prints graph to console
void Graph::printGraph() {
	for(auto edge: adjList) {
		string offset = (edge.first < 10) ? " " : "";
		cout << edge.first << offset << " -> ";
		
		for(auto vertex: edge.second) {
			cout << '{' << vertex.first << " [" << vertex.second << "]} ";
		}
		cout << endl;
	}
}