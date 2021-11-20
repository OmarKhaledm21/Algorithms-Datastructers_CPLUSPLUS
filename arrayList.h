#pragma once
#include <iostream>
using namespace std;

class arrayList
{
private:
	int* arr;
	int size;
	int count;
	int head, tail;
public:
	arrayList(int size=100) {
		this->size = size;
		count = 0;
		arr = new int[size];
		for (int i = 0; i < size; i++)
			arr[i] = 0;
	}
	void push_back(int ele) {
		if (count < size) {
			arr[count++] = ele;
		}
		else {
			cout << "List is full\n";
		}
	}
	void pop_back() {
		count--;
	}
	int getSize() {
		return count;
	}
	int isEmpty() {
		return count == 0;
	}
	bool search(int item) {
		for (int i = 0; i < count; i++) {
			if (arr[i] == item) {
				return true;
			}
		}
		return false;
	}
};

