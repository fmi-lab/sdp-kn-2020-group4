#ifndef __STUDENT_H
#define __STUDENT_H

#include "comparable.h"

class Student : public Comparable
{
private:
    int facultyNumber;

public:
    Student(int facultyNumber);

    virtual int compareTo(Comparable *other);
    virtual void print();

    int getFacultyNumber() const { return this->facultyNumber; }
};

#endif