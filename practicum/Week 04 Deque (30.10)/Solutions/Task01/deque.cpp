#ifndef __DEQUE_CPP
#define __DEQUE_CPP

#include <iostream>

#include "deque.h"

template <class T>
Deque<T>::Deque()
{
    first = nullptr;
    last = nullptr;
}

template <class T>
Deque<T>::~Deque()
{
    Deque::Node *current = first,
                *temp = nullptr;

    while (current)
    {
        temp = current;
        current = current->next;

        delete temp;
    }
}

template <class T>
void Deque<T>::push_front(T data)
{
    if (!first)
    {
        first = new Deque::Node();
        first->data = data;

        last = first;
    }
    else
    {
        Deque::Node *temp = new Deque::Node();
        temp->data = data;
        temp->next = first;

        first->prev = temp;

        first = temp;
    }
}

template <class T>
void Deque<T>::push_back(T data)
{
    if (!last)
    {
        last = new Deque::Node();
        last->data = data;

        first = last;
    }
    else
    {
        Deque::Node *temp = new Deque::Node();
        temp->data = data;
        temp->prev = last;

        last->next = temp;

        last = temp;
    }
}

template <class T>
T Deque<T>::pop_front()
{
    T data = first->data;

    Deque::Node *current = first;

    first = first->next;
    first->prev = nullptr;

    delete current;

    return data;
}

template <class T>
T Deque<T>::pop_back()
{
    T data = last->data;

    Deque::Node *current = last;

    last = last->prev;
    last->next = nullptr;

    delete current;

    return data;
}

template <class T>
void Deque<T>::print()
{
    Deque::Node *current = first;

    while (current)
    {
        std::cout << current->data << " ";

        current = current->next;
    }
}

#endif