#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	if (!DEBUG)
		std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target_file) : AForm("ShrubberyCreationForm", 145, 137)
{
	if (!DEBUG)
		std::cout << "ShrubberyCreationForm constructor called" << std::endl;
	this->target = target_file + "_shrubbery";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj) : AForm(obj)
{
	if (!DEBUG)
		std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const & obj)
{
	if (!DEBUG)
		std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->target = obj.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	if (!DEBUG)
		std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->get_requiredExecGrade())
		throw GradeTooLowException();
	else if (this->get_isSigned() == false)
		throw FormNotSignedException();
	else
	{
		std::ofstream ofile;
		ofile.open(this->target);

		ofile <<"						+++++++++++\n"
			"					==++++++++++++++++++++\n"
			"					+++*++++++++++++++*++++\n"
			"				++++***++++***+*++++++***++++\n"
			"				+*+++*******+***++*****+++*+++++\n"
			"				++++*******+++++++****+++++++*+++\n"
			"			++++++*********++++*++*+**++****+++++++++\n"
			"		==  +*+++***+++++++++**+********+**++++++*++++\n"
			"		+++++**************++++++++++*++++++++++++++\n"
			"		++++***++**++++***************+++++****++++++\n"
			"		+++*+***++*++*****++++***********+***++++*++++++\n"
			"		+++++*********+***+************************+++\n"
			"			*++*****++  **+++****+***************++++++\n"
			"			**+         ++*********** +++*  +++++++\n"
			"						++++*****+++\n"
			"							***+\n"
			"							***+\n"
			"							***+\n"
			"							***+\n"
			"					***++++++++++=========" << std::endl;
		ofile.close();
	}
}
