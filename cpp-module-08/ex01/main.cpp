#include "Span.hpp"

int main()
{
	try
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "------- Second test -------" << std::endl;

	try
	{
		std::vector<int> var;
		Span sp1(3);

		var.push_back(6);
		var.push_back(3);
		var.push_back(17);

		sp1.addNumber(var.begin(), var.end());
		std::vector<int>::iterator it = var.begin();
		while (it < var.end())
		{
			std::cout << *it << " ";
			it++;
		}
		std::cout << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 1;

}