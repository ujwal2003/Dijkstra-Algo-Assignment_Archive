#include <iostream>
#include <map>
#include <set>
#include <float.h>
#include <utility>

#include "graph.h"

#define INF DBL_MAX

using namespace std;

//set default distance to infinity
struct distVal {
	double distance = INF;
};

void showShortestDistance(Graph &g, int src, int dest) {
	map<int, bool> visited;
	map<int, distVal> dist;
	
	//perhaps not the best way to make a priority queue
	dist[src].distance = 0.0;
	set<pair<double, int>> pQ;
	
	pair<double, int> ed(0.0, src);
	pQ.insert(ed);
	
	while(!pQ.empty()) {
		auto top = *(pQ.begin());
		int indx = top.second;
		double val = top.first;
		pQ.erase(top);
		visited[indx] = true;
		
		if(dist[indx].distance < val)
			continue;
		for(auto edge: g.adjList[indx]) {
			if(visited[edge.first]){continue;}
			
			double newDist = dist[indx].distance + edge.second;
			if(newDist < dist[edge.first].distance) {
				dist[edge.first].distance = newDist;
				pair<double, int> newEd(newDist, edge.first);
				pQ.insert(newEd);
			}
		}
	}
	
	cout << dist[dest].distance;
}

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
	
	cout << endl << "shortest distance from node 3 to 6 is: ";
	showShortestDistance(g, 3, 6);
}