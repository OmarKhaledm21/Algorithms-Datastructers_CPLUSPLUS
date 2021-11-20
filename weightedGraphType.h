#pragma once
#include <iomanip>
#include "graphType.h"

class weightedGraphType : public graphType
{
protected:
	double** weights; //pointer to create weight matrix
	double* smallestWeight; //pointer to create the array to store
	//the smallest weight from source to vertices

public:
	void createWeightedGraph();
	//Function to create the graph and the weight matrix.
	//Postcondition: The graph using adjacency lists and
	// its weight matrix is created.
	void shortestPath(int vertex);
	//Function to determine the weight of a shortest path
	//from vertex, that is, source, to every other vertex
	//in the graph.
	//Postcondition: The weight of the shortest path from vertex
	// to every other vertex in the graph is determined.
	void printShortestDistance(int vertex);
	//Function to print the shortest weight from the vertex
	//specified by the parameter vertex to every other vertex in
	//the graph.
	//Postcondition: The weight of the shortest path from vertex
	// to every other vertex in the graph is printed.
	weightedGraphType(int size = 0);
	//Constructor
	//Postcondition: gSize = 0; maxSize = size;
	// graph is an array of pointers to linked lists.
	// weights is a two-dimensional array to store the weights
	// of the edges.
	// smallestWeight is an array to store the smallest weight
	// from source to vertices.
	~weightedGraphType();
	//Destructor
	//The storage occupied by the vertices and the arrays
	//weights and smallestWeight is deallocated.

};

