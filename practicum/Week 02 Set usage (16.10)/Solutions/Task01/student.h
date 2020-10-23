#ifndef __STUDENT_H
#define __STUDENT_H

#include <iostream>

class Student
{
private:
    int facultyNumber;

public:
    Student(){};
    Student(int facultyNumber);

    bool operator==(const Student &other) const;
    bool operator>(const Student &other) const;
    friend std::ostream &operator<<(std::ostream &out, const Student &student);

    int getFacultyNumber() const { return this->facultyNumber; }
};

#endif