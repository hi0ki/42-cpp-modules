#include "Cure.hpp"

// Constructors & Destructor
Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
}
Cure::Cure(const Cure &cure) : AMateria(cure.type)
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = cure;
}

Cure &Cure::operator=(const Cure &cure)
{
	std::cout << "Cure assignation operator called" << std::endl;
	if (this != &cure)
		type = cure.type;
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

// Member functions
AMateria *Cure::clone() const
{
	std::cout << "Cure clone function called" << std::endl;
	return (new Cure(*this));
}
void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}