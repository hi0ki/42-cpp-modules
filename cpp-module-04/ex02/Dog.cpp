#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << GREY << "Dog default constructor called" << RESET << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	brain = new Brain();
	std::cout << GREY << "Dog constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	brain = new Brain();
	std::cout << GREY << "Dog copy constructor called" << RESET << std::endl;
	if (this != &obj)
		*this = obj;
}

Dog &Dog::operator=(const Dog &obj)
{
	std::cout << GREY << "Dog assignation operator called" << RESET << std::endl;
	type = obj.type;
	return *this;
}


Dog::~Dog()
{
	delete brain;
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