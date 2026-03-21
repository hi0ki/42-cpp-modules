#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << GREY << "Animal default constructor called" << RESET << std::endl;
}
Animal::Animal(std::string type) : type(type)
{
	std::cout << GREY << "Animal type constructor called" << RESET << std::endl;
}
Animal::Animal(const Animal &obj)
{
	std::cout << GREY << "Animal copy constructor called" << RESET << std::endl;
	*this = obj;
}

Animal &Animal::operator=(const Animal &obj)
{
	std::cout << GREY << "Animal assignation operator called" << RESET << std::endl;
	this->type = obj.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << GREY << "Animal destructor called" << RESET << std::endl;
}


std::string Animal::getType() const
{
	return type;
}