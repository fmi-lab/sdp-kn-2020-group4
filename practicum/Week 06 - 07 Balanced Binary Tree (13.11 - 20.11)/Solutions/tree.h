#ifndef __TREE_H
#define __TREE_H

#include <iostream>
#include <vector>

template <class T>
class Tree
{
private:
    struct Node
    {
        T data;
        Node *left, *right;
    };

    Node *root;

    void addNode(Tree<T>::Node *rootNode, std::vector<T> elements, int start, int end);
    void deleteHelper(const Tree<T>::Node *);
    bool balanceHelper(const Tree<T>::Node *rootNode) const;
    int height(const Tree<T>::Node *rootNode) const;
    void printHelper(const Tree<T>::Node *) const;

public:
    Tree(std::vector<T> elements, int len);
    ~Tree();

    void push(T data);
    T pop();

    bool hasItems();

    bool isBalanced() const;
    void print() const;
};

#include "tree.cpp"

#endif