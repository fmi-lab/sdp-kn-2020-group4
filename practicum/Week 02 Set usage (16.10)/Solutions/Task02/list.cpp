#ifndef __LIST_CPP
#define __LIST_CPP

#include "list.h"

#include <iostream>

template <class T>
List<T>::List()
{
    first = nullptr;
    last = nullptr;
}

template <class T>
List<T>::~List()
{
    List::Node *current = first,
               *temp = nullptr;

    while (current)
    {
        temp = current;
        current = current->next;

        delete temp;
    }
}

template <class T>
void List<T>::addFirst(T data)
{
    if (!first)
    {
        this->first = new List::Node();
        first->data = data;

        last = first;
    }
    else
    {
        List::Node *temp = new List::Node();
        temp->data = data;
        temp->next = first;

        first->prev = temp;

        first = temp;
    }
}

template <class T>
void List<T>::addLast(T data)
{
    if (!last)
    {
        last = new List::Node();
        last->data = data;

        first = last;
    }
    else
    {
        List::Node *temp = new List::Node();
        temp->data = data;
        temp->prev = last;

        last->next = temp;

        last = temp;
    }
}

template <class T>
void List<T>::remove(T data)
{
    List::Node *current = first;

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
void List<T>::print()
{
    List::Node *current = first;

    while (current)
    {
        std::cout << current->data << " ";

        current = current->next;
    }
}

template <class T>
Set<T> List<T>::toSet()
{
    Set<T> set;

    List::Node *current = first;

    while (current)
    {
        set.add(current->data);

        current = current->next;
    }

    return set;
}

#endif