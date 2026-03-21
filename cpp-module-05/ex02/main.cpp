
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	// ShrubberyCreationForm
	try
	{
		ShrubberyCreationForm form("shrubbery");
		Bureaucrat bur("bureaucrat", 100);

		bur.signForm(form);
		form.execute(bur);
		std::cout << form;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}

	// RobotomyRequestForm
	std::cout << "-------------------------------------" << std::endl;
	try
	{
		RobotomyRequestForm form("robotomy");
		const Bureaucrat bur("bureaucrat", 40);

		bur.signForm(form);
		form.execute(bur);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}

	// PresidentialPardonForm
	std::cout << "-------------------------------------" << std::endl;
	try
	{
		PresidentialPardonForm form("rajol");
		const Bureaucrat bur("bureaucrat", 4);

		form.beSigned(bur);
		bur.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}

	return 0;
}