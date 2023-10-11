#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>

#include "Node.h"

class AVLTree {
    public:
        AVLTree();
        Node* root;
        Node* findUnbalancedNode(const string& key);
        void insert(Node* node, const string& key);
        void visualizeTree(ofstream &, Node* node);
        void updateHeight(Node* node);
        void printBalanceFactors(Node* node);
        void setChildRight(Node* node, Node* child);
        void setChildLeft(Node* node, Node* child);
        void rotateLeft(Node* node);
        void rotateRight(Node* node);
        void rotate(Node* node, const string& key);
        int balanceFactor(Node* node);
	    int getMax(int a, int b);
        void insert(const string& key);
        void printBalanceFactors();
        void visualizeTree(const string& key);
        void printPreOrder(Node *node);
};
#endif