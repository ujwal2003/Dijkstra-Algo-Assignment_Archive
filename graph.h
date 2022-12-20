#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>

using namespace std;

class Graph {
	private:
		bool isDirected; //directed or undirected graph
	
	public:
		map<int, map<int, double>> adjList;
		
		Graph(bool _isDirected);
		void addEdge(int v1, int v2, double weight);
		void printGraph();
};

#endif