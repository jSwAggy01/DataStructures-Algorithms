# Stack Functionality Testing

## Introduction

This program demonstrates the usage and testing of a stack class. It tests various scenarios, including the constructor, push, pop, top, and empty operations, for both integer and string data types. The program aims to verify the correct behavior of the stack class and handle exceptions gracefully. This README provides an overview of the program's structure and its main functions.

## Program Structure

The program consists of a single C++ source file named `main.cpp`. The key components of the program include:

- **Main Function**: `main()`: The program's entry point, where various test cases are defined and executed. The test cases include scenarios for both integer and string data types, testing stack operations and exception handling.

- **Stack Class**: The stack class is not provided in this file but is assumed to be included via the `"stack.h"` header file. It contains the necessary stack implementation, including constructor, push, pop, top, and empty functions.

## Program Execution

The program executes the following steps:

1. **User Input**: The program prompts the user to enter a test number (1-5) to select a specific test case scenario.

2. **Test Cases**: Depending on the selected test case, the program performs one of the following tests:
   - Test 1: Constructor, push, pop, top, and empty operations on a stack of integers.
   - Test 2: Top operation on an empty stack.
   - Test 3: Pop operation from an empty stack.
   - Test 4: Push operation on a full stack (limited to 20 elements).
   - Test 5: Constructor, push, pop, top, and empty operations on a stack of strings.

3. **Output**: The program displays the results of each test case, including stack operations and exception handling. It indicates whether the stack is empty or not and shows the top element when applicable.

## Usage

To use this program and test the stack class with various scenarios, follow these steps:

1. **Compile the program**: Use a C++ compiler to compile the `main.cpp` source file.

2. **Run the compiled program**: Execute the compiled program, and it will prompt you to enter a test number (1-5) to select a specific test case.

3. **Observe the results**: The program will execute the selected test case, display the operations performed, and provide information on whether the stack is empty or not. Exception handling messages will be displayed when necessary.

Compile with:

```bash
g++ main.cpp -o a.exe
```

## Sample Output

```bash
$ ./a
Enter a test number(1-5): 5


stack5 constructor called
push A
push B
push C
stack5 top: C
pop
stack5 top: B
pop
stack5 top: A
pop
stack5 is empty.
stack5 top:
Called top on empty stack.
```

## Comments and Notes

- The program includes multiple test cases, each testing different aspects of the stack class, including edge cases and error handling.

- Collaborator information is provided at the beginning of the file to indicate collaboration on the project.

## Conclusion

This program serves as a comprehensive test suite for a stack class, demonstrating its behavior when working with integers and strings, as well as handling various scenarios and exceptions. You can use it as a reference for testing and verifying the correctness of your own stack implementation or for learning how to handle exceptions in a C++ program.
