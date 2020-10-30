#ifndef __TASK_H
#define __TASK_H

#include <iostream>
#include <string>

class Task
{
private:
    std::string task;

public:
    Task(){};
    Task(std::string task);

    std::string getTask() const { return this->task; }

    friend std::ostream &operator<<(std::ostream &out, const Task &task);
};

#endif