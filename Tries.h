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

    void display(){
        int level = 0;
        char str[20];

        // Displaying content of Trie
        cout << "Content of Trie: " << endl;
        display(root, str, level);
    }

    void display(node* root, char str[], int level)
    {
        // If node is leaf node, it indicates end
        // of string, so a null character is added
        // and string is displayed
        if (root->wordEnd)
        {
            str[level] = '\0';
            cout << str << endl;
        }

        int i;
        for (i = 0; i < ALPHABET_SIZE; i++)
        {
            // if NON NULL child is found
            // add parent key to str and
            // call the display function recursively
            // for child node
            if (root->children[i])
            {
                str[level] = i + 'a';
                display(root->children[i], str, level + 1);
            }
        }
    }
};


#endif //ADVANCED_DATASTRUCTURES_TRIES_H
