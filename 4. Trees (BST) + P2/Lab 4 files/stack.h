#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

const int MAX_SIZE = 20; // Out here b/c I can't declare it in the class ¯\_(ツ)_/¯

/* DECLARATIONS */

template <typename T>
class stack {
    private:
        T data[MAX_SIZE];
        int size;
    public:
        stack();
        void push(T val);
        void pop();
        T top();
        bool empty();
};

/* DEFINITIONS */

/* constructs an empty stack. */
template<typename T>
stack<T>::stack() {
    size = 0;
}

/*  inserts a new element (val) of type T (T could be integer or string) into the data. If the data array is full,
    this function should throw an overflow_error exception with error message "Called push on full stack.". */
template<typename T>
void stack<T>::push(T val) {
    if (size == MAX_SIZE) {
        throw overflow_error("Called push on full stack.");
    }
    else {
        data[size] = val;
        // cout << "\nFIXME: size: " << size << endl;
        // cout << "FIXME: data: " << data[size] << endl;
        ++size;
    }
}

/*  removes the last element from data. If the data array is empty, this function should throw an outofrange exception
    with error message "Called pop on empty stack.". */
template<typename T>
void stack<T>::pop() {
    if (size == 0) {
        throw out_of_range("Called pop on empty stack.");
    }
    else {
        --size;
    }
}

/*  returns the top element of stack (last inserted element). If stack is empty, this function should throw an underflow_error
    exception with error message "Called top on empty stack.". */
template<typename T>
T stack<T>::top() {
    if (size == 0) {
        throw underflow_error("Called top on empty stack.");
    }
    return data[size - 1];
}

/* returns true if the stack is empty otherwise it returns false. */
template<typename T>
bool stack<T>::empty() {
    if (size == 0) {
        return true;
    }
    return false;
}

#endif