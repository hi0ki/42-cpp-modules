#include "easyfind.hpp"

int main()
{
	std::vector<int> numbers;
	numbers.push_back(5);
	numbers.push_back(2);
	numbers.push_back(1);
	numbers.push_back(6);

	try
	{
		int index = easyfind(numbers, 2);
		std::cout << "The element found at index: " << index << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl; 
	}
	std::cout << "---------- second test ----------" << std::endl;
	try
	{
		int index = easyfind(numbers, -1);
		std::cout << "The element found at index: " << index << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl; 
	}
}