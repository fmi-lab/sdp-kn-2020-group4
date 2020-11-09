#ifndef __QUEUE_H
#define __QUEUE_H

template <class T>
class Queue
{
private:
    struct Node
    {
        T data;
        Node *next, *prev;
    };

    Node *first, *last;

public:
    Queue();
    ~Queue();

    void push(T data);
    T pop();

    void print();
};

#include "queue.cpp"

#endif