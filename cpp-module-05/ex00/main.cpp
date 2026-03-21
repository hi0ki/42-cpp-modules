#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	// example 1
	try
	{
		Bureaucrat b1("b1", 1);
		b1.decrementGrade();
		std::cout << b1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	// example 2
	std::cout << "----------------" << std::endl;
	try
	{
		Bureaucrat b2("b2", 150);
		b2.decrementGrade();
		std::cout << b2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	// example 3
	std::cout << "----------------" << std::endl;
	try
	{
		Bureaucrat b3("b3", 0);
		b3.incrementGrade();
		std::cout << b3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}