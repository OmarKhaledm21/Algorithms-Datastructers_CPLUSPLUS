#pragma once
#include <iostream>
#include <vector>
using namespace std;

// Data structure to store a graph edge
struct Edge {
    int src, dest, weight;
};

typedef pair<int, int> Pair;

// A class to represent a graph object
class Graph
{
public:
    // a vector of vectors of Pairs to represent an adjacency list
    vector<vector<Pair>> adjList;

    // Graph Constructor
    Graph(vector<Edge> const& edges, int N)
    {
        // resize the vector to hold `N` elements of type vector<Pair>
        adjList.resize(N);

        // add edges to the directed graph
        for (auto& edge : edges)
        {
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;

            // insert at the end
            adjList[src].push_back(make_pair(dest, weight));
            

            // uncomment the following code for undirected graph
            // adjList[dest].push_back(make_pair(src, weight));
        }
    }

    void printGraph(int N)
    {
        for (int i = 0; i < N; i++)
        {
            // Function to print all neighboring vertices of a given vertex
            for (Pair v : adjList[i])
            {
                cout << "(" << i << ", " << v.first <<
                    ", " << v.second << ") ";
            }
            cout << endl;
        }
    }
};

/*
	vector<Edge> edges = {
		{ 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
		{ 3, 2 }, { 4, 5 }, { 5, 4 }
	};

	int N = 6;
	Graph graph(edges, N);

	graph.printGraph(N);
	*/
/*

vector<Edge> edges =
{
    // `(x, y, w)` —> edge from `x` to `y` having weight `w`
    { 0, 1, 6 }, { 1, 2, 7 }, { 2, 0, 5 }, { 2, 1, 4 },
    { 3, 2, 10 }, { 5, 4, 1 }, { 4, 5, 3 }
};

// total number of nodes in the graph
int N = 6;

// construct graph
Graph graph(edges, N);

// print adjacency list representation of a graph
graph.printGraph(N);
*/