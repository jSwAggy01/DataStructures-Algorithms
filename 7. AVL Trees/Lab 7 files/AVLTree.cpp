#include <iostream>
#include <fstream>
#include <string>
#include "AVLTree.h"

using namespace std;	

AVLTree::AVLTree(){
    root = nullptr;
}

int AVLTree::getMax(int a, int b){
    if(a > b){
        return a;
    }

    else{
        return b;
    }
}



void AVLTree::rotate(Node* node, const string& key) {

    updateHeight(node);
    Node * unbalNode = findUnbalancedNode(key);

    if (unbalNode != nullptr) {

        if (balanceFactor(unbalNode) == -2) {
            if (balanceFactor(unbalNode->right) == 1) {

                rotateRight(unbalNode->right);
            }

            rotateLeft(unbalNode);
        }
        else if (balanceFactor(unbalNode) == 2) {

            if (balanceFactor(unbalNode->left) == -1) {

                rotateLeft(unbalNode->left);
            }

            rotateRight(unbalNode);
        }
    }

}

void AVLTree::insert(const string& key) {

    if (root == nullptr) {
        root = new Node(key);
    }

    else {
        insert(root, key);
    }
}


void AVLTree::insert(Node* node, const string& key) {

    if (key < node->key) {

        if (node->left != nullptr) {

            insert(node->left, key);
        }

        else {
            node->left = new Node(key);
            node->left->parent = node;
            rotate(node->left, key);
        }
    }

    else if (key > node->key) {

        if (node->right != nullptr) {

            insert(node->right, key);
        }

        else {
            node->right = new Node(key);
            node->right->parent = node;
            rotate(node->right, key);
        }
    }
    printPreOrder(root);
}

void AVLTree::updateHeight(Node* node) {

    int Lheight = -1;
    int Rheight = -1;

    int max = 0;

    if (node->left != nullptr) {
        Lheight = node->left->height;
    }

    if (node->right != nullptr) {
        Rheight = node->right->height;
    }

    max = getMax(Lheight, Rheight);
    node->height = max + 1;

    if (node->parent != nullptr) {
        updateHeight(node->parent);
    }
}


int AVLTree::balanceFactor(Node* node) {

    int Lheight = -1;
    int Rheight = -1;

    if (node->left != nullptr) {
        Lheight = node->left->height;
    }

    if (node->right != nullptr) {
        Rheight = node->right->height;
    }

    return Lheight - Rheight;
}


void AVLTree::printBalanceFactors() {
    if (root != nullptr) {
        printBalanceFactors(root);
    }

    cout << endl;
}


void AVLTree::printBalanceFactors(Node *node) {
    if (node != nullptr) {
        printBalanceFactors(node->left);
        cout << node->key << "(" << balanceFactor(node) << "), ";
        printBalanceFactors(node->right);
    }
}

void AVLTree::printPreOrder(Node *node) {
    if (node != nullptr) {
        cout << node->key << "(" << balanceFactor(node) << "), ";
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}


Node* AVLTree::findUnbalancedNode(const string & key) {

    Node* unbalNode = nullptr;
    Node* curr = root;

    while (curr->key != key) { 
    
        int balance = balanceFactor(curr);
        string key1 = curr->key;

        if (balance > 1 || balance < -1) {
            unbalNode = curr;
        }

        if (key1 < key) {
            curr = curr->right;
        }
        else if (key1 > key) {
            curr = curr->left;
        }
    }

    return unbalNode;
}


void AVLTree::setChildRight(Node* node, Node* child){
    node->right = child;

    if(child != nullptr){
        child->parent = node;
    }

    updateHeight(node);
}

void AVLTree::setChildLeft(Node* node, Node* child){
    node->left = child;

    if(child != nullptr){
        child->parent = node;
    }

    updateHeight(node);
}


void AVLTree::rotateLeft(Node *node) {

    Node* RLChild = node->right->left;

    if (node->parent != nullptr) {
    
        if(node->parent->left == node){
            setChildLeft(node->parent,node->right);
        }

        else if(node->parent->right == node){
            setChildRight(node->parent, node->right);
        }
    }
    else { 
        root = node->right;
        root->parent = nullptr;
    }

    setChildLeft(node->right, node);
    setChildRight(node, RLChild);
    
}


void AVLTree::rotateRight(Node *node) {

    Node* LRChild = node->left->right;

    if (node->parent != nullptr) {
        
        if(node->parent->left == node){
            setChildLeft(node->parent, node->left);
        }

        else if(node->parent->right == node){
            setChildRight(node->parent, node->left);
        }
    }

    else {
        root = node->left;
        root->parent = nullptr;
    }

    setChildRight(node->left, node);
    setChildLeft(node, LRChild);
    
    
}

















void AVLTree::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

void AVLTree::visualizeTree(ofstream & outFS, Node *n){
    if(n){
        if(n->left){
            visualizeTree(outFS,n->left);
            outFS<<n->key <<" -> " <<n->left->key<<";"<<endl;    
        }

        if(n->right){
            visualizeTree(outFS,n->right);
            outFS<<n->key <<" -> " <<n->right->key<<";"<<endl;    
        }
    }
}