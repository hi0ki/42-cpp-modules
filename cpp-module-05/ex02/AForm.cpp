#include "AForm.hpp"

AForm::AForm() : name("def_name_form") , requiredGrade(150), requiredExecGrade(150)
{
	isSigned = false;
	if (!DEBUG)
		std::cout << "default constructor" << std::endl;
}

AForm::AForm(std::string name, int requiredGrade, int requiredExecGrade) : name(name), requiredGrade(requiredGrade), requiredExecGrade(requiredExecGrade)
{
	isSigned = false;
	if (requiredExecGrade < 1 || requiredGrade < 1)
		throw GradeTooHighException();
	else if (requiredExecGrade > 150 || requiredGrade > 150)
		throw GradeTooLowException();
	if (!DEBUG)
		std::cout << "Type constructor" << std::endl;
}

AForm::AForm(const AForm &form) : name(form.name), requiredGrade(form.requiredGrade), requiredExecGrade(form.requiredExecGrade)
{
	isSigned = form.isSigned;
	if (!DEBUG)
		std::cout << "Copy constructor" << std::endl;
}

AForm::~AForm()
{
	if (!DEBUG)
		std::cout << "Destructor" << std::endl;
}

// operator 
AForm &AForm::operator=(AForm const &form)
{
	if (this != &form)
	{
		isSigned = form.isSigned;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const AForm &obj)
{
	out << GREEN << "Form name: " << obj.get_name() << std::endl;
	out << "Form is signed: " << obj.get_isSigned() << std::endl;
	out << "Form required grade: " << obj.get_requiredGrade() << std::endl;
	out << "Form required exec grade: " << obj.get_requiredExecGrade() << RESET << std::endl;
	return (out);
}

// getters

std::string AForm::get_name() const
{
	return (name);
}

int AForm::get_requiredGrade() const
{
	return (requiredGrade);
}

int AForm::get_requiredExecGrade() const
{
	return (requiredExecGrade);
}

bool AForm::get_isSigned() const
{
	return (isSigned);
}

// methods

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= requiredGrade)
	{
		isSigned = true;
		return ;
	}
	throw GradeTooLowException();
}

// exceptions

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}