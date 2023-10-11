# Quicksort and Insertion Sort Performance Analysis

## Introduction

This program performs a performance analysis of two sorting algorithms: quicksort with different pivot selection methods and insertion sort. It measures the execution time of these algorithms for sorting arrays of random integers.

## Program Structure

The program consists of a C++ source file named `main.cpp` and includes other standard libraries. The key components of the program include:

- **Main Function**: `main()`: The program's entry point, where the performance analysis of quicksort and insertion sort is conducted.

- **Sorting Algorithms**: The program implements two sorting algorithms:
  - **Quicksort with Midpoint Pivot**: `Quicksort_midpoint()`
  - **Quicksort with Median-of-Three Pivot**: `Quicksort_medianOfThree()`
  - **Insertion Sort**: `InsertionSort()`

- **Utility Functions**: The program includes utility functions for generating random integers and filling arrays.

- **Global Constants**: The program defines a global constant `NUMBERS_SIZE` for the size of the arrays to be sorted.

## Program Execution

The program executes the following steps:

1. **Array Initialization**: It initializes three arrays (`arr1`, `arr2`, and `arr3`) with random integers.

2. **Performance Analysis**:
   - It measures and prints the execution time of quicksort with the midpoint pivot for `arr1`.
   - It measures and prints the execution time of quicksort with the median-of-three pivot for `arr2`.
   - It measures and prints the execution time of insertion sort for `arr3`.

3. **Output**: The program displays the execution times of the sorting algorithms in milliseconds.

## Usage

To use this program for performance analysis of sorting algorithms, follow these steps:

1. **Compile the Program**: Use a C++ compiler to compile the source file `main.cpp`. For example:

```bash
g++ main.cpp -Wall -Werror -o ./a.exe
```

2. **Run the Compiled Program**: Execute the compiled program (`./a.exe` on Windows).

3. **Performance Analysis**: The program will conduct a performance analysis of the following sorting algorithms:
- Quicksort with midpoint pivot for `arr1`
- Quicksort with median-of-three pivot for `arr2`
- Insertion sort for `arr3`

4. **Output**: The program will display the execution times of the sorting algorithms in milliseconds.

5. **Analysis**: You can analyze the execution times to compare the performance of the different sorting algorithms.

## Sample Output

```bash
$ ./a
Beginning tests...

Testing quicksort midpoint on arr1
Time elapsed: 0 milliseconds      

Testing quicksort median on arr2  
Time elapsed: 16 milliseconds 

Testing insertion sort on arr3
Time elapsed: 1891 milliseconds

Testing completed...
```

## Comments and Notes

- The program uses C++ standard libraries for input and output operations.

- It includes utility functions for generating random integers and filling arrays with random data.

- Collaborator information is provided at the beginning of the file to indicate collaboration on the project.

## Conclusion

This program serves as a tool for conducting a performance analysis of quicksort with different pivot selection methods and insertion sort. It helps users evaluate the efficiency of these sorting algorithms for sorting arrays of random integers.