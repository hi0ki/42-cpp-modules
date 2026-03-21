#include "HumanB.hpp"

HumanB::HumanB(std::string n_name)
{
	name = n_name;
	wp = NULL;
}

HumanB::~HumanB()
{
    std::cout << name << " is dead and loses the game." << std::endl;
}

void HumanB::setWeapon(Weapon &n_wp)
{
	wp = &n_wp;
}
void HumanB::attack()
{
	if (wp)
	{
        std::cout << name << " attacks with their " << wp->getType() << std::endl;
    }
	else
	{
        std::cout << name << " has no weapon to attack with!" << std::endl;
    }
}