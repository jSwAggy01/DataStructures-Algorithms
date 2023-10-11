# Printer Priority Queue (Heap) Program

## Introduction

This program demonstrates the usage and testing of a Priority Queue implemented as a Max Heap. The program allows users to perform various operations on the Priority Queue, including enqueueing print jobs with priorities, printing the jobs in order of priority, and dequeuing the highest-priority print job. This README provides an overview of the program's structure, its main functions, and how to use it.

## Program Structure

The program consists of multiple C++ source files, including `main.cpp`, `Heap.h`, and `PrintJob.cpp`, along with other necessary source files. The key components of the program include:

- **Main Function**: `main()`: The program's entry point, where users can interact with the Priority Queue by selecting menu options to perform various operations.

- **Heap Class**: The Max Heap implementation is provided in the `Heap.h` header file. It includes functions for enqueueing print jobs with priorities, printing the jobs in priority order, and dequeuing the highest-priority print job.

- **PrintJob Class**: The `PrintJob.cpp` file contains the implementation of the `PrintJob` class, which represents individual print jobs with attributes such as priority, job number, and the number of pages.

## Program Execution

The program executes the following steps:

1. **User Interaction**: The program presents a menu to the user, allowing them to choose from various operations to perform on the Priority Queue (Heap).

2. **Heap Operations**: Depending on the user's choice, the program performs the selected operation, such as enqueuing print jobs, printing the jobs in order of priority, or dequeuing the highest-priority print job.

3. **Output**: The program provides appropriate output messages and results based on the selected operation. For example, it displays the print jobs in priority order or information about the dequeued job.

## Usage

To use this program and interact with the Priority Queue (Heap), follow these steps:

1. **Compile the Program**: Use a C++ compiler to compile the source files, including `main.cpp`, `Heap.cpp`, and `PrintJob.cpp`, along with any other necessary source files. For example:

```bash
g++ main.cpp PrintJob.cpp Heap.cpp -Wall -Werror -o ./a.exe
```

2. **Run the Compiled Program**: Execute the compiled program (`./a.exe` on Windows) to start interacting with the Priority Queue (Heap). You will see a menu with different options.

3. **Interact with the Priority Queue**: Choose an option from the menu to perform the corresponding operation. For example, you can enqueue print jobs, print the jobs in priority order, or dequeue the highest-priority print job.

4. **Follow Prompts**: Depending on the chosen operation, the program may prompt you to enter information about print jobs or provide information about the results of the operation.

5. **Exit the Program**: To exit the program, select the "Quit" option from the menu.

## Sample Output

```bash
$ ./a

Enter menu choice: 
1. Enqueue
2. Print
3. Dequeue
4. Quit
1
Enter print job to enqueue (priority, job Number, number of pages): 1 5 9


Enter menu choice: 
1. Enqueue
2. Print
3. Dequeue
4. Quit
2
Priority: 1, Job Number: 5, Number of Pages: 9

Enter menu choice: 
1. Enqueue
2. Print
3. Dequeue
4. Quit
4
```

## Comments and Notes

- The program includes a `menu()` function that displays the menu options to the user and captures their choice.

- The Max Heap implementation in the `Heap` class ensures that print jobs are dequeued in descending order of priority.

- Collaborator information is provided at the beginning of the file to indicate collaboration on the project.

## Conclusion

This program serves as a tool for interacting with a Priority Queue (Heap) of print jobs, allowing users to perform various operations and explore the behavior of the Max Heap data structure. It can be used to manage and prioritize print jobs efficiently.
