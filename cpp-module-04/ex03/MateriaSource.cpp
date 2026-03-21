#include "MateriaSource.hpp"

MateriaSource::MateriaSource() 
{
	std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->materias[i] = NULL;
}
MateriaSource::MateriaSource(MateriaSource &obj)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = obj;
}
MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i])
		{
			delete this->materias[i];
			this->materias[i] = NULL;
		}
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource &obj)
{
	std::cout << "MateriaSource assignation operator called" << std::endl;
	if (this != &obj)
	{
		for(int i = 0; i < 4; i++)
		{
			if (this->materias[i])
			{
				delete this->materias[i];
				this->materias[i] = NULL;
			}
			if (obj.materias[i])
				this->materias[i] = this->materias[i];
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4 ; i++)
	{
		if (!this->materias[i])
		{
			this->materias[i] = m;
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (type == this->materias[i]->getType())
			return this->materias[i]->clone();
	}
	std::cout << type << " not found" << std::endl;
	return NULL;
}
