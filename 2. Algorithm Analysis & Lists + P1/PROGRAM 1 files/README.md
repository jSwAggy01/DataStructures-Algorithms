# Josephus Game Program

## Introduction

This program, developed in collaboration with Peter Chu, simulates the Josephus problem, a classic theoretical problem related to a certain elimination game. The program allows users to input a list of names and a "skip" value, and it calculates the winning name in the game according to the Josephus algorithm. This README provides an overview of the program's structure and its main functions.

## Program Structure

The program consists of a single C++ source file named `main.cpp`. The key components of the program include:

- **Node Structure**: The `Node` struct represents elements of a circular linked list. Each node contains a payload (a person's name in this context) and a pointer to the next node in the list.

- **Functions**:
  - `newNode()`: Creates a new node with a given payload.
  - `loadGame()`: Initializes and loads a circular linked list with names.
  - `print()`: Prints the contents of the linked list.
  - `runGame()`: Simulates the Josephus game, determining the last person standing.
  - `main()`: The program's entry point, where user input is obtained, the game is run, and the winning name is displayed.

## Program Execution

The program executes the following steps:

1. **Input**: The program prompts the user to input the number of names (`n`) and the "skip" value (`k`) using the standard input (cin). It also accepts a list of names until the input is terminated with a period (`.`) or until the end of the file (EOF).

2. **Initialization**: The program initializes a circular linked list with the provided names.

3. **Josephus Game**: The Josephus algorithm is executed on the circular linked list to find the last person standing.

4. **Output**: The program displays the name of the last person standing as the winner.

## Usage

To use this program and play the Josephus game with a list of names, follow these steps:

1. **Compile the program**: Use a C++ compiler to compile the `main.cpp` source file.

2. **Run the compiled program**: Execute the compiled program to interactively input the number of names (`n`), the "skip" value (`k`), and the list of names. Terminate the input by entering a period (`.`) on a new line or by reaching the end of the file (EOF).

3. **Observe the result**: The program will calculate and display the name of the last person standing as the winner of the Josephus game.

Compile with:

```bash
g++ main.cpp -o a.exe
```

## Sample Output

```bash
$ ./a
7 3
Bob Lumbergh Amy Richard Megan Timothy Slater .
Lumbergh wins!
```

## Comments and Notes

- The program is designed to handle circular linked lists efficiently and follows the Josephus algorithm for elimination games.

- Collaborator information is provided at the beginning of the file to indicate collaboration on the project.

- There are some commented-out code blocks within the `main()` function that can be used for additional testing or debugging if needed.

## Conclusion

This program demonstrates the Josephus algorithm for solving an elimination game with a circular linked list. You can use it to simulate and find the winning participant when given a list of names and a "skip" value. It can serve as a useful tool for educational purposes or for solving similar problems involving circular eliminations.
