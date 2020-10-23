#ifndef __SET_H
#define __SET_H

#include "comparable.h"

class Set
{
private:
    struct Node
    {
        Comparable *data;
        Node *next, *prev;
    };

    Node *first, *last;

public:
    Set();
    ~Set();

    void add(Comparable *data);
    void remove(Comparable *data);

    void print();
};

#endif