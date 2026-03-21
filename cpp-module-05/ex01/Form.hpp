#ifndef FORM_HPP
	#define FORM_HPP

	#include <iostream>
	#include "Bureaucrat.hpp"

	class Bureaucrat;
	class Form
	{
		private:
			const std::string name;
			bool isSigned;
			const int requiredGrade;
			const int requiredExecGrade;
		public:
			Form();
			Form(std::string name, int requiredGrade, int requiredExecGrade);
			Form(const Form &form);
			~Form();

		// operator
		Form &operator=(Form const &form);

		// getters
		std::string get_name() const;
		bool get_isSigned() const;
		int get_requiredGrade() const;
		int get_requiredExecGrade() const;

		// methods
		void beSigned(const Bureaucrat &bureaucrat);

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
	};

	std::ostream &operator<<(std::ostream &out, const Form &obj);

#endif