#include "set.h"
#include "student.h"

int main()
{
    Set test;

    Comparable *std1 = new Student(1234);
    Comparable *std2 = new Student(2345);
    Comparable *std3 = new Student(1234);
    Comparable *std4 = new Student(1000);

    test.add(std1);
    test.add(std2);
    test.add(std3);
    test.add(std4);

    test.print();

    return 0;
}