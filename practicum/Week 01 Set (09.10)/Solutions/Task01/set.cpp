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

    while (current != nullptr)
    {
        temp = current;
        current = current->next;

        delete temp;
    }
}

bool Set::isAdded(int data) {
    Set::Node *current = first;

    while (current != nullptr)
    {
        if (current->data == data)
        {
            return true;
        }

        current = current->next;
    }

    return false;
}

void Set::add(int data)
{
    if (first == nullptr)
    {
        first = new Set::Node();
        first->data = data;

        last = first;
    }
    else
    {
        if (isAdded(data)) {
            return;
        }

        Set::Node *temp = new Set::Node();
        temp->data = data;
        temp->prev = last;

        last->next = temp;
        last = temp;
    }
}

void Set::print()
{
    Set::Node *current = first;

    while (current != nullptr)
    {
        std::cout << current->data << " ";

        current = current->next;
    }
}