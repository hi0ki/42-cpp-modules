#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

int main()
{
    ClapTrap claptrap("ClapTrap");
    ScavTrap scavtrap("ScavTrap");

    claptrap.attack("target1");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);

	std::cout << "---------------------------------" << std::endl;
    scavtrap.attack("target2");
    scavtrap.takeDamage(199);
    scavtrap.beRepaired(5);
    scavtrap.guardGate();

    return 0;
}