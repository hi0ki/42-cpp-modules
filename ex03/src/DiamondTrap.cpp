#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("unamed_clap_name")
{
	this->name = "unamed";
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = 50;
	DiamondTrap::attackDamage = FragTrap::attackDamage;

	std::cout << GREY << "DiamondTrap default constructor called" << RESET << std::endl;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	this->name = name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = 50;
	this->attackDamage = FragTrap::attackDamage;

	std::cout << GREY << "DiamondTrap name constructor called" << RESET <<std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj)
{
	std::cout << GREY << "DiamondTrap copy constructor called" << RESET << std::endl;
	*this = obj;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << GREY << "DiamondTrap " << this->name << " destructor called" << RESET << std::endl;
}
DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &obj)
{
	std::cout << GREY << "DiamondTrap assignation operator called" << RESET << std::endl;
	if (this != &obj)
	{
		this->name = obj.name;
		this->hitPoints = obj.hitPoints;
		this->energyPoints = obj.energyPoints;
		this->attackDamage = obj.attackDamage;
	}
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << GREEN << "THis is DiamondTrap " << this->name << " and ClapTrap " << ClapTrap::name << RESET <<std::endl;
}