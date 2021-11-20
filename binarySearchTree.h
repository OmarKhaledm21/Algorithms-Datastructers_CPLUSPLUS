#pragma once
#include <iostream>
#include<queue>
#include <cassert>
using namespace std;

struct nodeType
{
	int  info;
	nodeType* left;
	nodeType* right;
};

class binarySearchTreeType{
public:
	bool isEmpty();
	bool search(int);
	bool searchRec(int);
	void insert(int);
	void remove(int);
	void levelorderTraversal();//BREADTH
	void inorderTraversal();//DEPTH
	void preorderTraversal();//DEPTH
	void postorderTraversal();//DEPTH
	int treeHeight();
	int treeNodeCount();
	int treeLeavesCount();
	void clearTree();
	binarySearchTreeType();
	~binarySearchTreeType();
private:
	nodeType* root;
	void clear(nodeType*& p);
	void levelorder(nodeType*);
	void inorder(nodeType* p);
	void preorder(nodeType* p);
	void postorder(nodeType* p);
	int height(nodeType* p);
	int max(int x, int y);
	int nodeCount(nodeType* p);
	int leavesCount(nodeType* p);
	void deleteFromTree(nodeType*& p);
	bool searchRecPriv(nodeType*, int);
};

/*
int main()
{
	binarySearchTreeType b;
	b.insert(10);
	b.insert(20);
	b.insert(5);
	b.inorderTraversal();
	b.postorderTraversal();
	b.preorderTraversal();
	cout << endl;
	b.levelorderTraversal();
	return 0;
}
*/