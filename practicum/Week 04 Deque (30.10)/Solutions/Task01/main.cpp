#include <iostream>

#include "deque.h"

int main()
{
    Deque<int> queue;

    queue.push_back(5);
    queue.push_back(4);
    queue.push_front(8);
    queue.push_front(3);

    queue.print();

    std::cout << std::endl
              << "Pop" << std::endl;

    std::cout << queue.pop_back() << std::endl;
    std::cout << queue.pop_front() << std::endl;

    std::cout << std::endl
              << "End Pop" << std::endl;

    queue.print();

    return 0;
}