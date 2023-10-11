# Abstract Data Types (ADTs)

Abstract Data Types (ADTs) are fundamental concepts in computer science and programming that represent a high-level description of data structures and the operations that can be performed on them, without specifying the underlying implementation details. ADTs provide a level of abstraction that separates the logical behavior of a data structure from its implementation, allowing programmers to focus on how to use the data structure rather than how it is built.

Key Points:

- **Abstraction**: ADTs provide an abstraction layer that separates the logical behavior of a data structure from its implementation, allowing for a focus on usage.

- **Data and Operations**: An ADT defines a set of data (attributes or fields) and a set of operations (methods or functions) that can be performed on that data. These operations include creating, modifying, accessing, and deleting elements in the data structure.

- **Encapsulation**: ADTs encapsulate data and operations within a single unit, often called an "object" or a "class" in object-oriented programming, hiding internal details.

- **Generic**: ADTs are designed to be generic, meaning they can work with various types of data. For example, a stack ADT can be used to store integers, strings, or any other data type.

- **Examples**: Common examples of ADTs include Stacks (Last-In-First-Out), Queues (First-In-First-Out), and Lists (dynamic collections).

- **Implementation-Independent**: ADTs do not specify how data structures are implemented, allowing flexibility in implementation while adhering to specified operations.

- **Modularity**: ADTs promote modularity in software design, creating reusable and well-defined components that can be integrated into larger software systems.

# Stacks

## Introduction
A stack is a fundamental abstract data type (ADT) used in computer science. It follows the Last-In-First-Out (LIFO) principle, meaning the last item added to the stack is the first to be removed. Stacks are used in various algorithms and applications, including function call management, expression evaluation, and more.

## Basic Operations

### 1. Push
- Add an item to the top of the stack.

### 2. Pop
- Remove and return the item at the top of the stack.

### 3. Peek (or Top)
- View the item at the top of the stack without removing it.

### 4. IsEmpty
- Check if the stack is empty.

## Example

```python
# Python example of a stack implementation
class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()

    def peek(self):
        if not self.is_empty():
            return self.items[-1]

    def is_empty(self):
        return len(self.items) == 0

# Usage
my_stack = Stack()
my_stack.push(1)
my_stack.push(2)
my_stack.push(3)

print(my_stack.pop())  # Output: 3
```

## Conclusion

Stacks are versatile data structures that play a crucial role in many algorithms and applications. Understanding how to implement and use stacks is fundamental in computer science.

# Queues

## Introduction
A queue is an abstract data type (ADT) that follows the First-In-First-Out (FIFO) principle, where the first item added is the first to be removed. Queues are used in various applications, including task scheduling, print spooling, and breadth-first search algorithms.

## Basic Operations

### 1. Enqueue (or Push)
- Add an item to the back of the queue.

### 2. Dequeue (or Pop)
- Remove and return the item at the front of the queue.

### 3. Front (or Peek)
- View the item at the front of the queue without removing it.

### 4. IsEmpty
- Check if the queue is empty.

## Example

```python
# Python example of a queue implementation
from collections import deque

class Queue:
    def __init__(self):
        self.items = deque()

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        if not self.is_empty():
            return self.items.popleft()

    def front(self):
        if not self.is_empty():
            return self.items[0]

    def is_empty(self):
        return len(self.items) == 0

# Usage
my_queue = Queue()
my_queue.enqueue(1)
my_queue.enqueue(2)
my_queue.enqueue(3)

print(my_queue.dequeue())  # Output: 1
```

## Conclusion

Queues are essential data structures in computer science, and they are used in various real-world scenarios to manage and process data in a specific order.

# Exception Handling

## Introduction
Exception handling is a crucial aspect of programming that allows you to gracefully handle unexpected or erroneous situations in your code. Exceptions are raised when an error occurs, and they can be caught and handled to prevent program crashes.

## Basic Concepts

### 1. Try and Except Blocks
- The `try` block contains code that might raise an exception.
- The `except` block is executed when an exception occurs in the `try` block.

### 2. Exception Types
- Different exceptions represent various error types (e.g., `ValueError`, `TypeError`, `FileNotFoundError`).
- You can specify the type of exception to catch.

### 3. Finally Block
- The `finally` block contains code that is always executed, whether an exception occurred or not.

## Example

```python
# Python example of exception handling
try:
    num = int(input("Enter a number: "))
    result = 10 / num
except ZeroDivisionError:
    print("Error: Division by zero.")
except ValueError:
    print("Error: Invalid input. Please enter a number.")
else:
    print("Result:", result)
finally:
    print("Execution completed.")
```

# Templates

## Introduction
Templates in C++ provide a way to write generic code that can work with various data types. They are essential for creating generic data structures like containers (e.g., vectors, queues) and generic functions.

## Types of Templates

### 1. Function Templates
- Allow you to define a function that can operate on different data types without writing multiple versions of the same function.

### 2. Class Templates
- Enable the creation of generic classes, where the class can work with different data types.

## Example

```cpp
// C++ example of a function template
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    int result1 = add(5, 3);      // Result: 8
    double result2 = add(2.5, 1.5); // Result: 4.0

    return 0;
}
```

## Conclusion

Templates in C++ allow for code reusability and flexibility by creating generic functions and classes. They are a powerful feature for writing efficient and maintainable code.