#include "Brain.hpp"

Brain::Brain()
{
	std::cout << GREY << "Brain constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain &obj)
{
	std::cout << GREY << "Brain copy constructor called" << RESET << std::endl;
	*this = obj;
}

Brain &Brain::operator=(const Brain &obj)
{
	std::cout << GREY << "Brain assignation operator called" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = obj.ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << GREY << "Brain destructor called" << RESET << std::endl;
}