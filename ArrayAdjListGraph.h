#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
	int source;
	int destination;
};

class ArrayAdjListGraph
{
private:
	vector<vector<int>>adjList;
	int size;
public:
	ArrayAdjListGraph(vector<Edge> const& edges, int N) {
		adjList.resize(N);
		size = N;
		for (auto& edge : edges)
		{
			adjList[edge.source].push_back(edge.destination);

			// uncomment the following code for undirected graph
			// adjList[edge.dest].push_back(edge.src);
		}
	}

	void addEdges(const int u,const int v,bool bidirectional) {
		adjList[u].push_back(v);
		if (bidirectional) {
			adjList[v].push_back(u);
		}
	}

	void printGraph()
	{
		for (int i = 0; i < size; i++)
		{
			// print the current vertex number
			cout << i << " --> ";

			// print all neighboring vertices of a vertex `i`
			for (int v : adjList[i]) {
				cout << v << " ";
			}
			cout << endl;
		}
	}

	

	~ArrayAdjListGraph(){}
};

