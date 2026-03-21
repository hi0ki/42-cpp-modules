#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
	std::cout << GREY << "WrongAnimal default constructor called" << RESET<< std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << GREY << "WrongAnimal type constructor called" << RESET<< std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	std::cout << GREY << "WrongAnimal copy constructor called" << RESET<< std::endl;
	*this = obj;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << GREY << "WrongAnimal destructor called" << RESET<< std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
	std::cout << GREY << "WrongAnimal assignation operator called" << RESET<< std::endl;
	this->type = obj.type;
	return *this;
}


void WrongAnimal::makeSound() const
{
	std::cout << GREEN << "WrongAnimal has no sound" << RESET<< std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}