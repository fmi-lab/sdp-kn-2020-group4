#include "bstree.h"

BSTree::BSTree():root{nullptr} {}

bool BSTree::empty() const {
    return !root;
}

bool BSTree::member(const int& element) const {
    return member_helper(element, root);
}

bool BSTree::member_helper(const int& element, const BTreeNode* rootNode) const {
    if (!rootNode) {
        return false;
    }
    if (element == rootNode->data) {
        return true;
    }
    if(element < rootNode->data) {
        return member_helper(element, rootNode->left);
    } else {
        return member_helper(element, rootNode->right);
    }
}

void BSTree::add_iter(const int& element) {
    if(empty()) {
        root = new BSTree::BTreeNode{element};
    } else {
        BSTree::BTreeNode* current = root;
        while(current) {
            if(element < current->data && current->left) {
                current = current->left;
            } else if (element < current->data && !current->left){
                current->left = new BSTree::BTreeNode{element};
            } else if(element > current->data && current->right) {
                current = current->right;
            } else {
                current->right = new BSTree::BTreeNode{element};
            }
        }
    }
}

void BSTree::add_rec(const int& element) {
    add_helper(element, root);
}

void BSTree::add_helper(const int& element, BTreeNode*& rootNode) {
    if(!rootNode) {
         rootNode = new BSTree::BTreeNode{element};
    } else {
        if(element < rootNode->data) {
            add_helper(element, rootNode->left);
        } else {
            add_helper(element, rootNode->right);
        }
    }
}

void BSTree::print_helper(const BTreeNode* rootNode) const {
    if(!rootNode) {
        return;
    }
    print_helper(rootNode->left);
    std::cout << rootNode->data << " ";
    print_helper(rootNode->right);
}

int BSTree::height() const {
    return height_helper(root);
}

int BSTree::height_helper(const BTreeNode* rootNode) const {
    // height ::= max(height(leftSubTree), height(rightSubTree)) + 1
    if(!rootNode) {
        return 0;
    }
    return std::max(height_helper(rootNode->left), height_helper(rootNode->right)) + 1;
}

void BSTree::print() const {
    // We are going to iterate the tree following the Left-Root-Right strategy
    print_helper(root);
}