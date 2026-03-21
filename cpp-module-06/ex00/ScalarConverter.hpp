#ifndef SCALARCONVERTER_HPP
	#define	SCALARCONVERTER_HPP

	#include <iostream>
	#define DEBUG 0

	#define CHAR 
	#define INT
	#define DOUBLE
	#define FLOAT

	#define RED "\033[1;31m"
	#define GREEN "\033[1;32m"
	#define RESET "\033[0m"

	class ScalarConverter
	{
		private:
			ScalarConverter();
			ScalarConverter(ScalarConverter &obj);
			ScalarConverter &operator=(const ScalarConverter &obj);
			~ScalarConverter();
		public:
			static void convert(char *str);
	};
#endif