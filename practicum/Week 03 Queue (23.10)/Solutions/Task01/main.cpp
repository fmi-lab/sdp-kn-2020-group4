#include <iostream>

#include "queue.h"

int main()
{
    Queue<int> queue;

    queue.push(5);
    queue.push(4);
    queue.push(8);

    queue.print();

    std::cout << std::endl
              << "Pop" << std::endl;

    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;

    std::cout << std::endl
              << "End Pop" << std::endl;

    queue.print();

    return 0;
}