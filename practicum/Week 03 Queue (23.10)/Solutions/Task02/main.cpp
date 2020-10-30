#include <iostream>

#include "queue.h"
#include "task.h"

int main()
{
    int workers;
    std::string task;
    Queue<Task> queue;

    std::cout << "Enter tasks (to stop enter q)" << std::endl;

    while (true)
    {
        std::cout << "Enter task: ";
        std::cin >> task;

        if (task == "q")
        {
            break;
        }

        queue.push(task);
    }

    std::cout << "Enter number of workers: ";
    std::cin >> workers;

    int currentWorker = 1;

    while (queue.hasItems())
    {
        std::cout << std::endl
                  << "Worker " << currentWorker << " works on task " << queue.pop();

        if (++currentWorker > workers)
        {
            currentWorker = 1;
        }
    }

    return 0;
}