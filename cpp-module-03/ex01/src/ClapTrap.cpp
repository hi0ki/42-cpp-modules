#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Unnamed"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << GREY << "ClapTrap default constructor called" << RESET << std::endl;
}
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << GREY << "ClapTrap name constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << GREY << "ClapTrap copy constructor called" << RESET << std::endl;
	*this = obj;
}
ClapTrap::~ClapTrap()
{
	std::cout << GREY << "ClapTrap "<<this->name << " destructor called" << RESET << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << GREY << "ClapTrap assignation operator called" << RESET << std::endl;
	if (this != &obj)
	{
		this->name = obj.name;
		this->hitPoints = obj.hitPoints;
		this->energyPoints = obj.energyPoints;
		this->attackDamage = obj.attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(std::string const &target)
{
	if (!this->hitPoints)
	{
		std::cout << RED << "ClapTrap " << this->name << " is dead and cannot attack" << RESET << std::endl;
		return ;
	}
	else if (!this->energyPoints)
	{
		std::cout << RED << "ClapTrap " << this->name << " has no energy points and cannot attack" << RESET << std::endl;
		return ;
	}
	else if (!this->attackDamage)
	{
		std::cout << RED << "ClapTrap " << this->name << " has no attack damage and cannot attack" << RESET << std::endl;
		return ;
	}
	std::cout << GREEN << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << RESET << std::endl;
	this->energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->hitPoints)
	{
		std::cout << RED << this->name << " is already dead" << RESET << std::endl;
		return ;
	}
	else if (!amount)
	{
		std::cout << GREEN << this->name << " takes no damage" << RESET << std::endl;
		return ;
	}
	else if (this->hitPoints <= amount)
	{
		std::cout << GREEN << this->name << " takes " << amount << " points of damage and dies" << RESET << std::endl;
		this->hitPoints = 0;
		return ;
	}
	std::cout << GREEN << this->name << " takes " << amount << " points of damage, and still has " << this->hitPoints - amount << " hit points!" << RESET << std::endl;
	this->hitPoints -= amount;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->hitPoints)
	{
		std::cout << RED << this->name << " is dead and cannot be repaired" << RESET << std::endl;
		return ;
	}
	else if (!this->energyPoints)
	{
		std::cout << RED << this->name << " has no energy points and cannot be repaired" <<  RESET << std::endl;
		return ;
	}
	else if (!amount)
	{
		std::cout << RED << this->name << " is not repaired" << RESET << std::endl;
		return ;
	}
	if (this->hitPoints + amount >= 10)
		this->hitPoints = 10;
	else 
		this->hitPoints += amount;
	std::cout << GREEN << this->name << " is repaired!" << RESET << std::endl;
	this->energyPoints--;
}
