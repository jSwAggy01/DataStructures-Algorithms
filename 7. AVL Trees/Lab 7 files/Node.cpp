#include <iostream>
#include <string>

#include "Node.h"

using namespace std;

Node::Node(string word){
	right = nullptr;
	left = nullptr;
	parent = nullptr;
	height = 0;
	key = word;
	counter = 1;
}

