#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;

// struct TreeNode {
//     string text;
//     int val;
//     TreeNode *right;
//     TreeNode *left;
//     TreeNode(int value) : text(text), val(val), right(nullptr), left(nullptr) {}
// };

class TreeNode {
    public:
        int count;
        string key;
        TreeNode *left;
        TreeNode *right;
        TreeNode *parent;
        TreeNode(int count, string key) : count(count), key(key), left(nullptr), right(nullptr), parent(nullptr) {}
        bool isLeaf();
};

#endif