#ifndef __DEVELOPER_H
#define __DEVELOPER_H

#include <iostream>
#include <string>

#include "queue.h"
#include "task.h"

class Developer
{
private:
    std::string name;
    std::string spec;
    int workingHours;
    std::string level;

    int remainingHours;
    Queue<Task> tasks;

public:
    Developer(){};
    Developer(std::string name, std::string spec, int workingHours, std::string level);

    bool addTask(Task task);
    void print();

    std::string getName() const { return this->name; }
    std::string getSpec() const { return this->spec; }
    int getWorkingHours() const { return this->workingHours; }
    std::string getLevel() const { return this->level; }
    Queue<Task> getTasks() const { return this->tasks; }

    bool operator==(const Developer &other) const;
    bool operator>(const Developer &other) const;

    friend std::ostream &operator<<(std::ostream &out, const Developer &developer);
};

#endif