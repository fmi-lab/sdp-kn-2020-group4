#include "task.h"

Task::Task(std::string task)
{
    std::size_t dateEnd = task.find("_");
    std::size_t timeEnd = task.find("_", dateEnd + 1);

    date = task.substr(0, dateEnd);
    time = task.substr(dateEnd + 1, timeEnd);
    workDone = task.substr(timeEnd);
}

bool Task::operator==(const Task &other) const
{
    return this->date == other.date;
}

bool Task::operator>(const Task &other) const
{
    return this->date > other.date;
}

std::ostream &operator<<(std::ostream &out, const Task &task)
{
    out << std::endl
        << "Task date: " << task.getDate();

    return out;
}