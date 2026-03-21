#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyrequestForm", 72, 45)
{
	if (!DEBUG)
		std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestform", 72, 45)
{
	if (!DEBUG)
		std::cout << "RobotomyRequestForm constructor called" << std::endl;
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj)
{
	if (!DEBUG)
		std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = obj;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	if (!DEBUG)
		std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	if (this != &obj)
		this->target = obj.target;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->get_requiredExecGrade())
		throw GradeTooLowException();
	else if (this->get_isSigned() == false)
		throw FormNotSignedException();
	else
	{
		srand(time(NULL));
		if (rand() % 2)
			std::cout << GREEN << this->target << " has been robotomized successfully" << RESET << std::endl;
		else
			std::cout << RED << this->target << "the robotomy failed" << RESET << std::endl;
	}
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	if (!DEBUG)
		std::cout << "RobotomyRequestForm destructor called" << std::endl;
}