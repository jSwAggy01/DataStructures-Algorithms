#ifndef NODE_H
#define NODE_H
#include<iostream>

using namespace std;

class Node{
	public:
		Node(string word);
		Node* left;
		Node* right;
		int height;
		int counter;
		Node* parent;
		string key;
};
#endif