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

    bool isAdded(T data);

public:
    Set();
    ~Set();

    void add(T data);
    void remove(T data);

    void print();

    class Iterator
    {
    private:
        Node *current;

    public:
        Iterator(Node *_current);

        T next();
        bool hasNext();
    };

    Iterator begin();
};

#include "set.cpp"

#endif