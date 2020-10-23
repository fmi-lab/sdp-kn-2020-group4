#include <iostream>

#include "comparable.h"

int Comparable::compareTo(Comparable *other)
{
    // Throwing exception instead of default implementations is usually better approach.
    return 0;
}

void Comparable::print()
{
    // Throwing exception instead of default implementations is usually better approach.
    std::cout << "Default print";
}