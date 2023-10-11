#include "BSTree.h"

/* PUBLIC MEMBER FUNCTIONS */

    BSTree::BSTree() {
        root = nullptr;
    }

    BSTree::~BSTree() {
        DestroyRecursive(root);
    }

    // BSTree destructor from https://stackoverflow.com/questions/34170164/destructor-for-binary-search-tree
    void BSTree::DestroyRecursive(TreeNode *node) {
        if (node) {
            DestroyRecursive(node->left);
            DestroyRecursive(node->right);
            delete node;
        }
    }

    void BSTree::insert(const string &newString) {
        TreeNode *newNode;

        // Case 1: Check for dupes, increment count
        if (search(newString) && getNode(newString)->count > 0) {
            ++getNode(newString)->count;
        }

        // Case 2: Check for existing tree
        else if (root == nullptr) {
            newNode = new TreeNode(1, newString);
            root = newNode;
        }
        
        // Case 3: Otherwise insert
        else {
            newNode = new TreeNode(1, newString);
            insert(root, newNode);
        }
    }

    void BSTree::insert(TreeNode *parent, TreeNode *nodeToInsert) {
        if (nodeToInsert->key < parent->key) {
            if (parent->left == nullptr) {
                parent->left = nodeToInsert;
            }
            else {
                insert(parent->left, nodeToInsert);
            }
        }
        else {
            if (parent->right == nullptr) {
                parent->right = nodeToInsert;
            }
            else {
                insert(parent->right, nodeToInsert);
            }
        }
    }

void BSTree::remove(const string& key) {
    remove(nullptr, root, key);
}

void BSTree::remove(TreeNode* parent, TreeNode* curr, const string& key) {
    string tempKey;
	TreeNode* suc = nullptr;

    if (curr == nullptr) {
        return;
    }

    if (curr->key == key) {

        // Case 1: Dupe exists, decrement count
		if (curr->count > 1) {
			--curr->count;
			return;
		}

        // Case 2: Leaf
        if (curr->left == nullptr && curr->right == nullptr) {
			if (parent == nullptr) {
				root = nullptr;
            }
			else if (parent->left == curr) {
				parent->left = nullptr;
            }
			else {
				parent->right = nullptr;
            }
		}

        // Case 3: Empty right child
        else if (curr->right == nullptr) {
			suc = curr;
			curr = curr->left;
			while (curr->right != nullptr) {
				curr = curr->right;
            }
			tempKey = curr->key;
            int tempcount = curr->count;
            remove(tempKey);
            suc->key = (tempKey);
            suc->count = tempcount;
			if (parent == nullptr) {
				root = suc->left;
            }
			else if (parent->left == suc) {
				parent->left = suc;
            }
			else {
				parent->right = suc;
            }
		} 

        // Case 4: Empty left child
        else if (curr->left == nullptr) {
			suc = curr;
			curr = curr->right;
			if (curr->left != nullptr) {
				curr = curr->left;
				tempKey = curr->key;
                int tempcount = curr->count;
                remove(tempKey);
                suc->key = (tempKey);
                suc->count = tempcount;
				if (parent == nullptr) {
					root = suc->right;
                }
				else if (parent->left == suc) {
					parent->left = suc;
                }
				else {
					parent->right = suc;
                }
			} 
            else {
				if (parent == nullptr) {
					root = suc->right;
                }
				else if (parent->left == suc) {
					parent->left = suc->right;
                }
				else {
					parent->right = suc->right;
                }
			}
		}

        // Case 5: Internal node with 2 children
        else {
			suc = curr->left;
			while (suc->right != nullptr) {
				suc = suc->right;
            }
			tempKey = suc->key;
			remove(tempKey);
			curr->key = tempKey;
		}
		return;
	} 
    else if (curr->key < key) {
        remove(curr, curr->right, key);
    }
	else {
        remove(curr, curr->left, key);
    }
}

    // Public helper function for search :)
    bool BSTree::search(const string &key) const {
        return search(root, key);
    }

    // Returns true if key is found in tree
    bool BSTree::search(TreeNode *node, const string &key) const {
        if (node != nullptr) {
            if (key == node->key) {
                return true;
            }
            else if (key < node->key) {
                return search(node->left, key);
            }
            else {
                return search(node->right, key);
            }
        }
        return false;
    }

    // Helper function
    TreeNode* BSTree::getNode(const string &key) const {
        // cout << "GETNODE ACTUAL: " << getNode(root, key)->key << endl;
        return getNode(root, key);
    }

    // UTILITY - Returns the requested node
    TreeNode* BSTree::getNode(TreeNode *node, const string &key) const {
        if (node != nullptr) {
            if (key == node->key) {
                // cout << "GETNODE: " << node->key << endl;
                return node;
            }
            else if (key < node->key) {
                return getNode(node->left, key);
            }
            else {
                return getNode(node->right, key);
            }
        }

        return nullptr;
    }

    string BSTree::largest() const {
        TreeNode *curr = root;
        if (root == nullptr) {
            return "";
        }
        while (curr->right != nullptr) {
            curr = curr->right;
        }
        return curr->key;
    }

    string BSTree::smallest() const {
        TreeNode *curr = root;
        if (root == nullptr) {
            return "";
        }
        while (curr->left != nullptr) {
            curr = curr->left;
        }
        return curr->key;
    }

    int BSTree::height(const string &key) const {
        TreeNode *node = getNode(key);
        return height(node);
    }

    int BSTree::height(TreeNode *node) const {
        int leftHeight;
        int rightHeight;

        if (node == nullptr) {
            return -1;
        }

        leftHeight = height(node->left);
        rightHeight = height(node->right);
        
        return 1 + max(leftHeight, rightHeight);
    }

    TreeNode* BSTree::getParent(TreeNode *node) {
        return getParent(root, node);
    }

    void BSTree::preOrder() const {
        preOrder(root);
    }

    void BSTree::postOrder() const {
        postOrder(root);
    }

    void BSTree::inOrder() const {
        inOrder(root);
    }

// /* PRIVATE MEMBER FUNCTIONS */

    void BSTree::preOrder(TreeNode *node) const {
        if (node != nullptr) {
            cout << node->key << "(" << node->count << "), ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void BSTree::postOrder(TreeNode *node) const {
        if (node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->key << "(" << node->count << "), ";
        }
    }

    void BSTree::inOrder(TreeNode *node) const {
        if (node == nullptr) {
            return;
        }
        inOrder(node->left);
        cout << node->key << "(" << node->count << "), ";
        inOrder(node->right);
    }

    bool BSTree::ReplaceChild(TreeNode *parent, TreeNode *currChild, TreeNode *newChild) {
        if (parent->left != currChild && parent->right != currChild) {
            return false;
        }
        if (parent->left == currChild) {
            parent->left = newChild;
        }
        else {
            parent->right = newChild;
        }
        if (newChild != nullptr) {
            newChild->parent = parent;
        }
        return true;
    }

    TreeNode* BSTree::getParent(TreeNode *subTreeRoot, TreeNode *node) {
        if (subTreeRoot == nullptr) {
            return nullptr;
        }
        if ((subTreeRoot->left == node) || (subTreeRoot->right == node)) {
            return subTreeRoot;
        }
        if (node->key < subTreeRoot->key) {
            return getParent(subTreeRoot->left, node);
        }
        return getParent(subTreeRoot->right, node);
    }