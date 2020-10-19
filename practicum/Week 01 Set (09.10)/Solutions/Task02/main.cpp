#include "set.h"

int main()
{
    Set *test = new Set();

    test->add(8);
    test->add(3);
    test->add(5);
    test->add(4);
    test->add(3);
    test->add(4);
    test->add(1);

    test->print();

    return 0;
}