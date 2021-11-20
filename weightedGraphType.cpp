#include "weightedGraphType.h"

void weightedGraphType::createWeightedGraph() {

}

void weightedGraphType::shortestPath(int vertex)
{
	for (int j = 0; j < gSize; j++)
		smallestWeight[j] = weights[vertex][j]; 
	
	bool* weightFound;
	weightFound = new bool[gSize];

	for (int j = 0; j < gSize; j++)
		weightFound[j] = false;
	
	weightFound[vertex] = true;
	smallestWeight[vertex] = 0;
	
	for (int i = 0; i < gSize - 1; i++)
	{
		double minWeight = DBL_MAX;
		int v;
		for (int j = 0; j < gSize; j++)
			if (!weightFound[j])
				if (smallestWeight[j] < minWeight)
				{
					v = j;
					minWeight = smallestWeight[v];
				}
		weightFound[v] = true;
		for (int j = 0; j < gSize; j++)
			if (!weightFound[j])
				if (minWeight + weights[v][j] < smallestWeight[j])
					smallestWeight[j] = minWeight + weights[v][j];
	} 
}

void weightedGraphType::printShortestDistance(int vertex)
{
	cout << "Source Vertex: " << vertex << endl;
	cout << "Shortest distance from source to each vertex."
		<< endl;
	cout << "Vertex Shortest_Distance" << endl;
	for (int j = 0; j < gSize; j++)
		cout << setw(4) << j << setw(12) << smallestWeight[j]<< endl;
	cout << endl;
} //end printShortestDistance

  //Constructor
weightedGraphType::weightedGraphType(int size)
	:graphType(size)
{
	weights = new double* [size];
	for (int i = 0; i < size; i++)
		weights[i] = new double[size];
	smallestWeight = new double[size];
}
//Destructor
weightedGraphType::~weightedGraphType()
{
	for (int i = 0; i < gSize; i++)
		delete[] weights[i];
	delete[] weights;
	delete smallestWeight;
}