#ifndef __RPN_Parser__
#define __RPN_Parser__
#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<map>
#include<functional>

class RPNParser {
    std::string originalExpression;
    std::string parsedExpression;
    std::map<char, int> opsPriority;

    // utils
    void initOperationsPriority() {
        opsPriority.insert({
            {'*', 2},
            {'/', 2},
            {'%', 2},
            {'+', 1},
            {'-', 1}
        });
    }

    std::function<int(const int&, const int&)> buildOperation(char& operation) const {
        switch(operation) {
            case '+': {
                return [](const int& a, const int& b) -> int { return a + b;};
            }
            case '-': {
                return [](const int& a, const int& b) -> int { return a - b;};
            }
            case '*': {
                return [](const int& a, const int& b) -> int { return a * b;};
            }
            case '/': {
                return [](const int& a, const int& b) -> int { return a / b;};
            }
            case '%': {
                return [](const int& a, const int& b) -> int { return a % b;};
            }
            default: throw std::invalid_argument("No such operation!");
        }
    }

    // checkers
    bool isOperation(const char& symbol) const {
        return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '%';
    }

    bool isOpenParenthesis(const char& symbol) const {
        return symbol == '(';
    }

    bool isClosingParenthesis(const char& symbol) const {
        return symbol == ')';
    }

    bool isNumber(const char& symbol) const {
        return symbol >= '0' && symbol <= '9';
    }

    bool isParenthesis(const char& symbol) const {
        return isOpenParenthesis(symbol) || isClosingParenthesis(symbol);
    }

    void processOperation(const char& currentOperation, std::stack<char>& operations) {
        int currentOpPriority = opsPriority[currentOperation];
        if (!operations.empty()) {
            int lastOpPriority = opsPriority[operations.top()];
            while(!operations.empty() && currentOpPriority < lastOpPriority) {
                parsedExpression.push_back(operations.top());
                operations.pop();
            }
        }
        operations.push(currentOperation);
    }

    void processParenthesis(const char& parenthesis, std::stack<char>& operations) {
        if (isOpenParenthesis(parenthesis)) {
            operations.push(parenthesis);
        } else {
            while(!operations.empty() && !isOpenParenthesis(operations.top())) {
                parsedExpression.push_back(operations.top());
                operations.pop();
            }
            if(!operations.empty() && isOpenParenthesis(operations.top())) {
                operations.pop();
            }
        }
    }
    public:
    RPNParser() = delete;
    RPNParser(const std::string& expression): originalExpression{expression} {
        initOperationsPriority();
    }

    std::string parse() {
        std::stack<char> operations;
        for (auto symbol : originalExpression) {
            if(isOperation(symbol)) {
                processOperation(symbol, operations);
            } else if(isParenthesis(symbol)) {
                processParenthesis(symbol,operations);
            } else {
                parsedExpression.push_back(symbol);
            }
        }

        while(!operations.empty()) {
            parsedExpression.push_back(operations.top());
            operations.pop();
        }

        return parsedExpression;
    }

    int solve() const {
        std::stack<int> numbers;
        try {
            for(char symbol : parsedExpression) {
                if (isNumber(symbol)) {
                    numbers.push(symbol - '0');
                } else if (isOperation(symbol)) {
                    int second = numbers.top();
                    numbers.pop();
                    int first = numbers.top();
                    numbers.pop();

                    int result = buildOperation(symbol)(first, second);
                    numbers.push(result);
                }
            }
            return numbers.top();
        } catch(std::invalid_argument& e) {
                    std::cout << e.what();
                    return 0;
        }
    }
};
#endif
