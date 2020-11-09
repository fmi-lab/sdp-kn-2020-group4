#include<vector>
#include "bstree.h"

int main() {
    std::vector<int> testData {7,5,6,4,9,8,10};
    BSTree t;
    for(int elem: testData) {
        t.add_rec(elem);
    }
    t.print();
    std::cout << t.height();
}