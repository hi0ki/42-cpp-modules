#ifndef INTERN_HPP
	#define INTERN_HPP

	#include "PresidentialPardonForm.hpp"
	#include "RobotomyRequestForm.hpp"
	#include "ShrubberyCreationForm.hpp"
	#include "AForm.hpp"

	class Intern
	{
		public:
			Intern();
			Intern(const Intern &intern);
			~Intern();
			Intern &operator=(const Intern &intern);
			AForm* makeForm(std::string form_name, std::string target);
	};

#endif