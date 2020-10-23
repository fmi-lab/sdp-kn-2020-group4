#include <iostream>

#include "student.h"

Student::Student(int facultyNumber)
{
    this->facultyNumber = facultyNumber;
}

int Student::compareTo(Comparable *other)
{
    Student *b = dynamic_cast<Student *>(other);

    if (this->facultyNumber == b->getFacultyNumber())
    {
        return 0;
    }
    else if (this->facultyNumber < b->getFacultyNumber())
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

void Student::print()
{
    std::cout << "Student: " << this->facultyNumber << std::endl;
}