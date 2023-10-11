# Hashing, Chaining, and Probing

## Introduction
Hashing is a fundamental technique in computer science used to map data to specific locations (buckets) within a data structure called a hash table. Hashing enables efficient data retrieval by reducing search time. In this README, we'll explore hashing, two collision resolution methods (chaining and probing), and their implementations in C++.

## Hashing

### 1. Hash Function
- A hash function takes an input (or key) and returns a fixed-size, typically smaller, value (hash code).
- It should consistently produce the same hash code for the same input.

### 2. Hash Table
- A hash table is an array that stores data elements using their hash codes as indices.
- It allows fast data retrieval when the hash function distributes data evenly across the table.

## Chaining

### 1. Collision Resolution - Chaining
- In chaining, each bucket in the hash table holds a linked list (or another data structure) to store multiple elements with the same hash code.
- Collisions are resolved by adding elements to the linked list associated with their hash code.

## Probing

### 2. Collision Resolution - Probing
- Probing involves searching for the next available slot (usually within the same table) when a collision occurs.
- Common probing techniques include linear probing and quadratic probing.

## Basic Operations

### 1. Insertion
- Adding a key-value pair to the hash table.
- The hash function determines the location (index) for the key.

### 2. Retrieval
- Finding a value associated with a given key.
- The hash function is used to locate the key's position.

### 3. Deletion
- Removing a key-value pair from the hash table.
- The hash function locates the key, and the value is removed.

## Example

```cpp
// C++ example of a hash table using chaining
#include <iostream>
#include <list>
#include <vector>

class HashTable {
private:
    static const int tableSize = 10;
    std::vector<std::list<std::pair<int, std::string>>> table;

    int hash(int key) {
        return key % tableSize;
    }

public:
    HashTable() : table(tableSize) {}

    void insert(int key, const std::string& value) {
        int index = hash(key);
        table[index].emplace_back(key, value);
    }

    std::string get(int key) {
        int index = hash(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return "Key not found.";
    }

    void remove(int key) {
        int index = hash(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                break;
            }
        }
    }
};
```

## Conclusion

Hashing is a versatile technique used in various applications, including data retrieval, caching, and encryption. Understanding hash functions, hash tables, and collision resolution methods like chaining and probing is essential for efficient data management and retrieval.