#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN::RPN(std::string argv)
{
    for (size_t i = 0; i < argv.size(); i++)
    {
        if (isdigit(argv[i]))
        {
            this->_stack.push(argv[i] - '0');
            i++;
        }
        else if (argv[i] == '+' || argv[i] == '-' || argv[i] == '*' || argv[i] == '/')
        {
            if (this->_stack.size() < 2)
                throw std::runtime_error("Error");
            this->operation(argv[i]);
            i++;
        }
        if (argv[i] == ' ' || i >= argv.size())
            continue;
        else
            throw std::runtime_error("Error");
    }
    if (this->_stack.size() != 1)
        throw std::runtime_error("Error");
    std::cout << this->_stack.top() << std::endl;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        this->_stack = other._stack;
    }
    return (*this);
}

RPN::~RPN() {}

// utils

void RPN::operation(char op)
{
    int b = this->_stack.top();
    this->_stack.pop();
    int a = this->_stack.top();
    this->_stack.pop();
    int result;

    switch (op)
    {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error: Division by zero");
            result = a / b;
            break;
        default:
            throw std::runtime_error("Error: Unknown operator");
            break;
    }
    this->_stack.push(result);
}