#ifndef __SET_CPP
#define __SET_CPP

#include "set.h"

#include <iostream>

template <class T>
Set<T>::Set()
{
    first = nullptr;
    last = nullptr;
}

template <class T>
Set<T>::~Set()
{
    Set::Node *current = first,
              *temp = nullptr;

    while (current)
    {
        temp = current;
        current = current->next;

        delete temp;
    }
}

template <class T>
void Set<T>::add(T data)
{
    if (!first)
    {
        first = new Set::Node();
        first->data = data;

        last = first;
    }
    else
    {
        Set::Node *current = first;

        while (current)
        {
            if (current->data == data)
            {
                return;
            }
            else if (current->data > data)
            {
                break;
            }

            current = current->next;
        }

        Set::Node *temp = new Set::Node();
        temp->data = data;

        if (!current)
        {
            temp->prev = last;
            last->next = temp;
            last = temp;
        }
        else
        {
            temp->prev = current->prev;
            temp->next = current;

            if (current == first)
            {
                first = temp;
            }
            else
            {
                current->prev->next = temp;
            }

            current->prev = temp;
        }
    }
}

template <class T>
void Set<T>::print()
{
    Set::Node *current = first;

    while (current)
    {
        std::cout << current->data << std::endl;

        current = current->next;
    }
}

template <class T>
T Set<T>::Iterator::next()
{
    if (!hasNext())
    {
        throw std::out_of_range("Nil iterator");
    }

    Set<T>::Node *temp = current;

    current = current->next;

    return temp->data;
}

template <class T>
bool Set<T>::Iterator::hasNext()
{
    return current;
}

template <class T>
Set<T>::Iterator::Iterator(Node *_current) : current(_current) {}

template <class T>
typename Set<T>::Iterator Set<T>::begin()
{
    return Set<T>::Iterator(first);
}

#endif