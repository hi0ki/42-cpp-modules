#include "../include/ScavTrap.hpp"
ScavTrap::ScavTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << GREY << "ScavTrap default constructor called" << RESET << std::endl;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << GREY << "ScavTrap name constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
	std::cout << GREY <<  "ScavTrap copy constructor called" << RESET << std::endl;
	*this = obj;
}

ScavTrap::~ScavTrap()
{
	std::cout << GREY << "ScavTrap " << this->name << " destructor called" << RESET << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &obj)
{
	std::cout << GREY << "ScavTrap assignation operator called" << RESET << std::endl;
	if (this != &obj)
	{
		this->name = obj.name;
		this->hitPoints = obj.hitPoints;
		this->energyPoints = obj.energyPoints;
		this->attackDamage = obj.attackDamage;
	}
	return (*this);
}

void	ScavTrap::attack(std::string const &target)
{
	if (!this->hitPoints)
	{
		std::cout << RED << "ScavTrap " << this->name << " is dead and cannot attack" << RESET << std::endl;
		return ;
	}
	else if (!this->energyPoints)
	{
		std::cout << RED << "ScavTrap " << this->name << " has no energy points and cannot attack" << RESET << std::endl;
		return ;
	}
	else if (!this->attackDamage)
	{
		std::cout << RED << "ScavTrap " << this->name << " has no attack damage and cannot attack" << RESET << std::endl;
		return ;
	}
	std::cout << GREEN << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << RESET << std::endl;
	this->energyPoints--;
}

void ScavTrap::guardGate()
{
	std::cout << GREEN << "ScavTrap " << this->name << " is now in Gate keeper mode." << RESET << std::endl;
}