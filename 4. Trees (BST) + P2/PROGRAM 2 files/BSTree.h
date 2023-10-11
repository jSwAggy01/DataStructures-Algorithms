#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include "Node.h"

using namespace std;

class BSTree {
   private:
        TreeNode *root;
   public:
        /* Constructors */

        /* Default constructor */
        BSTree();

        /* Destructor */
        ~BSTree();
   private:
        void DestroyRecursive(TreeNode *node);  // Extension of destructor
   public:
        /* Mutators */

        /* Insert an item into the binary search tree. 
           Be sure to keep BST properties. 
           When an item is first inserted into the tree the count should be set to 1. 
           When adding a duplicate string (case sensitive), rather than adding another node, 
           the count variable should be incremented 
         */
        void insert(const string &newString);
        
        /* Remove a specified string from the tree. 
           Be sure to maintain all bianry search tree properties. 
           If removing a node with a count greater than 1, just decrement the count, otherwise, 
           if the count is simply 1, remove the node. 
            You MUST follow the remove algorithm shown in the slides and discussed in class or else 
            your program will not pass the test functions. 
            When removing, 
                if removing a leaf node, simply remove the leaf. Otherwise, 
                if the node to remove has a left child, replace the node to remove with the largest 
                string value that is smaller than the current string to remove 
                (i.e. find the largest value in the left subtree of the node to remove). 
                If the node has no left child, replace the node to remove with the smallest value 
                larger than the current string to remove 
                (i.e. find the smallest value in the right subtree of the node to remove. 
         */
        void remove(const string &key);   // Must be recursive

        /* Accessors */

        /* [Recursive] search for a string in the binary search tree. 
           It should return true if the string is in the tree, and false otherwise. 
         
           I reclassified this as the helper function :) 
         */
        bool search(const string &key) const;

        /* Helper function for returning the node that matches the key */
        TreeNode* getNode(const string &key) const;
        
        /* Find and return the largest value in the tree. Return an empty string if the tree is empty */
        string largest() const;
        
        /* Find and return the smallest value in the tree. Return an emtpy string if the tree is empty */
        string smallest() const;

        /* Compute and return the height of a particular string in the tree. 
           The height of a leaf node is 0 (count the number of edges on the longest path). 
           Return -1 if the string does not exist. 
         */
        int height(const string &key) const;

        /* UTILITY - Returns parent node of specified node */
        TreeNode* getParent(TreeNode *node);

        /* Printing */
        
        /* For all printing orders, each node should be displayed as follows:
           <string> (<count>)
           e.g. goodbye(1), Hello World(3)
           */
        void preOrder() const;
        void postOrder() const;     // Helperss
        void inOrder() const;
   private:
        void preOrder(TreeNode*) const;
        void postOrder(TreeNode*) const;  // All must be recursive
        void inOrder(TreeNode*) const;    

        /* Inserts a new node */
        void insert(TreeNode *parent, TreeNode *nodeToInsert);
        
        /* [Recursive] search for a string in the binary search tree. 
           It should return true if the string is in the tree, and false otherwise. 
         */
        bool search(TreeNode *node, const string &key) const;

        /* Removes the specified node */
        void remove(TreeNode *parent, TreeNode *node, const string &key);

        /* Returns the node that matches the key passed in */
        TreeNode* getNode(TreeNode *node, const string &key) const;

        /* UTILITY - Replaces the child of a parent node */
        bool ReplaceChild(TreeNode *parent, TreeNode *currChild, TreeNode *newChild);

        /* UTILITY - Returns the parent node of the specified node */
        TreeNode* getParent(TreeNode *subTreeRoot, TreeNode *node);

        /* Returns height of a given string */
        int height(TreeNode *node) const;
};

#endif