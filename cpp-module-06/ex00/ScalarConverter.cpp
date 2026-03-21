#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	if (!DEBUG)
		std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter &obj)
{
	if (!DEBUG)
		std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void)obj;
	if (!DEBUG)
		std::cout << "Assignation operator called" << std::endl;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	if (!DEBUG)
		std::cout << "Destructor called" << std::endl;
}

////////////////////////////////////////////////////////////

bool if_PrintableChar(char c)
{
    return c >= 32 && c <= 126;
}

bool theres_a_dot(std::string str)
{
	bool dot = false;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '.')
		{
			if (dot == true)
				return false;
			dot = true;
		}
	}
	return dot;
}


bool util_function(const char *str, std::string characters)
{
	for (int i = 0; str[i]; i++)
	{
		size_t j = 0;
		while (characters[j])
		{
			if (str[i] == characters[j])
				break ;
			j++;
		}
		if (j == characters.length())
			return false;
	}
	return true;
}






int CheckIfChar(std::string str)
{
	if (str.length() == 1 && if_PrintableChar(str.c_str()[0]))
	{
		return 1;
	}
	return 0;
}

int CheckIfInt(std::string str)
{
	int i = 0;
	if (str[0] == '-')
		i = 1;
	if (util_function(str.c_str() + i, "0123456789"))
		return 1;
	return 0;
}

int check_if_float(std::string str)
{
	int i = 0;
	if (str[0] == '-')
		i = 1;
	if (util_function(str.c_str() + i, "0123456789.fF"))
	{
		bool dot = theres_a_dot(str);
		if (dot == true)
		{
			size_t i = 0;
			while(str[i])
			{
				if ((str[i] == 'f' || str[i] == 'F') && dot == true)
				{
					if (str[i + 1] == '\0')
						return 1;
					return 0;
				}
				else if ((str[i] == 'f' || str[i] == 'F') && dot == false)
					return 0;
				i++;
			}
			if (i == str.length())
				return (0);
			return 1;
		}
	}
	return 0;
}

int check_if_double(std::string str)
{
	int i = 0;
	if (str[0] == '-')
		i = 1;
	if (util_function(str.c_str() + i, "0123456789."))
	{
		bool dot = theres_a_dot(str);
		if (dot == true)
		{
			for (int i = 0; str[i]; i++)
			{
				if (str[i] == '.')
				{
					if (str[i + 1] == '\0')
						return 0;
				}
			}
			return 1;
		}
	}
	return (0);
}



// print funciton

void print_IntOrChar(char *str)
{
	int i;
	if (CheckIfChar(str))
		i = static_cast<int>(str[0]);
	else
		i = atoi(str);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);
	char	c = static_cast<char>(i);

	if (i >= 32 && i <= 126)
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void print_DoubleOrFloat(char *str)
{
	float	f = atof(str);
	int		i = static_cast<int>(f);
	double	d = static_cast<double>(f);
	char	c = static_cast<char>(f);
	if (i >= 32 && i <= 126)
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	if (f - i == 0)
	{
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}
int handle_pseudo(std::string string)
{
	std::string pseudos[3] = {"-inf", "+inf", "nan"};

	for (int i = 0; i < 3; i++)
	{
		if (string == pseudos[i])
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << pseudos[i] << "f" << std::endl;
			std::cout << "double: " << pseudos[i] << std::endl;
			return 1;
		}
	}
	return 0;
}

void ScalarConverter::convert(char *str)
{
	if (CheckIfChar(str) || CheckIfInt(str))
		print_IntOrChar(str);
	else if (check_if_float(str) || check_if_double(str))
		print_DoubleOrFloat(str);
	else if (handle_pseudo(str))
		return ;
	else
		std::cout << RED "The type conversion is ipmossible try again :/" RESET << std::endl;
}
