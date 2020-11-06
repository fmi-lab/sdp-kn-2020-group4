#ifndef __PATIENT_H
#define __PATIENT_H

#include <iostream>
#include <string>

class Patient
{
private:
    std::string name;

public:
    Patient(){};
    Patient(std::string name);

    std::string getName() const { return this->name; }

    friend std::ostream &operator<<(std::ostream &out, const Patient &patient);
};

#endif