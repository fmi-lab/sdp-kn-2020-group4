#ifndef __LIST_H
#define __LIST_H

#include "set.h"

template <class T>
class List
{
private:
    struct Node
    {
        T data;
        Node *next, *prev;
    };

    Node *first, *last;

public:
    List();
    ~List();

    void addLast(T data);
    void addFirst(T data);
    void remove(T data);

    void print();

    Set<T> toSet();
};

#include "list.cpp"

#endif