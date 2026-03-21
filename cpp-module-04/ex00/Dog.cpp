#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << GREY << "Dog default constructor called" << RESET << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << GREY << "Dog constructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
	std::cout << GREY << "Dog assignation operator called" << RESET << std::endl;
	type = obj.type;
	return *this;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	std::cout << GREY << "Dog copy constructor called" << RESET << std::endl;
	
	*this = obj;
}

Dog::~Dog()
{
	std::cout << GREY << "Dog destructor called" << RESET << std::endl;
}

void Dog::makeSound() const
{
	std::cout << GREEN << "Wooooooow Wooooooow" << RESET << std::endl;
}

std::string Dog::getType() const
{
	return type;
}