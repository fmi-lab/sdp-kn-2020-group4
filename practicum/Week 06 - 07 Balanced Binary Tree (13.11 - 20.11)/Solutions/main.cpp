#include <iostream>
#include <vector>

#include "tree.h"

int main()
{
    std::vector<int> elements = {1, 3, 5, 7, 9, 11, 13};

    Tree<int> tree = Tree<int>(elements, 7);

    tree.print();

    std::cout << std::endl << "Balanced: " << tree.isBalanced() << std::endl;

    return 0;
}