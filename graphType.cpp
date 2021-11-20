//
// Created by Omar on 10/11/2021.
//
#include "graphType.h"

graphType::graphType(int size)
{
    maxSize = size;
    gSize = 0;
    graph = new unorderedList<int>[size];
}

bool graphType::isEmpty() const {
    return (gSize == 0);
}

void graphType::createGraph() {
    ifstream infile;
    char fileName[50];
    int vertex;
    int adjacentVertex;
    if (gSize != 0) { //if the graph is not empty, make it empty
        clearGraph();
    }
    cout << "Enter input file name: ";
    cin >> fileName;
    cout << endl;
    infile.open(fileName);
    if (!infile)
    {
        cout << "Cannot open input file." << endl;
        return;
    }
    infile >> gSize; //get the number of vertices
    for (int index = 0; index < gSize; index++)
    {
        infile >> vertex;
        infile >> adjacentVertex;
        while (adjacentVertex != -999)
        {
            graph[vertex].insertLast(adjacentVertex);
            infile >> adjacentVertex;
        } 
    }
    infile.close();
}

void graphType::clearGraph()
{
    for (int index = 0; index < gSize; index++) {
        graph[index].destroyList();
    }
    gSize = 0;
} 

void graphType::printGraph() const
{
    for (int index = 0; index < gSize; index++)
    {
        cout << index << " ";
        graph[index].print();
        cout << endl;
    }
    cout << endl;
} 

void graphType::depthFirstTraversal()
{
    bool* visited; //pointer to create the array to keep track of the visited vertices
    visited = new bool[gSize];
    for (int index = 0; index < gSize; index++)
        visited[index] = false;

    //For each vertex that is not visited, do a depth
    //first traverssal
    for (int index = 0; index < gSize; index++)
        if (!visited[index])
            dft(index, visited);

    delete[] visited;
} 

void graphType::dft(int v, bool visited[])
{
    visited[v] = true;
    cout << " " << v << " "; //visit the vertex
    Iterator<int> graphIt;
    //for each vertex adjacent to v
    for (graphIt = graph[v].begin(); graphIt != graph[v].end(); ++graphIt)
    {
        int w = *graphIt;
        if (!visited[w])
            dft(w, visited);
    } 
}

void graphType::dftAtVertex(int vertex)
{
    bool* visited;
    visited = new bool[gSize];
    for (int index = 0; index < gSize; index++)
        visited[index] = false;
    dft(vertex, visited);
    delete[] visited;
} 

void graphType::breadthFirstTraversal()
{
    queue<int> queue;
    bool* visited;
    visited = new bool[gSize];
    for (int ind = 0; ind < gSize; ind++)
        visited[ind] = false; //initialize the array
        //visited to false
    Iterator<int> graphIt;
    for (int index = 0; index < gSize; index++)
        if (!visited[index])
        {
            queue.push(index);
            visited[index] = true;
            cout << " " << index << " ";
            while (!queue.empty())
            {
                int u = queue.front();
                queue.pop();
                for (graphIt = graph[u].begin(); graphIt != graph[u].end(); ++graphIt)
                {
                    int w = *graphIt;
                    if (!visited[w])
                    {
                        queue.push(w);
                        visited[w] = true;
                        cout << " " << w << " ";
                    }
                }
            } 
        }
    delete[] visited;
}

graphType::~graphType()
{
    clearGraph();
}