#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << GREY << "Cat default constructor called" << RESET << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << GREY << "Cat type constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	std::cout << GREY << "Cat copy constructor called" << RESET << std::endl;
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