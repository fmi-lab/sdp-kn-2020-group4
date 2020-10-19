#ifndef __STACK_HH__
#define __STACK_HH__

#include<iostream>
#include<vector>

class Stack {
    std::vector<int> container;
    int topOfStack;
    public:
    Stack();
    void push(const int& element);
    int pop();
    int top() const;
    size_t size() const;
    bool empty() const;
};
#endif
