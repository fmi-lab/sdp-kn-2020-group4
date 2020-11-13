#ifndef __QUEUE_CPP
#define __QUEUE_CPP

#include <iostream>

#include "queue.h"

template <class T>
Queue<T>::Queue()
{
    first = nullptr;
    last = nullptr;
}

template <class T>
Queue<T>::~Queue()
{
    Queue::Node *current = first,
                *temp = nullptr;

    while (current)
    {
        temp = current;
        current = current->next;

        delete temp;
    }
}

template <class T>
void Queue<T>::push(T data)
{
    if (!last)
    {
        last = new Queue::Node();
        last->data = data;

        first = last;
    }
    else
    {
        Queue::Node *temp = new Queue::Node();
        temp->data = data;
        temp->prev = last;

        last->next = temp;

        last = temp;
    }
}

template <class T>
T Queue<T>::pop()
{
    T data = first->data;

    Queue::Node *current = first;

    first = first->next;

    delete current;

    return data;
}

template <class T>
bool Queue<T>::hasItems()
{
    return first;
}

template <class T>
void Queue<T>::print()
{
    Queue::Node *current = first;

    while (current)
    {
        std::cout << current->data << std::endl;

        current = current->next;
    }
}

#endif