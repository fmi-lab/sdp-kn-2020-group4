#include "set.h"
#include "student.h"

int main()
{
    Set<int> test;

    test.add(8);
    test.add(3);
    test.add(5);
    test.add(4);
    test.add(3);
    test.add(4);
    test.add(1);

    test.print();

    Set<Student> test2;

    test2.add(Student(1234));
    test2.add(Student(2543));
    test2.add(Student(1234));
    test2.add(Student(1000));

    test2.print();

    return 0;
}