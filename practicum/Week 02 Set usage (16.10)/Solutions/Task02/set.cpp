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
void Set<T>::remove(T data)
{
    Set::Node *current = first;

    while (current)
    {
        if (current->data == data)
        {

            if (!current->next)
            {
                last = current->prev;
            }
            else if (!current->prev)
            {
                first = current->next;
            }
            else
            {
                current->next->prev = current->prev;
                current->prev->next = current->next;
            }
        }

        current = current->next;
    }
}

template <class T>
void Set<T>::print()
{
    Set::Node *current = first;

    while (current)
    {
        std::cout << current->data << " ";

        current = current->next;
    }
}

#endif