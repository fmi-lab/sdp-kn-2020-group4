#ifndef __TASK_H
#define __TASK_H

#include <iostream>
#include <string>

class Task
{
private:
    std::string date;
    std::string time;
    std::string workDone;

public:
    Task(){};
    Task(std::string task);

    bool operator==(const Task &other) const;
    bool operator>(const Task &other) const;
    friend std::ostream &operator<<(std::ostream &out, const Task &student);

    std::string getDate() const { return this->date; }
};

#endif