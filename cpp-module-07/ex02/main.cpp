#include "Array.hpp"

int main()
{
	try
	{
		Array <std::string>arr(1);
		arr[0] = "42";
		std::cout << arr[0] << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "------------------" << std::endl;
	
	try
	{
		Array <int>arr(1);
		arr[0] = 20;
		std::cout << arr[0] << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "-------err--------" << std::endl;
	try
	{
		Array <int>arr(1);
		arr[0] = 20;
		std::cout << arr[-1] << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}