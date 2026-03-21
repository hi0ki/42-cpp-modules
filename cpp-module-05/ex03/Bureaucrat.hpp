#ifndef BUREAUCRAT_HPP
	#define BUREAUCRAT_HPP

	#include <iostream>
	#include "AForm.hpp"
	
	#define DEBUG 1
	#define RED "\033[0;31m"
	#define GREEN "\033[1;32m"
	#define RESET "\033[0m"

	class AForm;

	class Bureaucrat{
		private:
			const std::string name;
			int grade;
		public:
			Bureaucrat();
			Bureaucrat(std::string name, int grade);
			Bureaucrat(const Bureaucrat &obj);
			~Bureaucrat();

			// assignation operator overload
			Bureaucrat &operator=(const Bureaucrat &obj);
			
			// getters
			std::string getName() const;
			int getGrade() const;

			// methods
			void incrementGrade();
			void decrementGrade();
			void signForm(AForm &form) const;
			void executeForm(AForm const & form) const;

			// exceptions
			class GradeTooHighException : public std::exception{
				public:
					virtual const char *what() const throw();
			};

			class GradeTooLowException : public std::exception{
				public:
					virtual const char *what() const throw();
			};
	};

	std::ostream &operator<<(std::ostream &out, Bureaucrat &obj);
#endif
