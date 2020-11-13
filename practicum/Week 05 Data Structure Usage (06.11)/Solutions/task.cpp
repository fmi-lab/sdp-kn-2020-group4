#include "task.h"

Task::Task(std::string name, std::string type, int hours, int priority)
{
    this->name = name;
    this->type = type;
    this->hours = hours;
    this->priority = priority;
}

bool Task::operator==(const Task &other) const
{
    return this->name == other.getName();
}

bool Task::operator>(const Task &other) const
{
    return this->priority > other.getPriority();
}

std::ostream &operator<<(std::ostream &out, const Task &task)
{
    out << task.getName() << " "
        << task.getType() << " "
        << task.getPriority() << " "
        << task.getHours();

    return out;
}