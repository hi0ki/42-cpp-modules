#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Usage: " << av[0] << " <numbers to sort>" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe pmergeMe(ac, av);
		pmergeMe.start();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}	