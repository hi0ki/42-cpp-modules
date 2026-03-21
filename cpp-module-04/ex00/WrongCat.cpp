#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << GREY << "WrongCat default constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << GREY << "WrongCat type constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
	std::cout << GREY << "WrongCat copy constructor called" << RESET << std::endl;
	*this = obj;
}


WrongCat &WrongCat::operator=(const WrongCat &obj)
{
	std::cout << GREY << "WrongCat assignation operator called" << RESET << std::endl;
	this->type = obj.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << GREY << "WrongCat destructor called" << RESET << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << GREEN << "WrongCat : meoooow meoooow" << RESET << std::endl;
}

std::string WrongCat::getType() const
{
	return type;
}