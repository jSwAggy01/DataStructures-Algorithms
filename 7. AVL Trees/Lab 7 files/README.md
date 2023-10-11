# AVL Tree Program

## Introduction

This program demonstrates the creation and management of AVL trees. The program allows users to insert strings into the AVL tree and view the balance factors of the nodes.

## Program Structure

The program consists of multiple C++ source files, including `main.cpp`, `AVLTree.cpp`, and `Node.cpp`, along with other necessary source files. The key components of the program include:

- **Main Function**: `main()`: The program's entry point, where users can insert strings into the AVL tree and view the balance factors of the nodes.

- **AVLTree Class**: The `AVLTree.cpp` file contains the implementation of the `AVLTree` class, which represents the AVL tree data structure. It includes functions for inserting nodes, printing balance factors, and optionally visualizing the tree.

- **Node Class**: The `Node.cpp` file contains the implementation of the `Node` class, representing individual nodes in the AVL tree.

## Program Execution

The program executes the following steps:

1. **User Input**: The program provides a menu with options to insert strings into the AVL tree and print balance factors.

2. **Insertion**: Users can choose to insert a string into the AVL tree. The program balances the tree as necessary to maintain AVL properties.

3. **Printing Balance Factors**: Users can choose to print the balance factors of the nodes in the AVL tree.

## Usage

To use this program and manage AVL trees, follow these steps:

1. **Compile the Program**: Use a C++ compiler to compile the source files, including `main.cpp`, `AVLTree.cpp`, and `Node.cpp`, along with any other necessary source files. For example:

```bash
g++ AVLTree.cpp Node.cpp main.cpp -Wall -Werror -o ./a.exe
```

2. **Run the Compiled Program**: Execute the compiled program (`./a.exe` on Windows) to start managing AVL trees.

3. **Menu Options**: The program will display a menu with the following options:

- **Insert**: Choose option 1 to insert a string into the AVL tree. Enter the string when prompted.

- **Print Balance Factors**: Choose option 2 to print the balance factors of the nodes in the AVL tree.

- **Quit**: Choose option 3 to exit the program.

4. **Insertion**: Insert strings into the AVL tree to observe how the tree remains balanced. The program will handle tree balancing automatically.

5. **Printing Balance Factors**: Choose the "Print Balance Factors" option to view the balance factors of the nodes in the AVL tree.

6. **Exit the Program**: To exit the program, select the "Quit" option.

## Sample Output

```vbnet
$ ./a

Enter menu choice: 
1. Insert
2. Print
3. Quit
1   
Enter string to insert: bird


Enter menu choice: 
1. Insert
2. Print
3. Quit
1
Enter string to insert: bee

bird(1), bee(0),   
Enter menu choice: 
1. Insert
2. Print
3. Quit
1
Enter string to insert: zebra

bird(0), bee(0), zebra(0), 
Enter menu choice:
1. Insert
2. Print
3. Quit
1
Enter string to insert: golang 

bird(-1), bee(0), zebra(1), golang(0), bird(-1), bee(0), zebra(1), golang(0),

Enter menu choice:
1. Insert
2. Print
3. Quit
2
bee(0), bird(-1), golang(0), zebra(1), 

Enter menu choice:
1. Insert
2. Print
3. Quit
3
```

## Comments and Notes

- The program includes the `AVLTree` class to encapsulate AVL tree logic, and it uses the `Node` class to represent individual nodes.

- Collaborator information is provided at the beginning of the file to indicate collaboration on the project.

- The program optionally supports visualizing the AVL tree by calling the `visualizeTree()` function. You can uncomment this function call and provide a suitable filename as an argument to generate a visualization file.

## Conclusion

This program serves as a tool for managing AVL trees, allowing users to insert strings and view balance factors. It can be used to understand how AVL tree structures and balancing work in computer science and data structures.
