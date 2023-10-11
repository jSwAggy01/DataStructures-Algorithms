# Binary Search Tree (BST) Implementation and Testing

## Introduction

This program demonstrates the usage and testing of a Binary Search Tree (BST) data structure. The program allows users to perform various operations on a BST, including insertion, removal, printing of tree orders, searching for elements, finding the smallest and largest elements, and determining the height of nodes. This README provides an overview of the program's structure, its main functions, and how to use it.

## Program Structure

The program consists of multiple C++ source files, including `main.cpp`, `BSTree.h`, and other necessary source files. The key components of the program include:

- **Main Function**: `main()`: The program's entry point, where users can interact with the BST by selecting menu options to perform various operations.

- **BSTree Class**: The BST implementation is provided in the `BSTree.h` header file. It includes functions for inserting elements, removing elements, searching for elements, finding the smallest and largest elements, determining the height of nodes, and printing tree orders (preorder, inorder, and postorder).

## Program Execution

The program executes the following steps:

1. **User Interaction**: The program presents a menu to the user, allowing them to choose from various operations to perform on the BST.

2. **BST Operations**: Depending on the user's choice, the program performs the selected BST operation, such as inserting, removing, searching, printing tree orders, finding the smallest or largest element, or determining the height of nodes.

3. **Output**: The program provides appropriate output messages and results based on the selected operation. For example, it displays whether an element was found during a search or prints the tree orders.

## Usage

To use this program and interact with the BST, follow these steps:

1. **Compile the Program**: Use a C++ compiler to compile the source files, including `main.cpp` and any other necessary source files.

2. **Run the Compiled Program**: Execute the compiled program (./a.exe on Windows) to start the BST operations. You will see a menu with different options.

3. **Interact with the BST**: Choose an option from the menu to perform the corresponding operation. For example, you can insert elements, remove elements, search for elements, print tree orders, find the smallest or largest element, or determine the height of nodes.

4. **Follow Prompts**: Depending on the chosen operation, the program may prompt you to enter strings or provide information about the result of the operation.

5. **Exit the Program**: To exit the program, select the "Quit" option from the menu.

Compile with:

```bash
g++ main.cpp BSTree.cpp -Wall -Werror -Wuninitialized -o ./a.exe
```

## Sample Output

```vbnet
$ ./a

Enter menu choice: 
1. Insert
2. Remove
3. Print
4. Search
5. Smallest        
6. Largest
7. Height
8. Quit
1
Enter string to insert: dog


Enter menu choice: 
1. Insert
2. Remove
3. Print
4. Search
5. Smallest        
6. Largest
7. Height
8. Quit
1
Enter string to insert: cat


Enter menu choice: 
1. Insert
2. Remove
3. Print
4. Search
5. Smallest        
6. Largest
7. Height
8. Quit
1
Enter string to insert: wolf


Enter menu choice: 
1. Insert
2. Remove
3. Print
4. Search
5. Smallest
6. Largest
7. Height
8. Quit
3
Preorder = dog(1), cat(1), wolf(1), 
Inorder = cat(1), dog(1), wolf(1),
Postorder = cat(1), wolf(1), dog(1),

Enter menu choice:
1. Insert
2. Remove
3. Print
4. Search
5. Smallest
6. Largest
7. Height
8. Quit
2
Enter string to remove: dog


Enter menu choice:
1. Insert
2. Remove
3. Print
4. Search
5. Smallest
6. Largest
7. Height
8. Quit
3
Preorder = cat(1), wolf(1), 
Inorder = cat(1), wolf(1),
Postorder = wolf(1), cat(1),

Enter menu choice:
1. Insert
2. Remove
3. Print
4. Search
5. Smallest
6. Largest
7. Height
8. Quit
8
```

## Comments and Notes

- The program includes a `run_tests()` function that can be used to run automated tests on the BST. You can uncomment and call this function to verify the correctness of the BST implementation.

- The program is designed to handle various scenarios, including inserting and removing elements, searching for elements, and handling edge cases.

- Collaborator information is provided at the beginning of the file to indicate collaboration on the project.

## Conclusion

This program serves as a tool for interacting with a Binary Search Tree (BST), allowing users to perform various operations and explore the behavior of the BST data structure. It can be used for educational purposes to learn about BST operations and how they work.