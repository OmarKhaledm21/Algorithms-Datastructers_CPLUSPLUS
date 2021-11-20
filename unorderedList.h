#pragma once
#include "LinkedList.h"


template<class t>
class unorderedList : public LinkedList<t>
{
private:
	using LinkedList<t>::head;
	using LinkedList<t>::tail;
	using LinkedList<t>::count;

public:
	
	void deleteNode(const t& deleteItem) {
		node<t>* current=NULL;
		node<t>* trailCurrent=NULL;
		bool found;
		if (head == NULL) {
			cout << "List is empty" << endl;
		}
		else {
			found = false;
			trailCurrent = head;
			current = head->link;
		}
		while (current != NULL && !found)
		{
			if (current->info != deleteItem)
			{
				trailCurrent = current;
				current = current->link;
			}
			else {
				found = true;
			}
		}
		if (found == true) {
			trailCurrent->link = current->link;
			count--;
			if (tail == current) {
				tail = trailCurrent;
			}
			delete current;
		}
		else if (found == false) {
			cout << "Item is not found!" << endl;
		}
	}
	virtual bool search(const t& searchItem)const {
		node<t>* current;
		bool found = false;
		current = head;
		while (current != NULL && !found) {
			if (current->info == searchItem) {
				found = true;
			}
			else {
				current = current->link;
			}
		}
		return found;
	}
	virtual void insertFirst(const t& newItem) {
		node<t>* newNode;
		newNode = new node<t>;
		newNode->info = newItem;
		newNode->link = head;
		head = newNode;
		count++;
		if (tail == NULL)
			tail = newNode;
	}
	virtual void insertLast(const t& newItem) {
		node<t>* newNode = new node<t>;
		newNode->info = newItem;
		newNode->link = NULL;
		if (head == NULL) {
			head = newNode;
			tail = newNode;
			count++;
		}
		else {
			tail->link = newNode;
			tail = newNode;
			count++;
		}
	}
};

