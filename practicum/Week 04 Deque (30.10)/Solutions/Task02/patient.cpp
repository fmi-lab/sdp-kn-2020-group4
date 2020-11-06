#include "patient.h"

Patient::Patient(std::string name)
{
    this->name = name;
}

std::ostream &operator<<(std::ostream &out, const Patient &patient)
{
    out << patient.getName();

    return out;
}