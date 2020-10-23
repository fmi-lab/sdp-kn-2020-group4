#include "set.h"

#include <iostream>

Set::Set()
{
    first = nullptr;
    last = nullptr;
}

Set::~Set()
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

void Set::add(Comparable *data)
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
            int compared = current->data->compareTo(data);

            if (compared == 0)
            {
                return;
            }
            else if (compared > 0)
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

void Set::print()
{
    Set::Node *current = first;

    while (current)
    {
        current->data->print();

        current = current->next;
    }
}