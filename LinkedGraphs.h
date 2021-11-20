#pragma once
#pragma once
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

struct Edge {
    int src, dest;
};

class LinkedGraphs
{
private:
    Node* getAdjListNode(int dest, Node* head)
    {
        Node* newNode = new Node;
        newNode->value = dest;

        // point new node to the current head
        newNode->next = head;

        return newNode;
    }
public:
    Node** head;
    int nodeCount;

    LinkedGraphs(Edge edges[], int nodeCount) {
        this->nodeCount = nodeCount;
        head = new Node * [nodeCount]();

        // initialize head pointer for all vertices
        for (int i = 0; i < nodeCount; i++) {
            head[i] = nullptr;
        }

        int n = sizeof(edges) / sizeof(edges[0]);

        // add edges to the directed graph
        for (unsigned i = 0; i < n; i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;

            // insert at the beginning
            Node* newNode = getAdjListNode(dest, head[src]);

            // point head pointer to the new node
            head[src] = newNode;

            // uncomment the following code for undirected graph

            /*
            newNode = getAdjListNode(src, head[dest]);

            // change head pointer to point to the new node
            head[dest] = newNode;
            */
        }
    }

    void printList(Node* ptr)
    {
        while (ptr != nullptr)
        {
            cout << " —> " << ptr->value << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    ~LinkedGraphs() {
        for (int i = 0; i < nodeCount; i++) {
            delete[] head[i];
        }

        delete[] head;
    }

};
