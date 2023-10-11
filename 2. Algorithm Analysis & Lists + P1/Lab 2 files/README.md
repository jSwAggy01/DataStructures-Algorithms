# IntList Functionality Testing

## Introduction

This program, developed collaboratively with Julian (jdela055@ucr.edu), is designed to test and demonstrate the functionality of the `IntList` class. The `IntList` class represents a singly-linked list of integers and provides various operations for manipulating and inspecting the list. This README provides an overview of the program's structure and its main functions.

## Program Structure

The program consists of a single C++ source file named `main.cpp`. The key components of the program include:

- **Header File**: `IntList.h` - This file likely contains the declaration of the `IntList` class and its member functions. It's included to provide access to the class's interface.

- **Main Function**: `main()` - The program's entry point, where various tests and demonstrations of the `IntList` class are performed.

## Program Execution

The program is structured to test several operations provided by the `IntList` class, including:

1. **Testing `push_front()`**: This function adds elements to the front of the list. In this test, five integers (1, 2, 3, 4, and 5) are added to the list using `push_front()`.

2. **Testing Overloaded Output Operator**: The overloaded `<<` operator is used to print the contents of the list.

3. **Testing `printReverse()`**: This function prints the elements of the list in reverse order.

4. **Testing `pop_front()`**: This operation removes the front element of the list.

5. **Testing `pop_back()`**: This operation removes the last element of the list.

6. **Testing `push_back()`**: This function adds elements to the back of the list.

7. **Memory Cleanup**: The `delete` operator is used to free the memory allocated for the list to prevent memory leaks.

## Usage

To use this program and observe the behavior of the `IntList` class, follow these steps:

1. Compile the program: Use a C++ compiler to compile the `main.cpp` source file. Ensure that `IntList.h` is in the same directory or included in the project.

2. Run the compiled program: Execute the compiled program to perform the series of tests and view the results.

Compile with:

```bash
g++ main.cpp IntList.cpp -o a.exe
```

## Sample Output

```bash
$ ./a


Testing push_front()...


Testing overloaded function...        
5 4 3 2 1

Testing printReverse()...

1 2 3 4 5

Testing pop_front()...

2 3 4 5

Testing pop_back()
2 3 4

Deleting list...Testing push_back()...

4 3 2 1 2 3 4 5
```

## Comments and Notes

- The program contains some commented-out code blocks that seem to represent additional tests or experiments. These can be uncommented and further developed for additional testing if needed.

- Collaborator information is provided at the beginning of the file to indicate collaboration on the project.

- Some sections of the code are commented with "### frontList test ###" and "### backList test ###," which suggest the program might have been intended to test different lists or scenarios. You can adapt and extend the program as needed for your specific testing purposes.

## Conclusion

This program serves as a demonstration of the `IntList` class and its various operations. You can use it as a starting point for further development, testing, or integration into a larger project involving linked lists of integers.
