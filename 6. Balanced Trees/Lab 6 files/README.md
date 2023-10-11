# Arithmetic Expression Parser

## Introduction

This program demonstrates the parsing and evaluation of arithmetic expressions. The program takes arithmetic expressions as input and constructs expression trees to represent them. It provides functionality to convert expressions from infix notation to prefix and postfix notations and to visualize the expression tree.

## Program Structure

The program consists of multiple C++ source files, including `main.cpp` and `arithmeticExpression.cpp`, along with other necessary source files. The key components of the program include:

- **Main Function**: `main()`: The program's entry point, where users can provide arithmetic expressions and observe the conversion to infix, prefix, and postfix notations, as well as visualize the expression tree.

- **ArithmeticExpression Class**: The `arithmeticExpression.cpp` file contains the implementation of the `arithmeticExpression` class, which represents arithmetic expressions. It includes functions for building expression trees, converting expressions to infix, prefix, and postfix notations, and visualizing the expression tree.

## Program Execution

The program executes the following steps:

1. **User Input**: The program provides a set of predefined arithmetic expressions (e.g., "a+b*c") and parses and evaluates them.

2. **Expression Tree Construction**: For each provided expression, the program constructs an expression tree to represent it.

3. **Conversion and Display**: The program displays the original infix expression and its equivalents in prefix and postfix notations. It also provides the option to visualize the expression tree (using Graphviz).

## Usage

To use this program and observe the parsing and evaluation of arithmetic expressions, follow these steps:

1. **Compile the Program**: Use a C++ compiler to compile the source files, including `main.cpp` and `arithmeticExpression.cpp`, along with any other necessary source files. For example:

```bash
g++ main.cpp arithmeticExpression.cpp -Wall -Werror -o ./a.exe
```

2. **Run the Compiled Program**: Execute the compiled program (`./a.exe` on Windows) to start parsing and evaluating arithmetic expressions. The program will display the results for predefined expressions.

3. **Observing Results**: The program will display the original infix expression and its equivalents in prefix and postfix notations. You can observe the expression tree visualization by using the provided Graphviz `.dot` file.

4. **Custom Expressions**: To test custom expressions, you can modify the expressions in the `main()` function by assigning them to the `expr1`, `expr2`, or `expr3` variables. Rebuild and run the program to observe the results for your custom expressions.

5. **Exit the Program**: To exit the program, simply close the terminal or command prompt.

## Output

```bash
$ ./a
expression 1: a+b*c
infix: (a+(b*c))
prefix: +a*bc
postfix: abc*+

expression 2: (a+b)*(c-d)
infix: ((a+b)*(c-d))
prefix: *+ab-cd
postfix: ab+cd-*

expression 3: a + b * c - ( d * e + f ) * g
infix: ((a+(b*c))-(((d*e)+f)*g))
prefix: -+a*bc*+*defg
postfix: abc*+de*f+g*-
```

## Comments and Notes

- The program includes the `arithmeticExpression` class to encapsulate the logic for expression parsing and tree construction.

- Collaborator information is provided at the beginning of the file to indicate collaboration on the project.

- The program utilizes Graphviz for visualizing expression trees. To generate visualizations, you can uncomment the `visualizeTree()` function calls and provide a suitable filename (e.g., `"expr1.dot"`) as an argument.

## Conclusion

This program serves as a tool for parsing and evaluating arithmetic expressions, providing a visual representation of expression trees and the conversion between infix, prefix, and postfix notations. It can be used to understand how expression parsing and tree construction work in computer science and mathematics.