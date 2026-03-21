#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl obj;

	if (ac < 2)
		std::cerr << "Error: Please provide a level argument." << std::endl;
	else if (ac > 2)
		std::cerr << "Error: Too many arguments." << std::endl;
	else
	{
		std::string level = av[1];
		obj.complain(level);
	}
}