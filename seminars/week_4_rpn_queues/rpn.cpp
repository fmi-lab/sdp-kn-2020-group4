#include<iostream>
#include "rpn.h"
#include <string>

int main() {
    std::string test = "(3+4)*(8/2)";
    RPNParser rpn(test);
    std::cout << rpn.parse() << '\n';
    std::cout << rpn.solve();
    return 0;
}
