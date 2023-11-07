#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) { 
    *this = other; 
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        this->_stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

int RPN::evaluate(const std::string& expression) {
    std::istringstream tokens(expression);
    std::string token;

    while (tokens >> token) {
        if (isOperator(token)) {
            if (this->_stack.size() < 2) {
                throw std::runtime_error("Not enough operands");
            }
            double rhs = this->_stack.top();
            this->_stack.pop();
            double lhs = this->_stack.top();
            this->_stack.pop();

            if (token == "+") {
                this->_stack.push(lhs + rhs);
            } else if (token == "-") {
                this->_stack.push(lhs - rhs);
            } else if (token == "*") {
                this->_stack.push(lhs * rhs);
            } else if (token == "/") {
                if (rhs == 0) {
                    throw std::runtime_error("Division by zero");
                }
                this->_stack.push(lhs / rhs);
            } else if (token == "%") {
                if (rhs == 0) {
                    throw std::runtime_error("Modulo by zero");
                }
                this->_stack.push(fmod(lhs, rhs));
            }
        } else if (isNumber(token)) {
            this->_stack.push(std::stod(token));
        } else {
            throw std::runtime_error("ERROR");
        }
    }
    if (_stack.size() != 1) {
        throw std::runtime_error("ERROR");
    }

    return _stack.top();
}

bool RPN::isNumber(const std::string& token) {
    if (token.empty()) {
        return false;
    }
    for (size_t i = 0; i < token.length(); i++) {
        if (i == 0 && token[i] == '-') {
            continue;
        }
        if (!std::isdigit(token[i])) {
            return false;
        }
    }
    return true;
}

bool RPN::isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/" || token == "%";
}

bool RPN::validateToken(const std::string& token) {
    return isNumber(token) || isOperator(token);
}