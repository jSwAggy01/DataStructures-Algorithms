# Balanced Trees

## Introduction
Balanced trees are specialized tree data structures designed to maintain a balanced structure, ensuring efficient insertion, deletion, and search operations. These trees are crucial for maintaining optimal performance in various applications, including databases, file systems, and data storage structures.

## Types of Balanced Trees

### 1. AVL Tree
- An AVL tree (Adelson-Velsky and Landis tree) is a self-balancing binary search tree.
- It ensures that the height of the left and right subtrees of any node differs by at most one.
- AVL trees guarantee logarithmic time complexity for searching, insertion, and deletion operations.

### 2. Red-Black Tree
- A Red-Black tree is another self-balancing binary search tree with a set of rules for maintaining balance.
- It uses color-coding and rotation operations to ensure that the tree remains balanced.
- Red-Black trees offer logarithmic time complexity for basic operations.

### 3. B-Tree
- A B-tree is a balanced tree structure designed for efficient disk access and storage.
- It is commonly used in databases and file systems.
- B-trees have multiple levels, making them suitable for managing large datasets.

## Basic Operations

### 1. Insertion
- Adding a new element to the balanced tree while maintaining its balance.

### 2. Deletion
- Removing an element from the balanced tree while preserving its balanced structure.

### 3. Searching
- Finding a specific element within the balanced tree efficiently.

### 4. Traversal
- Visiting all elements in the balanced tree in a specific order, such as in-order or level-order traversal.

## Example

```cpp
// C++ example of an AVL tree implementation
#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    TreeNode* root;

public:
    AVLTree() : root(nullptr) {}

    // Insert a value into the AVL tree
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Helper function for recursive insertion
    TreeNode* insertRecursive(TreeNode* current, int value) {
        if (current == nullptr) {
            return new TreeNode(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        } else {
            return current; // Duplicate values not allowed
        }

        // Update height of the current node
        current->height = 1 + std::max(getHeight(current->left), getHeight(current->right));

        // Perform balance check and rotations
        int balance = getBalance(current);

        // Left-Left case
        if (balance > 1 && value < current->left->data) {
            return rotateRight(current);
        }

        // Right-Right case
        if (balance < -1 && value > current->right->data) {
            return rotateLeft(current);
        }

        // Left-Right case
        if (balance > 1 && value > current->left->data) {
            current->left = rotateLeft(current->left);
            return rotateRight(current);
        }

        // Right-Left case
        if (balance < -1 && value < current->right->data) {
            current->right = rotateRight(current->right);
            return rotateLeft(current);
        }

        return current;
    }

    // Perform a right rotation
    TreeNode* rotateRight(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        // Update heights
        y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    // Perform a left rotation
    TreeNode* rotateLeft(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        // Update heights
        x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    // Get the height of a node
    int getHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    // Get the balance factor of a node
    int getBalance(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }
};

int main() {
    AVLTree avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    return 0;
}
```

## Conclusion

Balanced trees are essential for maintaining efficient data structures in various applications. Understanding AVL trees, Red-Black trees, and B-trees, along with their basic operations, is crucial for solving complex problems efficiently.