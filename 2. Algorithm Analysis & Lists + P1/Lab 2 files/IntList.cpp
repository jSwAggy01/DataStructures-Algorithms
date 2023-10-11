#include "IntList.h"
#include <iostream>

using namespace std;


IntList::IntList() {
    // these nodes actually need to be allocated
    dummyHead = new IntNode(0); // these node pointers have no data, all they should do is point to the list's actual head and tail
    dummyTail = new IntNode(0); // data here is null
    
    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;

}

IntList::~IntList() { // deleting a list means going through and deleting all of its nodes
    IntNode* nextNode;
    IntNode* currentNode = dummyHead->next; // dummyHead->next points to the actual list head

    while (currentNode->next != 0) { // runs till traversal reaches the tail
        nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }

    // still need to delete dummy nodes
    delete dummyHead;
    delete dummyTail;

}


void IntList::push_front(int value) {
    IntNode* current = new IntNode(value);

    //cout << "push_front(" << current->data << ")" << endl;
    
    current->prev = dummyHead; // current previous pointer needs to point to dummyHead
    current->next = dummyHead->next; // current next pointer needs to point to the former head (dummyHead->next) *head to be replaced, I guess

    dummyHead->next->prev = current; // former head (head->next) previous pointer needs to point to the new node
    dummyHead->next = current; // dummyHead is updated to point to the prepended current node

}

void IntList::pop_front() {
    IntNode* temp;  // toDelete
    if (dummyTail->prev == 0) {
        // if the list is already empty, do nothing
    }
    
    else {
        temp = dummyTail->prev;
        dummyTail->prev = dummyTail->prev->prev; // the new tail node is whatever preceded the former tail
        dummyTail->prev->next = dummyTail;
        delete temp;
    }
}



void IntList::push_back(int value) {
    IntNode* current = new IntNode(value);

    //cout << "push_back(" << current->data << ")" << endl;

    current->next = dummyTail;
    current->prev = dummyTail->prev; // current prev now points to old tail

    dummyTail->prev->next = current;
    dummyTail->prev = current; 

}

void IntList::pop_back() {
    IntNode* temp;  // toDelete
    if (dummyHead->next == 0) {
        // if the list is already empty, do nothing
    }

    else {
        // cout << "FIXME: " << dummyHead->next->data << endl;
        temp = dummyHead->next;
        dummyHead->next = dummyHead->next->next;
        dummyHead->next->prev = dummyHead;
        delete temp;
    }
}

bool IntList::empty() const{
    if (dummyHead->next == dummyTail || dummyTail->prev == dummyHead) { // the list is empty if dummyHead and dummyTail point to eachother
        return true;
    }

    else {
        return false;
    }
}


void IntList::printReverse() {
    IntNode* currentTail = dummyTail->prev; // current begins at the list's tail

    while (currentTail->prev != 0) {
        if (currentTail->prev->prev == 0) { // checks for last node, if currentTail is last node, don't print the extra space
            cout << currentTail->data;
        }
        
        else {
            cout << currentTail->data << " ";

        }

        currentTail = currentTail->prev;
    }
    

}

ostream & operator<<(ostream &out, const IntList& rhs) { // out is the name of the output stream passed in, update and return out
    IntNode* current = rhs.dummyHead->next; // current starts at the actual list head
    
    while (current->next != 0) {
        if (current->next->next == 0) {
            out << current->data;
        }

        else {
            out << current->data << " ";
        }

        current = current->next;

    }
    return out;
}


// Implmenting
/*
    IntList(); // done, tested, working
    ~IntList();  // done, tested, working
    void push_front(int value); // done, tested, working
    void pop_front(); //
    void push_back(int value); // done, tested, working
    void pop_back(); //
    bool empty() const; // done, tested, working
    void printReverse(); // done, tested, working
    friend ostream & operator<<(ostream &out, const IntList& rhs); // done, tested, working
*/