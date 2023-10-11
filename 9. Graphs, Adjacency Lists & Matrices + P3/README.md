# Graphs, Adjacency Lists and Matrices

## Introduction
Graphs are a fundamental data structure used to represent relationships between entities. They consist of nodes (vertices) and edges connecting those nodes. In this README, we'll explore graphs, two common representations (adjacency lists and adjacency matrices), and their implementations in C++.

## Graphs

### 1. Nodes (Vertices)
- Nodes are the entities or points in a graph.
- Each node can have a label or value associated with it.

### 2. Edges
- Edges are the connections between nodes in a graph.
- They can be directed (one-way) or undirected (two-way).
- Edges may have weights or costs associated with them.

## Adjacency List

### 1. Representation - Adjacency List
- In an adjacency list representation, each node in the graph has a list of its adjacent nodes.
- It is efficient for sparse graphs (few edges).
- Suitable for various graph algorithms.

## Adjacency Matrix

### 2. Representation - Adjacency Matrix
- In an adjacency matrix representation, a two-dimensional array is used to represent the graph.
- The rows and columns of the matrix correspond to nodes, and the values indicate whether an edge exists between nodes.
- It is efficient for dense graphs (many edges).
- Requires more memory compared to adjacency lists.

## Basic Operations

### 1. Insertion
- Adding nodes and edges to the graph.

### 2. Deletion
- Removing nodes and edges from the graph.

### 3. Search
- Finding specific nodes or edges in the graph.

## Example

```cpp
// C++ example of a graph using adjacency list representation
#include <iostream>
#include <vector>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyList;

public:
    Graph(int vertices) : numVertices(vertices), adjacencyList(vertices) {}

    // Add an edge to the graph
    void addEdge(int src, int dest) {
        adjacencyList[src].push_back(dest);
        // For undirected graphs, add the reverse edge as well.
        adjacencyList[dest].push_back(src);
    }

    // Print the adjacency list
    void print() {
        for (int i = 0; i < numVertices; ++i) {
            std::cout << "Adjacency list of vertex " << i << ": ";
            for (int neighbor : adjacencyList[i]) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }
};
```

## Conclusion

Graphs are versatile data structures used in various applications, including network modeling, social networks, and route planning. Understanding different representations like adjacency lists and adjacency matrices is essential for solving complex problems efficiently in graph theory.