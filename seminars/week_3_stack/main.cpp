#include "stack.h"
#include<stack>

int fibb(int n) {
    if(n<=2) {
        return 1;
    }
    return fibb(n-1) + fibb(n-2);
}

int fibbStack(int n) {
    Stack s;
    s.push(1);
    s.push(1);
    while( n > 2 ) {
        int first = s.top();
        s.pop();
        int second = s.top();
        s.pop();
        s.push(first);
        s.push(first + second);
        n--;       
    }
    return s.top();
}

struct State {
    int last;
    int previous;
    int iterNum;
};

int fibbStackState(int n) {
    std::stack<State> s;
    s.push({1,0,1});
    while( n > 1 ) {
        auto [last, previous, iterNum] = s.top();
        s.pop();
        s.push({(last + previous), last, iterNum++});
        n--;
    }
    return s.top().last;
}

// 1 1 2 3 5 8
int main() {
    // Stack s;
    // std::vector<int> testElements = { 2, 3, 4, 12, 21 };
    // for(int element :testElements) {
    //     s.push(element);
    // }
    // while(!s.empty()) {
    //     std::cout << s.top() << " ";
    //     s.pop();
    // }
    // std::cout << fibbStack(5);
    std::cout << fibbStackState(5);
    return 0;
}
