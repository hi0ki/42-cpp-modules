#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("def_name"), grade(1)
{
	if (!DEBUG)
		std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	
	if (!DEBUG)
		std::cout << "Bureaucrat constructor called" << std::endl;
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.name) , grade(obj.grade)
{
	if (!DEBUG)
		std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	if (!DEBUG)
		std::cout << "Bureaucrat assignation operator called" << std::endl;
	if (this != &obj)
	{
		this->grade = obj.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	if (!DEBUG)
		std::cout << "Bureaucrat destructor called" << std::endl;
}

//	methods

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << GREEN <<this->name << " executes " << form.get_name() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED 
			<< this->name << " couldn’t execute " << form.get_name() << " because " << 
			e.what() << RESET << std::endl;
	}
}


std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->grade == 1)
		throw GradeTooHighException();
	else
		this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade == 150)
		throw GradeTooLowException();
	else
		this->grade++;
}

void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN << this->getName() << " signs " << form.get_name() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << this->getName() << " couldn’t sign " << form.get_name() << " because " << e.what() << RESET << std::endl;
	}
}

//	exceptions

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

// assignation operator overload

std::ostream &operator<<(std::ostream &out, Bureaucrat &obj)
{
	out << GREEN <<obj.getName() << ", bureaucrat grade " << obj.getGrade() << RESET << std::endl;
	return out;
}
