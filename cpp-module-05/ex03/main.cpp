
#include "Intern.hpp"

int main()
{
	AForm* rrf = NULL;
	try
	{
		Bureaucrat br("mehdi", 2);
		Intern someRandomIntern;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		if (rrf)
		{
			rrf->beSigned(br);
			rrf->execute(br);
			delete rrf;
		}
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
		delete rrf;
	}
	return 0;
}