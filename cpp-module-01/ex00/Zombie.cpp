#include "Zombie.hpp"

Zombie::Zombie()
{
	static int i = 0;
	if (name.empty())
	{
		name = "Zombie_" + std::to_string(i);
		i++;
	}
	std::cout << "Shiit! " << name << " is born!" << std::endl;
};

Zombie::~Zombie( void )
{
    std::cout << "Let's go! " << name << " is dead!" << std::endl;
}

Zombie::Zombie(std::string n_name)
{
	name = n_name;
    std::cout << "Shiit! " << name << " is born!" << std::endl;
}

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}