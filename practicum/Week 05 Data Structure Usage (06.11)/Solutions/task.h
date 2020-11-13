#ifndef __TASK_H
#define __TASK_H

#include <iostream>
#include <string>

class Task
{
private:
    std::string name;
    std::string type;
    int hours;
    int priority;

public:
    Task(){};
    Task(std::string name, std::string type, int hours, int priority);

    std::string getName() const { return this->name; }
    std::string getType() const { return this->type; }
    int getHours() const { return this->hours; }
    int getPriority() const { return this->priority; }

    bool operator==(const Task &other) const;
    bool operator>(const Task &other) const;

    friend std::ostream &operator<<(std::ostream &out, const Task &task);
};

#endif