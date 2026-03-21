#include "HumanA.hpp"

HumanA::HumanA(std::string n_name, Weapon &n_wp) : wp(n_wp), name(n_name) {}

HumanA::~HumanA()
{
    std::cout << name << " is dead and loses the game." << std::endl;
}

void HumanA::attack()
{
	std::cout << name << " attacks with their " << wp.getType() << std::endl;
}