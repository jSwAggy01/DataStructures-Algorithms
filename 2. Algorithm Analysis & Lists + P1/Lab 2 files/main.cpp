// Collaborated with demo partner Julian - jdela055@ucr.edu
#include "IntList.h"
#include <iostream>

using namespace std;


int main() {

    cout << endl << endl;

    // ### frontList test ###
    IntList* frontList = new IntList();
    cout << "Testing push_front()...\n\n";
    frontList->push_front(1);
    frontList->push_front(2);
    frontList->push_front(3);
    frontList->push_front(4);
    frontList->push_front(5);
    cout << endl;

    cout << "Testing overloaded function..." << endl;
    cout << *frontList;
    cout << endl << endl;

    cout << "Testing printReverse()...\n\n";
    
    frontList->printReverse();
    cout << endl;
    cout << endl;

    cout << "Testing pop_front()...\n\n";

    frontList->pop_front();

    frontList->printReverse();
    cout << endl << endl;

    cout << "Testing pop_back()" << endl;

    frontList->pop_back();

    frontList->printReverse();
    cout << endl << endl;

    cout << "Deleting list...";
    delete frontList;

    cout << "Testing push_back()...\n\n";
    frontList->push_back(1);
    frontList->push_back(2);
    frontList->push_back(3);
    frontList->push_back(4);
    frontList->push_back(5);
    cout << *frontList << "\n\n";

    /*
    // ### backList test ###
    IntList* backList= new IntList();
    cout << "Testing push_back()...\n\n"; 
    backList->push_back(1);
    backList->push_back(2);
    backList->push_back(3);
    backList->push_back(4);
    backList->push_back(5);


    cout << "Testing printReverse()...\n\n";
    
    backList->printReverse();
    cout << endl;
    cout << endl;


    cout << "Deleting list...";
    delete backList;
    */
    

    /*
    cout << "Testing push_front(1)" << endl;
    
    cout << "Testing x1" << endl;
    list->push_front(1); // push front is crashing the program
    cout << "Testing x2" << endl;
    */


    

    /*
    list->push_front(2);
    list->push_front(3);
    list->printReverse();
    */

    return 0;
}