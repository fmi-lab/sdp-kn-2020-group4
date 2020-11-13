#include "developer.h"
#include "queue.h"
#include "task.h"

Developer::Developer(std::string name, std::string spec, int workingHours, std::string level)
{
    this->name = name;
    this->spec = spec;
    this->workingHours = workingHours;
    this->remainingHours = workingHours;
    this->level = level;
}

bool Developer::addTask(Task task)
{
    int hours = task.getHours();

    if (level == "Junior")
    {
        hours *= 4;
    }
    else if (level == "Middle")
    {
        hours *= 2;
    }

    if (spec != task.getType() || this->remainingHours < task.getHours())
    {
        return false;
    }

    tasks.push(task);
    remainingHours -= hours;

    return true;
}

void Developer::print()
{
    std::cout << name << " "
              << level << " "
              << spec << " "
              << workingHours << std::endl;

    tasks.print();

    std::cout << std::endl;
}

bool Developer::operator==(const Developer &other) const
{
    return this->name == other.getName();
}

bool Developer::operator>(const Developer &other) const
{
    return this->name > other.getName();
}

std::ostream &operator<<(std::ostream &out, const Developer &developer)
{
    out << developer.getName() << " "
        << developer.getLevel() << " "
        << developer.getSpec() << " "
        << developer.getWorkingHours();

    return out;
}