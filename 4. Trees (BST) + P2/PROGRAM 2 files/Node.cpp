#include "Node.h"

bool TreeNode::isLeaf() {
    if (right == nullptr && left == nullptr) {
        return true;
    }
    return false;
}