#include "stack.h"

Stack::Stack(): topOfStack{-1} {}

void Stack::push(const int& element) {
    container.push_back(element);
    topOfStack++;
}

int Stack::pop() {
    if(topOfStack == -1) {
        throw std::out_of_range("No more elements!");
    }
    int removedElement = container[topOfStack--];
    container.pop_back();
    return removedElement;
}

int Stack::top() const {
    return container[topOfStack];
}

size_t Stack::size() const {
    return container.size();
}

bool Stack::empty() const {
    return container.empty();
}
