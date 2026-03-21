#include "Zombie.hpp"

Zombie::Zombie()
{}

Zombie::~Zombie( void )
{
    std::cout << "Zombie " << name << " is destroyed!" << std::endl;
}

Zombie::Zombie(std::string n_name)
{
	name = n_name;
    std::cout << "Zombie " << name << " is destroyed!" << std::endl;
}

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string n_name)
{
	name = n_name;
}