# Directed Acyclic Graphs (DAGs), Minimum Spanning Trees (MSTs), and All-Pair Shortest Paths (APSP)

## Introduction
Directed Acyclic Graphs (DAGs), Minimum Spanning Trees (MSTs), and All-Pair Shortest Paths (APSP) are fundamental concepts and algorithms in graph theory and computer science. In this README, we'll explore these topics and their implementations in C++.

## Directed Acyclic Graphs (DAGs)

### 1. DAGs
- A Directed Acyclic Graph (DAG) is a directed graph with no cycles.
- DAGs are used to represent various relationships and dependencies without circular dependencies.
- Common applications include task scheduling, topological sorting, and dependency resolution.

## Minimum Spanning Trees (MSTs)

### 2. Minimum Spanning Trees (MSTs)
- A Minimum Spanning Tree is a subgraph of a connected, undirected graph that includes all vertices and has the minimum possible sum of edge weights.
- MSTs are used in network design, clustering, and optimization problems.

### 3. Algorithms for Finding MSTs
   - Prim's Algorithm
   - Kruskal's Algorithm

## All-Pair Shortest Paths (APSP)

### 4. All-Pair Shortest Paths (APSP)
- APSP algorithms find the shortest path between all pairs of vertices in a weighted graph.
- APSP is used in navigation systems, network routing, and various optimization problems.

### 5. Algorithms for APSP
   - Floyd-Warshall Algorithm
   - Johnson's Algorithm (for graphs with negative weights)

## Basic Operations

### 1. DAGs
   - Topological Sorting: Finding a linear ordering of vertices such that for every directed edge (u, v), vertex u comes before vertex v.
   - Detecting Cycles: Identifying cycles in a directed graph.

### 2. MSTs
   - Finding the Minimum Spanning Tree of a graph.
   - Determining the total weight (cost) of the MST.

### 3. APSP
   - Finding the shortest paths between all pairs of vertices.
   - Determining the shortest path distances.

## Example

```cpp
// C++ example of finding the Minimum Spanning Tree (Kruskal's Algorithm)
#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
    int src, dest, weight;
};

class Graph {
private:
    int V;
    std::vector<Edge> edges;

public:
    Graph(int vertices) : V(vertices) {}

    void addEdge(int src, int dest, int weight) {
        edges.push_back({src, dest, weight});
    }

    // Helper function to find the parent of a vertex
    int findParent(std::vector<int>& parent, int node) {
        if (parent[node] == -1) {
            return node;
        }
        return findParent(parent, parent[node]);
    }

    // Function to find the Minimum Spanning Tree using Kruskal's Algorithm
    void findMST() {
        std::sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        std::vector<int> parent(V, -1);
        int mstWeight = 0;

        for (const Edge& edge : edges) {
            int srcParent = findParent(parent, edge.src);
            int destParent = findParent(parent, edge.dest);

            if (srcParent != destParent) {
                std::cout << "Edge (" << edge.src << " - " << edge.dest << ") with weight " << edge.weight << " added to MST." << std::endl;
                mstWeight += edge.weight;
                parent[srcParent] = destParent;
            }
        }

        std::cout << "Total weight of Minimum Spanning Tree: " << mstWeight << std::endl;
    }
};
```

## Conclusion

Directed Acyclic Graphs (DAGs), Minimum Spanning Trees (MSTs), and All-Pair Shortest Paths (APSP) are important concepts and algorithms in graph theory. Understanding how to work with these structures and apply the associated algorithms is valuable for solving various real-world problems efficiently.