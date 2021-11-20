#pragma once
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct node {
    int info;
    int height;
    node* right;
    node* left;
};

class AVL
{
public:
    node* root;

    AVL() {
        this->root = NULL;
    }

    int getHeight(node* p) {

        if (p->left && p->right) {
            if (p->left->height < p->right->height)
                return p->right->height + 1;
            else return  p->left->height + 1;
        }
        else if (p->left && p->right == NULL) {
            return p->left->height + 1;
        }
        else if (p->left == NULL && p->right) {
            return p->right->height + 1;
        }
        return 0;

    }

    int getBalanceFactor(node* n) {
        if (n->left && n->right) {
            return n->left->height - n->right->height;
        }
        else if (n->left && n->right == NULL) {
            return n->left->height;
        }
        else if (n->left == NULL && n->right) {
            return -n->right->height;
        }
    }

    node* LeftLeftRotation(node* n) {
        node* p;
        node* tp;
        p = n;
        tp = p->left;

        p->left = tp->right;
        tp->right = p;

        return tp;
    }


    node* RightRightRotation(node* n) {
        struct node* p;
        struct node* tp;
        p = n;
        tp = p->right;

        p->right = tp->left;
        tp->left = p;

        return tp;
    }


    node* RightLeftRotation(node* n) {
        node* p;
        node* tp;
        node* tp2;
        p = n;
        tp = p->right;
        tp2 = p->right->left;

        p->right = tp2->left;
        tp->left = tp2->right;
        tp2->left = p;
        tp2->right = tp;

        return tp2;
    }

    node* LeftRightRotation(node* n) {
        node* p;
        node* tp;
        node* tp2;
        p = n;
        tp = p->left;
        tp2 = p->left->right;

        p->left = tp2->right;
        tp->right = tp2->left;
        tp2->right = p;
        tp2->left = tp;

        return tp2;
    }

    node* insert(node* root, int data) {

        if (root == NULL) {
            node* n;
            n = new node;
            n->info = data;
            root = n;
            root->left = root->right = NULL;
            root->height = 1;
            return root;
        }
        else {
            if (data < root->info)
                root->left = insert(root->left, data);
            else
                root->right = insert(root->right, data);
        }

        root->height = getHeight(root);

        if (getBalanceFactor(root) == 2 && getBalanceFactor(root->left) == 1) {
            root = LeftLeftRotation(root);
        }
        else if (getBalanceFactor(root) == -2 && getBalanceFactor(root->right) == -1) {
            root = RightRightRotation(root);
        }
        else if (getBalanceFactor(root) == -2 && getBalanceFactor(root->right) == 1) {
            root = RightLeftRotation(root);
        }
        else if (getBalanceFactor(root) == 2 && getBalanceFactor(root->left) == -1) {
            root = LeftRightRotation(root);
        }

        return root;

    }

    void levelOrder() {
        if (this->root == NULL) {
            cout << "\n" << "Empty tree" << "\n";
            return;
        }
        levelOrder(this->root);
    }

    void levelOrder(node* v) {
        queue <node*> q;
        node* cur;
        q.push(v);
        q.push(NULL);

        while (!q.empty()) {
            cur = q.front();
            q.pop();
            if (cur == NULL && q.size() != 0) {
                cout << "\n";

                q.push(NULL);
                continue;
            }
            if (cur != NULL) {
                cout << " " << cur->info;

                if (cur->left != NULL) {
                    q.push(cur->left);
                }
                if (cur->right != NULL) {
                    q.push(cur->right);
                }
            }


        }
    }

    node* deleteNode(node* p, int data) {

        if (p->left == NULL && p->right == NULL) {
            if (p == this->root)
                this->root = NULL;
            delete p;
            return NULL;
        }

        node* t;
        node* q;
        if (p->info < data) {
            p->right = deleteNode(p->right, data);
        }
        else if (p->info > data) {
            p->left = deleteNode(p->left, data);
        }
        else {
            if (p->left != NULL) {
                q = Predecessor(p->left);
                p->info = q->info;
                p->left = deleteNode(p->left, q->info);
            }
            else {
                q = Successor(p->right);
                p->info = q->info;
                p->right = deleteNode(p->right, q->info);
            }
        }

        if (getBalanceFactor(p) == 2 && getBalanceFactor(p->left) == 1) { p = LeftLeftRotation(p); }
        else if (getBalanceFactor(p) == 2 && getBalanceFactor(p->left) == -1) { p = LeftRightRotation(p); }
        else if (getBalanceFactor(p) == 2 && getBalanceFactor(p->left) == 0) { p = LeftLeftRotation(p); }
        else if (getBalanceFactor(p) == -2 && getBalanceFactor(p->right) == -1) { p = RightRightRotation(p); }
        else if (getBalanceFactor(p) == -2 && getBalanceFactor(p->right) == 1) { p = RightLeftRotation(p); }
        else if (getBalanceFactor(p) == -2 && getBalanceFactor(p->right) == 0) { p = LeftLeftRotation(p); }


        return p;
    }

    node* Predecessor(node* p) {
        while (p->right != NULL) {
            p = p->right;
        }
        return p;
    }

    node* Successor(node* p) {
        while (p->left != NULL) {
            p = p->left;
        }
        return p;
    }

    void clearTree()
    {
        clear(root);
    }

    void clear(node*& p)
    {
        if (p != NULL)
        {
            clear(p->left);
            clear(p->right);
            delete p;
            p = NULL;
        }
    }

    ~AVL() { clearTree(); }
};
