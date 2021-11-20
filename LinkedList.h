#pragma once
#include <iostream>
using namespace std;

template<class t>
struct node {
    t info;
    node* link;
};


template<class t>
class Iterator {
private:
    node<t>* current;
public:
    Iterator() {
        current = nullptr;
    }
    Iterator(node<t>* ptr) {
        current = ptr;
    }
    t operator*() {
        return current->info;
    }
    void operator++() {
        current = current->link;
    }
    bool operator==(const Iterator<t>& right)const {
        return (current == right.current);
    }
    bool operator!=(const Iterator<t>& right)const {
        return (current != right.current);
    }
};

template<typename t>
class LinkedList {
public:
    int count;
    node<t>* head;
    node<t>* tail;
public:
    LinkedList<t>() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    LinkedList<t>(const LinkedList<t>& otherList) {
        copyList(otherList);
    }
    const LinkedList<t>& operator=(const LinkedList<t>& otherList) {
        if (this != &otherList) //avoid self-copy
        {
            copyList(otherList);
        }//end else
        return *this;
    }
    void initializeList() {
        destroyList();
    }
    bool isEmpty()const {
        return head == nullptr;
    }
    void print()const {
        node<t>* current = head;
        while (current != nullptr) {
            cout << current->info << " ";
            current = current->link;
        }
    }
    int length()const {
        return count;
    }
    void destroyList() {
        node<t>* temp;
        while (head != nullptr) {
            temp = head;
            head = head->link;
            delete temp;
        }
        tail = nullptr;
        count = 0;
    }
    t front()const {
        if (head != nullptr) { return head->info; }
        else { return NULL; }
    }
    t back()const {
        if (tail != nullptr) { return tail->info; }
        else { return NULL; }
    }
    virtual bool search(const t& searchItem)const=0;
    virtual void insertFirst(const t& newItem) = 0;
    virtual void insertLast(const t& newItem) = 0;
    virtual void deleteNode(const t& deleteItem) = 0;
    
    Iterator<t>begin() {
        Iterator<t> temp(head);
        return temp;
    }

    Iterator<t>end() {
        Iterator<t> temp(nullptr);
        return temp;
    }
    ~LinkedList() { destroyList(); }
private:
    void copyList(const LinkedList<t>& otherList) {
        node<t>* newNode;
        node<t>* current;
        if (head != nullptr) {
            destroyList();
        }
        if (otherList.head == nullptr) {
            head = nullptr;
            tail = nullptr;
            count = 0;
        }
        else {
            current = otherList.head;

            count = otherList.count;

            head = new node<t>;
            head->info = current->info;
            head->link = NULL;
            tail = head;
            current = current->link;
            while (current != NULL)
            {
                newNode = new node<t>;
                newNode->info = current->info;
                newNode->link = NULL;
                tail->link = newNode;
                tail = newNode;
                current = current->link;
            }
        }

    }
};

