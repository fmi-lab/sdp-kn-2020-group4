#ifndef __SET_H
#define __SET_H

template <class T>
class Set
{
private:
    struct Node
    {
        T data;
        Node *next, *prev;
    };

    Node *first, *last;

public:
    Set();
    ~Set();

    void add(T data);
    void remove(T data);

    void print();
};

#include "set.cpp"

#endif