#include "set.h"

int main()
{
    Set *test = new Set();

    test->add(3);
    test->add(3);
    test->add(4);
    test->add(4);
    test->add(3);
    test->add(4);

    test->print();

    return 0;
}