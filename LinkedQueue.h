#pragma once
#include <iostream>
#include <cassert>
using namespace std;
template<class t>
class linkedQueue
{
private:
	struct Node
	{
		t item;
		Node* next;
	};
	int length;
	Node* frontPtr, *rearPtr;

public:

	linkedQueue() :frontPtr(NULL), rearPtr(NULL), length(0){}

	bool isEmpty()
	{
		return (length == 0);
	}

	void dequeue()
	{
		if (isEmpty())
			cout << "Empty Queue" << endl;
		else if (length == 1)
		{
			delete frontPtr;
			frontPtr = NULL;
			rearPtr = NULL;
			length = 0;
		}
		else
		{
			Node* current = frontPtr;
			frontPtr = frontPtr->next;
			delete current;
			length--;
		}
	}

	void enqueue(t item)
	{
		Node* newNode = new Node;
		newNode->item = item;
		newNode->next = NULL;

		if (length == 0)
			rearPtr = frontPtr = newNode;
		else
		{
			rearPtr->next = newNode;
			rearPtr = newNode;
		}
		length++;
	}

	t front()
	{
		assert(!isEmpty());
		return frontPtr->item;
	}

	t rear()
	{
		assert(!isEmpty());
		return rearPtr->item;
	}

	void clearQueue()
	{
		Node* current;

		while (frontPtr != NULL)
		{
			current = frontPtr;
			frontPtr = frontPtr->next;
			delete current;
		}
		rearPtr = NULL;
		length = 0;
	}

	void display()
	{
		Node* cur = frontPtr;
		cout << "Item in the queue :[ ";
		while (cur != NULL)
		{
			cout << cur->item << " ";
			cur = cur->next;
		}
		cout << "]" << endl;
	}

	void search(t item)
	{
		Node* cur = frontPtr;
		bool flag = true;
		while (cur != NULL)
		{
			if (cur->item == item)
			{
				cout << "the item :" << item << " found" << endl;
				flag = false;
				break;
			}
			cur = cur->next;
		}
		if (flag)
			cout << "the item : " << item << " not found" << endl;

	}
};