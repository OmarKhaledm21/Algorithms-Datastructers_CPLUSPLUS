#pragma once
#include "LinkedList.h"

template<class t>
class orderedList : public LinkedList<t>
{
private:
	using LinkedList<t>::head;
	using LinkedList<t>::tail;
	using LinkedList<t>::count;
public:
	void deleteNode(const t& deleteItem);
	void insert(const t& newItem);
	void insertFirst(const t& newItem);
	void insertLast(const t& newItem);
	bool search(const t& searchItem) const;
};

template<class t>
bool orderedList<t>::search(const t& searchItem)const {
	bool found = false;
	node<t>* current;
	current = head;
	while (current != NULL && !found) {
		if (current->info == searchItem) {
			found = true;
		}
		else {
			current = current->link;
		}
	}
	if (found) {
		found = (current->info == searchItem);
	}
	return found;
}

template<class t>
void orderedList<t>::insert(const t& newItem) {
	node<t>* current=NULL;
	node<t>* newNode;
	node<t>* trailCurrent=NULL;
	bool found;
	newNode = new node<t>;
	newNode->info = newItem;
	newNode->link = NULL;
	if (head == NULL) {
		head = newNode;
		tail = newNode;
		count++;
	}
	else{
		current = head;
		found = false;
		while (current!=NULL && !found) {
			if (current->info > newItem) {
				found = true;
			}
			else {
				trailCurrent = current;
				current = current->link;
			}
		}
		if (current == head) {
			newNode->link = head;
			head = newNode;
			count++;
		}
		else {
			trailCurrent->link = newNode;
			newNode->link = current;
			if (current == NULL) {
				tail = newNode;
			}
			count++;
		}
	}
}

template<class t>
void orderedList<t>::insertFirst(const t& newItem) {
	insert(newItem);
}

template<class t>
void orderedList<t>::insertLast(const t& newItem) {
	insert(newItem);
}

template <class t>
void orderedList<t>::deleteNode(const t& deleteItem)
{
	node<t>* current=NULL; 
	node<t>* trailCurrent=NULL; 
	bool found;
	if (head == NULL) { //Case 1
		cout << "Cannot delete from an empty list." << endl;
	}
	else{
		current = head;
		found = false;
		while (current != NULL && !found) { //search the list
			if (current->info >= deleteItem)
				found = true;
			else
			{
				trailCurrent = current;
				current = current->link;
			}
		}
		if (current == NULL) {
			cout << "Not found!" << endl;
		}
		else {
			if (current->info == deleteItem) {
				if (head == current) //Case 2
				{
					head = head->link;
					if (head == NULL)
						tail = NULL;
					delete current;
				}
				else //Case 3
				{
					trailCurrent->link = current->link;
					if (current == tail)
						tail = trailCurrent;
					delete current;
				}
				count--;
			}
			else //Case 4
				cout << "The item to be deleted is not in the "
				<< "list." << endl;
		}
	}
}