#include "AMateria.hpp"

// Constructors & Destructor

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &amateria)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = amateria;
}

AMateria &AMateria::operator=(const AMateria &amateria)
{
	std::cout << "AMateria assignation operator called" << std::endl;
	if (this != &amateria)
	{
		this->type = amateria.type;
	}
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

// Getters

std::string const &AMateria::getType() const
{
	return (this->type);
}

// Member functions

void AMateria::use(ICharacter &target)
{
	(void)target;
	std::cout << "AMateria use function called" << std::endl;
}

