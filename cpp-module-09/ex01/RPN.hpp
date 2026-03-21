#pragma once

#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<int> _stack;
	public:
		RPN();
		RPN(std::string argv);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
		// utils
		void operation(char op);
};