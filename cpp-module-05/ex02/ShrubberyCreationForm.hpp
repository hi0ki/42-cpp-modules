#ifndef SHRUBBERYCREATIONFORM_HPP
	#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(std::string target_file);
		ShrubberyCreationForm(ShrubberyCreationForm const & obj);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & obj);
		void execute(Bureaucrat const & executor) const;
		~ShrubberyCreationForm();
};
#endif