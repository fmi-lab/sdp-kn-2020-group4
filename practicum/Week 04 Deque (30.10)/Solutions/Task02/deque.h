#ifndef __QUEUE_H
#define __QUEUE_H

template <class T>
class Deque
{
private:
    struct Node
    {
        T data;
        Node *next, *prev;
    };

    Node *first, *last;

public:
    Deque();
    ~Deque();

    void push_front(T data);
    void push_back(T data);
    T pop_front();
    T pop_back();

    bool hasItems();

    void print();
};

#include "deque.cpp"

#endif