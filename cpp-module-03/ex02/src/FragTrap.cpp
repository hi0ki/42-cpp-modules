#include "../include/FragTrap.hpp"

FragTrap::FragTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << GREY << "FragTrap default constructor called" << RESET << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << GREY << "FragTrap name constructor called" << RESET << std::endl;
}
FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	std::cout << GREY << "FragTrap copy constructor called" << RESET << std::endl;
	*this = obj;
}

FragTrap&	FragTrap::operator=(const FragTrap &obj)
{
	std::cout << GREY << "FragTrap assignation operator" << RESET << std::endl;
	if (this != &obj)
	{
		this->name = obj.name;
		this->hitPoints = obj.hitPoints;
		this->energyPoints = obj.energyPoints;
		this->attackDamage = obj.attackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << GREY <<  "FragTrap " << this->name << " destructor called" << RESET << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << GREEN << "FragTrap " << this->name << " requests a high five" << RESET << std::endl;
}