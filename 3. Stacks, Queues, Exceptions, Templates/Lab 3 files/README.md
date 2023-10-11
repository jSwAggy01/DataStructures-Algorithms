# Selection Sort and Exception Handling Program

## Introduction

This program, developed in collaboration with Peter Chu, demonstrates the implementation of the selection sort algorithm for sorting a vector of elements. It also showcases exception handling to gracefully handle out-of-range access when retrieving elements from the vector. This README provides an overview of the program's structure and its main functions.

## Program Structure

The program consists of a single C++ source file named `main.cpp`. The key components of the program include:

- **Selection Sort Functions**:
  - `min_index()`: Finds the index of the minimum element in a vector, starting from a given index.
  - `selection_sort()`: Sorts a vector of elements using the selection sort algorithm.
  
- **Exception Handling**:
  - `getElement()`: Retrieves an element from a vector at a specified index and handles out-of-range exceptions gracefully.

- **Random Vector Creation**:
  - `createVector()`: Generates a random vector of characters of varying lengths.

- **Main Function**: `main()`: The program's entry point, where selection sort and exception handling are demonstrated. It generates a random vector, allows the user to input an index, and retrieves the element at that index while handling out-of-range exceptions.

## Program Execution

The program executes the following steps:

1. **Selection Sort Demonstration**: The program contains commented-out code for testing the selection sort algorithm on a vector of integers. This section of the code demonstrates how to sort a vector in ascending order.

2. **Random Vector Generation**: The program generates a random vector of characters with a random size between 0 and 25. The characters in the vector are lowercase letters starting from 'a'.

3. **Exception Handling Demonstration**: The program enters a loop that allows the user to input an index to retrieve an element from the generated vector. If the input index is out of range, an out-of-range exception is caught and handled gracefully, displaying an error message.

4. **Repeatable Run**: The user can repeat the index input and element retrieval process a specified number of times (in this case, 10 times).

## Usage

To use this program and observe the selection sort algorithm and exception handling in action, follow these steps:

1. **Compile the program**: Use a C++ compiler to compile the `main.cpp` source file.

2. **Run the compiled program**: Execute the compiled program to interact with the selection sort demonstration and the exception handling demonstration.

3. **Observe the results**: The program will demonstrate the selection sort algorithm and allow you to input indices to retrieve elements from the random vector, handling out-of-range exceptions gracefully.

Compile with:

```bash
g++ main.cpp -o a.exe
```

## Sample Output

```bash
$ ./a
Enter a number: 
7
Element located at 7: is h
Enter a number: 
4
Element located at 4: is e
Enter a number: 
0
Element located at 0: is a
Enter a number: 
99
out of range exception occurred
terminate called after throwing an instance of 'std::out_of_range'
  what():  vector::_M_range_check: __n (which is 99) >= this->size() (which is 18)
```

## Comments and Notes

- The program includes code blocks that are commented out. You can uncomment these blocks to test and experiment with different scenarios, such as sorting other types of vectors or modifying the random vector generation process.

- Collaborator information is provided at the beginning of the file to indicate collaboration on the project.

## Conclusion

This program serves as a demonstration of the selection sort algorithm for sorting vectors and showcases how to handle out-of-range exceptions gracefully when accessing elements from a vector. You can use it as a reference for implementing selection sort and exception handling in your own C++ programs.
