#include "Intern.hpp"

Intern::Intern()
{
	if (DEBUG == 0)
		std::cout << "Intern default constructor" << std::endl;
}
Intern::Intern(const Intern &intern)
{
	if (DEBUG == 0)
		std::cout << "Intern copy constructor" << std::endl;
	*this = intern;
}
Intern::~Intern()
{
	if (DEBUG == 0)
		std::cout << "Intern destructor" << std::endl;
}

Intern &Intern::operator=(const Intern &intern)
{
	if (DEBUG == 0)
		std::cout << "Intern assignation operator" << std::endl;
	(void)intern;
	return (*this);
}

AForm* Intern::makeForm(std::string form_name, std::string target)
{
	int i = 0;
	AForm *obj = NULL;
	std::string forms[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	while (i < 3)
	{
		if (forms[i] == form_name)
			break;
		i++;
	}


	switch (i)
	{
		case 0:
			obj = new PresidentialPardonForm(target);
			std::cout << GREEN << "Intern creates " << form_name << RESET << std::endl;
			break;
		case 1:
			obj = new RobotomyRequestForm(target);
			std::cout << GREEN << "Intern creates " << form_name << RESET << std::endl;
			break;
		case 2:
			obj = new ShrubberyCreationForm(target);
			std::cout << GREEN << "Intern creates " << form_name << RESET << std::endl;
			break;
		default:
			std::cout << RED << "No form with this name" << RESET << std::endl;
	}

	return (obj);
}