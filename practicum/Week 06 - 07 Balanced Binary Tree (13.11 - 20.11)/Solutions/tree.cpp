#ifndef __TREE_CPP
#define __TREE_CPP

#include <iostream>
#include <cmath>

#include "tree.h"

template <class T>
void Tree<T>::addNode(Tree<T>::Node *rootNode, std::vector<T> elements, int start, int end)
{
    if (end == start)
    {
        rootNode->data = elements[start];

        return;
    }

    if (start == end - 1)
    {
        rootNode->data = elements[end];

        rootNode->left = new Tree<T>::Node();
        rootNode->left->data = elements[start];

        return;
    }

    int mid = (start + end) / 2;

    rootNode->data = elements[mid];

    addNode(rootNode->left = new Tree<T>::Node(), elements, start, mid - 1);
    addNode(rootNode->right = new Tree<T>::Node(), elements, mid + 1, end);
}

template <class T>
void Tree<T>::deleteHelper(const Tree<T>::Node *rootNode)
{
    if (!rootNode)
    {
        return;
    }

    deleteHelper(rootNode->left);
    deleteHelper(rootNode->right);

    delete rootNode;
}

template <class T>
bool Tree<T>::balanceHelper(const Tree<T>::Node *rootNode) const
{
    if (!rootNode)
    {
        return true;
    }

    // Check for order
    if ((rootNode->left && rootNode->data < rootNode->left->data) ||
        (rootNode->right && rootNode->data > rootNode->right->data))
    {
        return false;
    }

    // Check for height
    int leftHeight, rightHeight;

    leftHeight = height(rootNode->left);
    rightHeight = height(rootNode->right);

    if (std::abs(leftHeight - rightHeight) <= 1 &&
        balanceHelper(rootNode->left) &&
        balanceHelper(rootNode->right))
    {
        return true;
    }

    return false;
}

template <class T>
int Tree<T>::height(const Tree<T>::Node *rootNode) const
{
    if (!rootNode)
    {
        return 0;
    }

    return 1 + std::max(height(rootNode->left), height(rootNode->right));
}

template <class T>
void Tree<T>::printHelper(const Tree<T>::Node *rootNode) const
{
    if (!rootNode)
    {
        return;
    }

    printHelper(rootNode->left);

    std::cout << rootNode->data << " ";

    printHelper(rootNode->right);
}

template <class T>
Tree<T>::Tree(std::vector<T> elements, int len)
{
    addNode(root = new Tree<T>::Node(), elements, 0, len - 1);
}

template <class T>
Tree<T>::~Tree()
{
    deleteHelper(root);
}

template <class T>
bool Tree<T>::isBalanced() const
{
    return balanceHelper(root);
}

template <class T>
void Tree<T>::print() const
{
    printHelper(root);
}

#endif