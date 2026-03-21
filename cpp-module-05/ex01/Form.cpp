#include "Form.hpp"

Form::Form() : name("def_name_form") , requiredGrade(150), requiredExecGrade(150)
{
	isSigned = false;
	std::cout << "default constructor" << std::endl;
}

Form::Form(std::string name, int requiredGrade, int requiredExecGrade) : name(name), requiredGrade(requiredGrade), requiredExecGrade(requiredExecGrade)
{
	isSigned = false;
	if (requiredExecGrade < 1 || requiredGrade < 1)
		throw Form::GradeTooHighException();
	else if (requiredExecGrade > 150 || requiredGrade > 150)
		throw GradeTooLowException();
	std::cout << "Type constructor" << std::endl;
}

Form::Form(const Form &form) : name(form.name), requiredGrade(form.requiredGrade), requiredExecGrade(form.requiredExecGrade)
{
	isSigned = form.isSigned;
	std::cout << "Copy constructor" << std::endl;
}

Form::~Form()
{
	std::cout << "Destructor" << std::endl;
}

// operator 
Form &Form::operator=(Form const &form)
{
	if (this != &form)
	{
		isSigned = form.isSigned;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
	out << "Form name: " << obj.get_name() << std::endl;
	out << "Form is signed: " << obj.get_isSigned() << std::endl;
	out << "Form required grade: " << obj.get_requiredGrade() << std::endl;
	out << "Form required exec grade: " << obj.get_requiredExecGrade() << std::endl;
	return (out);
}

// getters

std::string Form::get_name() const
{
	return (name);
}

int Form::get_requiredGrade() const
{
	return (requiredGrade);
}

int Form::get_requiredExecGrade() const
{
	return (requiredExecGrade);
}

bool Form::get_isSigned() const
{
	return (isSigned);
}

// methods

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= requiredGrade)
	{
		isSigned = true;
		return ;
	}
	throw GradeTooLowException();
}

// exceptions

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}