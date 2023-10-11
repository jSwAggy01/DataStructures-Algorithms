# AVL Trees

## Introduction
AVL trees, also known as Adelson-Velsky and Landis trees, are a self-balancing binary search tree (BST) data structure. They ensure that the tree remains balanced by maintaining a balance factor for each node, which is the difference in heights between its left and right subtrees. When this balance factor exceeds a certain limit (usually 1 or -1), rotations are performed to restore balance. AVL trees provide efficient searching, insertion, and deletion operations.

## Key Concepts

### 1. Balance Factor
- The balance factor of a node is defined as the height of its left subtree minus the height of its right subtree.
- It is used to determine the balance of a node.

### 2. Rotation Operations
- Rotations are tree restructuring operations used to maintain or restore the balance of an AVL tree.
- There are four types of rotations: 
    - Left Rotation (LL Rotation)
    - Right Rotation (RR Rotation)
    - Left-Right Rotation (LR Rotation)
    - Right-Left Rotation (RL Rotation)

### 3. AVL Tree Properties
- An AVL tree must satisfy the following properties:
    - The balance factor of every node is in the range [-1, 1].
    - The left and right subtrees of every node are themselves AVL trees.

## Basic Operations

### 1. Insertion
- Adding a new element to the AVL tree while maintaining its balance.
- After inserting a node, balance factors are updated, and rotations are performed if necessary to maintain balance.

### 2. Deletion
- Removing an element from the AVL tree while preserving its balanced structure.
- After deleting a node, balance factors are updated, and rotations are performed if necessary.

### 3. Searching
- Finding a specific element within the AVL tree efficiently.
- The binary search property of BSTs remains intact in AVL trees.

### 4. Traversal
- Visiting all elements in the AVL tree in a specific order, such as in-order or level-order traversal.

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
```

## Conclusion

AVL trees are self-balancing binary search trees that guarantee efficient searching, insertion, and deletion operations. Understanding AVL tree properties, balance factors, and rotation operations is crucial for solving complex problems efficiently.