#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/DiamondTrap.hpp"

int main()
{
    ClapTrap claptrap("ClapTrap");
    std::cout << "----------------------------------------------------" << std::endl;
    ScavTrap scavtrap("ScavTrap");
    std::cout << "----------------------------------------------------" << std::endl;
    FragTrap fragtrap("FragTrap");
    std::cout << "----------------------------------------------------" << std::endl;
    DiamondTrap diamondtrap("DiamondTrap");


    std::cout << "----------------------------------------------------" << std::endl;
    claptrap.attack("target1");
    claptrap.takeDamage(10);
    claptrap.beRepaired(3);

    std::cout << "----------------------------------------------------" << std::endl;
    scavtrap.attack("target2");
    scavtrap.takeDamage(99);
    scavtrap.beRepaired(5);
    scavtrap.guardGate();

    std::cout << "----------------------------------------------------" << std::endl;
    fragtrap.attack("target3");
    fragtrap.takeDamage(15);
    fragtrap.beRepaired(10);
    fragtrap.highFivesGuys();
    std::cout << "----------------------------------------------------" << std::endl;
    diamondtrap.attack("target4");
    diamondtrap.takeDamage(20);
    diamondtrap.beRepaired(15);
    diamondtrap.whoAmI();
    return 0;
}