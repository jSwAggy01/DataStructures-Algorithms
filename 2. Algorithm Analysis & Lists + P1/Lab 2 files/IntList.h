#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>

using namespace std;

struct IntNode { // node struct, this encapsulates node obejects
    int data;
    IntNode *prev;
    IntNode *next;
    IntNode(int data) : data(data), prev(0), next(0) {} // node object constructor with initalization list
};

class IntList { // list class, list objects work with and manipulate node objects; they are not the same thing
public:
    IntList();
    ~IntList();
    void push_front(int value);
    void pop_front();
    void push_back(int value);
    void pop_back();
    bool empty() const;
    void printReverse();

    // use to print the list object's node data
    friend ostream & operator<<(ostream &out, const IntList& rhs);

private:
    IntNode* dummyHead;
    IntNode* dummyTail;
};


#endif