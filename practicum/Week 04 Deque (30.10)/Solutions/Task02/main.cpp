#include <iostream>

#include "deque.h"
#include "patient.h"

int main()
{
    int doctors;
    std::string patient;
    char emergency;
    Deque<Patient> patients;

    std::cout << "Enter patients (to stop enter q)" << std::endl;

    while (true)
    {
        std::cout << "Enter patient name: ";
        std::cin >> patient;

        if (patient == "q")
        {
            break;
        }

        std::cout << "Is it emergency? (y/n)";
        std::cin >> emergency;

        if (emergency == 'y')
        {
            patients.push_front(Patient(patient));
        }
        else
        {
            patients.push_back(Patient(patient));
        }
    }

    std::cout << "Enter number of doctors: ";
    std::cin >> doctors;

    int currentDoctor = 1;

    while (patients.hasItems())
    {
        std::cout << std::endl
                  << "Doctor " << currentDoctor << " checks patient " << patients.pop_front();

        if (++currentDoctor > doctors)
        {
            currentDoctor = 1;
        }
    }

    return 0;
}