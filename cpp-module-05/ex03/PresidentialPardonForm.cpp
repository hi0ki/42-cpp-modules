#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	if (!DEBUG)
		std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	if (!DEBUG)
		std::cout << "PresidentialPardonForm constructor called" << std::endl;
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &obj) : AForm(obj)
{
	if (!DEBUG)
		std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	if (!DEBUG)
		std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->get_requiredExecGrade())
		throw GradeTooLowException();
	else if (this->get_isSigned() == false)
		throw FormNotSignedException();
	std::cout << GREEN << this->target << " has been pardoned by Zafod Beeblebrox" << RESET << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	if (!DEBUG)
		std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
	if (this != &obj)
	{
		this->target = obj.target;
	}
	return *this;
}