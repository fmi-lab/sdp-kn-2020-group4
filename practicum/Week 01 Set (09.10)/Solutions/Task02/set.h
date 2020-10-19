#ifndef __SET_H
#define __SET_H

class Set
{
private:
    struct Node
    {
        int data;
        Node *next, *prev;
    };

    Node *first, *last;

    bool isAdded(int data);

public:
    Set();
    ~Set();

    void add(int data);
    void remove(int data);

    void print();
};

#endif