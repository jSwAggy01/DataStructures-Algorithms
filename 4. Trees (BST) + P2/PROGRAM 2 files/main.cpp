// Collaborated with demo partner Peter Chu
// Help from former student - Yariazen
#include <iostream>
#include <limits>
#include "BSTree.h"

// Compile with: g++ Node.cpp main.cpp BSTree.cpp -Wall -Werror -Wuninitialized -o ./a.exe

using namespace std;

// int main() {

//   cout << "Beginning tests...\n";

//   cout << "Testing constructor, insert, search, getNode, remove\n" << endl;
//   {
//     cout << "Calling constructor" << endl;
//     BSTree tree;
//     cout << "insert" << endl;
//     tree.insert("Hello World");
//     cout << "insert" << endl;
//     tree.insert("Programmed");
//     cout << "insert" << endl;
//     tree.insert("To Think");
//     cout << "search 'Hello World'" << endl;
//     cout << "expected, 1" << endl;  // 1 means true/found
//     cout << "     got, " << tree.search("Hello World") << endl;
//     cout << "getNode 'Hello World'" << endl;
//     cout << "expected, Hello World" << endl;
//     cout << "     got, " << tree.getNode("Hello World")->key << endl;
//     cout << "getNode 'Programmed'" << endl;
//     cout << "expected, Programmed" << endl;
//     cout << "     got, " << tree.getNode("Programmed")->key << endl;
//     cout << "remove" << endl;
//     tree.remove("Hello World");
//     cout << "search" << endl;
//     cout << "expected, 0" << endl;  // 0 means false, not found
//     cout << "     got, " << tree.search("Hello World") << endl;
//     cout << endl;
//     cout << "Calling destructor" << endl;
//   }
//   cout << "Destructor returned\n" << endl;

  // cout << "Testing largest, smallest, height, inOrder\n" << endl;
  // {
  //   cout << "Calling constructor" << endl;
  //   BSTree tree;
  //   cout << "insert 'Apple'" << endl;
  //   tree.insert("Apple");
  //   cout << "insert 'Apple'" << endl;
  //   tree.insert("Apple");
  //   cout << "insert 'Hello'" << endl;
  //   tree.insert("Hello");
  //   cout << "insert 'Zebra'" << endl;
  //   tree.insert("Zebra");
  //   cout << "insert 'Bosley'" << endl;
  //   tree.insert("Bosley");
  //   cout << "largest" << endl;
  //   cout << "expected, Zebra" << endl;
  //   cout << "     got, " << tree.largest() << endl;
  //   cout << "smallest" << endl;
  //   cout << "expected, Apple" << endl;
  //   cout << "     got, " << tree.smallest() << endl;
  //   cout << "height, 'Zebra'" << endl;
  //   cout << "expecting, 2" << endl;
  //   cout << "      got, " << tree.height("Zebra") << endl;
  //   cout << "height, 'Bosley'" << endl;
  //   cout << "expecting, 1" << endl;
  //   cout << "      got, " << tree.height("Bosley") << endl;
  //   cout << "height, 'Apple'" << endl;
  //   cout << "expecting, 0" << endl;
  //   cout << "      got, " << tree.height("Apple") << endl;
  //   cout << "preOrder: ";
  //   tree.preOrder();
  //   cout << endl;
  //   cout << "postOrder: ";
  //   tree.postOrder();
  //   cout << endl;
  //   cout << "inOrder: ";
  //   tree.inOrder();
  //   cout << endl;

  //   cout << endl;
  //   cout << "Calling destructor" << endl;
  // }
  // cout << "Destructor returned" << endl;

//   return 0;

// }

