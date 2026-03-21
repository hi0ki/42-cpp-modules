#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << GREY << "Cat default constructor called" << RESET << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	brain = new Brain();
	std::cout << GREY << "Cat type constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	brain = new Brain();
	std::cout << GREY << "Cat copy constructor called" << RESET << std::endl;
	if (this != &obj)
		*this = obj;
}


Cat &Cat::operator=(const Cat &obj)
{
	std::cout << GREY << "Cat assignation operator called" << RESET << std::endl;
	this->type = obj.type;
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << GREY << "Cat destructor called" << RESET << std::endl;
}

void Cat::makeSound() const
{
	std::cout << GREEN << "Meeeeoooow Meeeeooooow" << RESET << std::endl;
}

std::string Cat::getType() const
{
	return type;
}