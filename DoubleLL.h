#pragma once
#include <iostream>
using namespace std;
template<class t>
struct node
{
	node<t>* next;
	node<t>* back;
	t info;
};

template<class t>
class DoubleLL
{
protected:
	int count;
	node<t>* first; 
	node<t>* last; 
public:
	DoubleLL<t>() {
		first = NULL;
		last = NULL;
		count = 0;
	};
	void initializeList() {
		destroy();
	};
	bool isEmptyList() const {
		return first==NULL;
	};
	void destroy() {
		node<t>* temp;
		while (first != NULL) {
			temp = first;
			first = first->next;
			delete temp;
		}
		last = NULL;
		count = 0;
	};
	void print() const {
		node<t>* cur;
		cur = first;
		while (cur != NULL) {
			cout << cur->info << " ";
			cur = cur->next;
		}
	};
	void reversePrint() const {
		node<t>* cur;
		cur = last;
		while (cur != NULL) {
			cout << cur->info << " ";
			cur = cur->back;
		}
	}

	void addToHead(t info) {
		node<t>* newNode = new node<t>;
		newNode->info = info;
		newNode->next = newNode->back = nullptr;
		if (first == nullptr) {
			first = last = newNode;
		}
		else {
			newNode->next = first;
			first->back = newNode;
			first = newNode;
		}
		count++;
	}
	void addToTail(t info) {
		node<t>* newNode = new node<t>;
		newNode->info = info;
		newNode->next = nullptr;
		newNode->back = nullptr;
		if (first == nullptr) {
			first = last = newNode;
		}
		else {
			newNode->back = last;
			last->next = newNode;
			last = newNode;
		}
		count++;
	}
	void recReversePrint(node<t>* cur)const {
		if (cur != NULL) {
			recReversePrint(cur->next);
			cout << cur->info << "*";
		}
	}

	node<t>* getLast() {
		return last;
	}
	node<t>* getFirst() {
		return first;
	}

	int length() const {
		return count;
	};
	t front() const {
		if (first == NULL) { return; }
		return first->info;
	};
	t back() const {
		if (first == NULL) {
			return;
		}
		else {
			return last->info;
		}
	};
	bool search(const t& searchItem) const {
		node<t>* cur;
		cur = first;
		bool found = false;
		while (cur != NULL && !found) {
			if (cur->info >= searchItem) {
				found = true;
			}
			else {
				cur = cur->next;
			}
		}
		if (found) { found = (cur->info == searchItem); }
		return found;
	};
	void insert(const t& insertItem) {
		/*
			Case 1: Insertion in an empty list
			Case 2: Insertion at the beginning of a nonempty list
			Case 3: Insertion at the end of a nonempty list
			Case 4: Insertion somewhere in a nonempty list
		*/
		node<t>* cur;
		node<t>* trailCur=NULL;
		node<t>* newNode;
		bool found;
		newNode = new node<t>;
		newNode->info = insertItem;
		newNode->next = NULL;
		newNode-> back = NULL;
		if (first==NULL) {
			first = newNode;
			last = newNode;
			count++;
		}
		else {
			found = false;
			cur = first;
			while (cur != NULL && !found) {
				if (cur->info >= insertItem) {
					found = true;
				}
				else {
					trailCur = cur;
					cur = cur->next;
				}
			}
			if (cur == first) {
				first->back = newNode;
				newNode->next = first;
				first = newNode;
				count++;
			}
			else {
				if (cur != NULL) {
					trailCur->next = newNode;
					newNode->back = trailCur;
					newNode->next = cur;
					cur->back = newNode;
				}
				else {
					trailCur->next = newNode;
					newNode->back = trailCur;
					last = newNode;
				}
				count++;
			}
		}
	}
	void deleteNode(const t& deleteItem) {
		node<t>* cur;
		node<t>* trailCur;
		bool found;
		if (first == NULL) {
			cout << "List is empty\n";
		}
		else if (first->info == deleteItem) {
			cur = first;
			first = first->next;
			if (first != NULL) {
				first->back = NULL;
			}
			else {
				last = NULL;
			}
			count--;
			delete cur;
		}
		else {
			found = false;
			cur = first;
			while (cur != NULL && !found) {
				if (cur->info >= deleteItem) {
					found = true;
				}
				else {
					cur = cur->next;
				}
			}
			if (cur==NULL) {
				cout << "item not found!\n";
			}
			else if (cur->info == deleteItem) {
				trailCur = cur->back;
				trailCur->next = cur->next;
				if (cur->next !=NULL) {
					cur->next->back = trailCur;
				}
				if (cur=last) {
					last = trailCur;
				}
				count--;
				delete cur;
			}
			else {
				cout << "item not found\n";
			}
		}
	}
	~DoubleLL() {
		destroy();
	};
};



