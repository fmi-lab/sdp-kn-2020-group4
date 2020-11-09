#include "task.h"

Task::Task(std::string task)
{
    this->task = task;
}

std::ostream &operator<<(std::ostream &out, const Task &task)
{
    out << task.getTask();

    return out;
}