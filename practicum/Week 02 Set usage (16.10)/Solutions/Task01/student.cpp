#include "student.h"

Student::Student(int facultyNumber)
{
    this->facultyNumber = facultyNumber;
}

bool Student::operator==(const Student &other) const
{
    return this->facultyNumber == other.facultyNumber;
}

bool Student::operator>(const Student &other) const
{
    return this->facultyNumber > other.facultyNumber;
}

std::ostream &operator<<(std::ostream &out, const Student &student)
{
    out << std::endl
        << "Student: " << student.getFacultyNumber();

    return out;
}