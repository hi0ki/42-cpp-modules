#include "Ice.hpp"

// Constructors & Destructor

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &ice) : AMateria(ice.type)
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = ice;
}

Ice &Ice::operator=(const Ice &ice)
{
	std::cout << "Ice assignation operator called" << std::endl;
	if (this != &ice)
	{
		this->type = ice.type;
	}
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

// Member functions

AMateria *Ice::clone() const
{
	std::cout << "Ice clone function called" << std::endl;
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
