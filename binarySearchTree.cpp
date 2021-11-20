#include "binarySearchTree.h"

binarySearchTreeType::binarySearchTreeType()
{
	root = NULL;
}

bool binarySearchTreeType::isEmpty()
{
	return (root == NULL);
}

void binarySearchTreeType::levelorderTraversal()
{
	levelorder(root);
}

void binarySearchTreeType::inorderTraversal()
{
	inorder(root);
}

void binarySearchTreeType::preorderTraversal()
{
	preorder(root);
}

void binarySearchTreeType::postorderTraversal()
{
	postorder(root);
}

int binarySearchTreeType::treeHeight()
{
	return height(root);
}


int binarySearchTreeType::treeNodeCount()
{
	return nodeCount(root);
}

int binarySearchTreeType::treeLeavesCount()
{
	return leavesCount(root);
}

void binarySearchTreeType::levelorder(nodeType* p)
{
	queue<nodeType* >q;
	if (p == NULL)
	{
		return;
	}
	q.push(p);
	while (!q.empty()) {
		nodeType* cur = q.front();
		cout << cur->info << " ";
		if (cur->left != NULL) {
			q.push(cur->left);
		}
		if (cur->right != NULL) {
			q.push(cur->right);
		}
		q.pop();
	}
}

void binarySearchTreeType::inorder(nodeType* p)// L Root R
{
	if (p != NULL)
	{
		inorder(p->left);
		cout << p->info << " ";
		inorder(p->right);
	}
}

void binarySearchTreeType::preorder(nodeType* p) // Root L R
{
	if (p != NULL)
	{
		cout << p->info << " ";
		preorder(p->left);
		preorder(p->right);
	}
}

void binarySearchTreeType::postorder(nodeType* p)//L R Root
{
	if (p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout << p->info << " ";
	}
}

void  binarySearchTreeType::clear(nodeType*& p)
{
	if (p != NULL)
	{
		clear(p->left);
		clear(p->right);
		delete p;
		p = NULL;
	}
}

void  binarySearchTreeType::clearTree()
{
	clear(root);
}

binarySearchTreeType::~binarySearchTreeType()
{
	clear(root);
}

int binarySearchTreeType::height(nodeType* p)
{
	if (p == NULL)
		return 0;
	else
		return 1 + max(height(p->left), height(p->right));
}

int binarySearchTreeType::max(int x, int y)
{
	if (x >= y)
		return x;
	else
		return y;
}

int binarySearchTreeType::nodeCount(nodeType* p)
{
	if (p == NULL)
		return 0;
	else
		return 1 + nodeCount(p->left) + nodeCount(p->right);
}

int binarySearchTreeType::leavesCount(nodeType* p)
{
	if (p == NULL)
		return 0;
	else if ((p->left == NULL) && (p->right == NULL))
		return 1;
	else
		return leavesCount(p->left) + leavesCount(p->right);
}

bool binarySearchTreeType::search(int item)
{
	nodeType* current = root;

	while (current != NULL)
	{
		if (current->info == item)
			return true;
		else if (current->info > item)
			current = current->left;
		else
			current = current->right;
	}
	return false;
}

bool binarySearchTreeType::searchRec(int item)
{
	return searchRecPriv(root, item);
}

bool binarySearchTreeType::searchRecPriv(nodeType* p, int item)
{
	if (p == NULL)
		return false;
	else if (p->info == item)
		return true;
	else if (p->info > item)
		return searchRecPriv(p->left, item);
	else
		return searchRecPriv(p->right, item);
}

void binarySearchTreeType::insert(int item)
{
	nodeType* current;  //pointer to traverse the tree
	nodeType* trailCurrent = NULL; //pointer behind current
	nodeType* newNode;  //pointer to create the node

	newNode = new nodeType;
	assert(newNode != NULL);
	newNode->info = item;
	newNode->left = NULL;
	newNode->right = NULL;

	if (root == NULL)
		root = newNode;
	else
	{
		current = root;

		while (current != NULL)
		{
			trailCurrent = current;

			if (current->info == item)
			{
				cout << "The insert item is already in the list -- ";
				cout << "duplicates are not allowed." << endl;
				return;
			}
			else
				if (current->info > item)
					current = current->left;
				else
					current = current->right;
		}//end while

		if (trailCurrent->info > item)
			trailCurrent->left = newNode;
		else
			trailCurrent->right = newNode;
	}
}
//this function only determines the node to be deleted
void binarySearchTreeType::remove(int item)
{
	nodeType* current;  //pointer to traverse the tree
	nodeType* trailCurrent; //pointer behind current

	if (root == NULL)
	{
		cout << "Cannot delete from the empty tree." << endl;
		return;
	}
	if (root->info == item)
	{
		deleteFromTree(root);
		return;
	}

	//if you get here, then the item to be deleted is not the root
	trailCurrent = root;

	if (root->info > item)
		current = root->left;
	else
		current = root->right;

	//search for the item to be deleted.
	while (current != NULL)
	{
		if (current->info == item)
			break;
		else
		{
			trailCurrent = current;
			if (current->info > item)
				current = current->left;
			else
				current = current->right;
		}
	}// once the while is done, current points to either NULL or to the node to be deleted

	if (current == NULL)
		cout << "The delete item is not in the tree." << endl;
	else if (trailCurrent->info > item)
		deleteFromTree(trailCurrent->left);
	else
		deleteFromTree(trailCurrent->right);
}

void binarySearchTreeType::deleteFromTree(nodeType*& node)
{
	nodeType* current;    //pointer to traverse 
									//the tree
	nodeType* trailCurrent;   //pointer behind current
	nodeType* temp;        //pointer to delete the node

	if (node->left == NULL && node->right == NULL)
	{
		delete node;
		node = NULL;
	}
	else if (node->left == NULL)
	{
		temp = node;
		node = node->right;
		delete temp;
	}
	else if (node->right == NULL)
	{
		temp = node;
		node = node->left;
		delete temp;
	}
	else
	{
		current = node->left;
		trailCurrent = NULL;

		while (current->right != NULL)
		{
			trailCurrent = current;
			current = current->right;
		}//end while

		node->info = current->info;

		if (trailCurrent == NULL) //current did not move; 					 
			node->left = current->left;//current == p->left; adjust p
		else
			trailCurrent->right = current->left;

		delete current;
	}//end else
}