void run_tests() {
    cout << "Constructing BS Tree...";
    BSTree bst = BSTree();
    cout << "complete." << endl;

    int totalTests = 0,failedTests = 0;
    totalTests++;
    cout << "Test: testing largest on empty tree...";
    if (bst.largest() == "") {
        cerr << "Passed" << endl;
    } else {
        cerr << "Failed" << endl;
        failedTests++;
    }
    totalTests++;
    cout << "Test: testing smallest on empty tree...";
    if (bst.smallest() == "") {
        cerr << "Passed" << endl;
    } else {
        cerr << "Failed" << endl;
        failedTests++;
    }
    /* Test insert (assume search works) */
    totalTests++;
    cout << "Test: testing insert and search...";
    string test_input = "Hello";
    bst.insert(test_input);
    if (bst.search(test_input)) {
        cerr << "Passed" << endl;
    } else {
        cerr << "Failed" << endl;
        failedTests++;
    }

    totalTests++;
    cout << "Test: testing insert second word and search first and second...";
    string test_input2 = "World";
    bst.insert(test_input2);
    if (bst.search(test_input) && bst.search(test_input2)) {
        cerr << "Passed" << endl;
    } else {
        cerr << "Failed" << endl;
        failedTests++;
    }

    totalTests++;
    cout << "Test: testing insert duplicate and search first (duplicate) and second...";
    string test_input_duplicate = "Hello";
    bst.insert(test_input_duplicate);
    if (bst.search(test_input) && bst.search(test_input2)) {
        cerr << "Passed" << endl;
    } else {
        cerr << "Failed" << endl;
        failedTests++;
    }

    totalTests++;
    cout << "Test: testing remove duplicate and search first (duplicate) second...";
    bst.remove(test_input);
    if (bst.search(test_input)) {
        cerr << "Passed" << endl;
    } else {
        cerr << "Failed" << endl;
        failedTests++;
    }

    totalTests++;
    cout << "Test: testing remove first (now gone)...";
    bst.remove(test_input);
    if (!bst.search(test_input) && bst.search(test_input2)) {
        cerr << "Passed" << endl;
    } else {
        cerr << "Failed" << endl;
        failedTests++;
    }

    // TODO: Add tests for largest and smallest on non-empty trees
    // TODO: Add tests for insert and remove on larger trees
    // TODO: Add tests for height of nodes (empty and larger trees)
    // Manually inspect pre post and inorder traversals

    cout << "Passed " << totalTests - failedTests << " / " << totalTests << " tests." << endl;
}

void printOrders(BSTree *tree) {
  cout << "Preorder = ";
  tree->preOrder( );
  cout << endl;
  cout << "Inorder = ";
  tree->inOrder( );
  cout << endl;
  cout << "Postorder = ";
  tree->postOrder( );
  cout << endl;
}

int menu() {
  int choice = 0;
  cout << endl << "Enter menu choice: ";
  cout << endl;
  cout 
    << "1. Insert" << endl
    << "2. Remove" << endl
    << "3. Print" << endl
    << "4. Search" << endl
    << "5. Smallest" << endl
    << "6. Largest" << endl
    << "7. Height" << endl
    << "8. Quit" << endl;
  cin >> choice;
  
  // fix buffer just in case non-numeric choice entered
  // also gets rid of newline character
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return choice;
}

int main( ) {
    // Pass all your tests before running the executable main
    // run_tests();  // TODO: Remove before submitting
    // return 0;

    BSTree tree;

    int choice = menu();

    string entry;
  
    while (choice != 8) {
    
        if (choice == 1) {
          cout << "Enter string to insert: ";
          getline(cin, entry);
          tree.insert(entry);
          cout << endl;
        }
        else if (choice == 2) {
          cout << "Enter string to remove: ";
          getline(cin, entry);
          tree.remove(entry);
          cout << endl;
        } 
        else if (choice == 3) {
          printOrders(&tree);
        } 
        else if (choice == 4) {
          cout << "Enter string to search for: ";
          getline(cin, entry);
          if (tree.search(entry)) {
            cout << "\nFound" << endl;
          }
          else {
            cout << "\nNot Found" << endl;
          }
        } 
        else if (choice == 5) {
          cout << "Smallest: ";
          cout << tree.smallest() << endl;
        } 
        else if (choice == 6) {
          cout << "Largest: ";
          cout << tree.largest() << endl;
        } 
        else if (choice == 7) {
          cout << "Enter string: " << endl;
          getline(cin, entry);
          cout << "Height of subtree rooted at " << entry << ": ";
          cout << tree.height(entry) << endl;
        }
        //fix buffer just in case non-numeric choice entered
        choice = menu();
    }
    return 0;
}

  // Compile with: g++ Node.cpp main.cpp BSTree.cpp -Wall -Werror -Wuninitialized -o ./a.exe