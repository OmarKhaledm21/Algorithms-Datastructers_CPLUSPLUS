//
// Created by Omar on 11/14/2021.
//

#ifndef ADVANCED_DATASTRUCTURES_TRIES_H
#define ADVANCED_DATASTRUCTURES_TRIES_H
#include <iostream>

using namespace std;

const int ALPHABET_SIZE = 26;
//Insert and search costs O(key_length).
//Space cost O(ALPHABET_SIZE * key_length * N) N is number of keys in trie.
struct node{
    bool wordEnd;
    node* children[ALPHABET_SIZE];
};

class Tries {
public:
    node *root;
    Tries(){
        root = getNode();
    }

    node* getNode()
    {
        node *newNode =  new node;
        newNode->wordEnd = false;

        for (int i = 0; i < ALPHABET_SIZE; i++) {
            newNode->children[i] = nullptr;
        }

        return newNode;
    }

    void insert(string key)
    {
        node *curr = root;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';

            if (!curr->children[index]) {
                curr->children[index] = getNode();
            }

            curr = curr->children[index];
        }

        // mark last node as leaf
        curr->wordEnd = true;
    }

    bool search(string key)
    {
        node *curr = root;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!curr->children[index]) {
                return false;
            }
            curr = curr->children[index];
        }

        return (curr->wordEnd);
    }
};


#endif //ADVANCED_DATASTRUCTURES_TRIES_H
