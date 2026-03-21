#ifndef AFORM_HPP
	#define AFORM_HPP

	#include <iostream>
	#include "Bureaucrat.hpp"

	class Bureaucrat;
	class AForm
	{
		private:
			const std::string name;
			bool isSigned;
			const int requiredGrade;
			const int requiredExecGrade;
		public:
			AForm();
			AForm(std::string name, int requiredGrade, int requiredExecGrade);
			AForm(const AForm &form);
			virtual ~AForm();

			// operator
			AForm &operator=(AForm const &form);

			// getters
			std::string get_name() const;
			bool get_isSigned() const;
			int get_requiredGrade() const;
			int get_requiredExecGrade() const;

			// methods
			void beSigned(const Bureaucrat &bureaucrat);
			virtual void execute(Bureaucrat const & executor) const = 0;

			// exceptions
			class GradeTooHighException : public std::exception
			{
				public:
					virtual const char *what() const throw();
			};

			class GradeTooLowException : public std::exception
			{
				public:
					virtual const char *what() const throw();
			};

			class FormNotSignedException : public std::exception
			{
				public:
					virtual const char *what() const throw();
			};
	};

	std::ostream &operator<<(std::ostream &out, const AForm &obj);

#endif