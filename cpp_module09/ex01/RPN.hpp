#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cctype>
#include <stdexcept>

class RPN
{
private:
    std::stack<double> _stack;
    bool isNumber(const std::string& token);
    bool isOperator(const std::string& token);
    bool validateToken(const std::string& token);

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    int evaluate(const std::string& expression);
};

#endif