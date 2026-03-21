#include "PhoneBook.hpp"

std::string read_data(std::string str , bool number)
{
	std::string line;

	while (1)
	{
		std::cout << str << ": ";
		if (!getline(std::cin, line))
		{
			exit(1);
		}
		std::cout << line << std::endl;
		if (!line.length() || (number == true && valid_number(line)))
		{
			std::cout << str << " is required. Please try again." << std::endl;
			continue; 
		}
		break;
	}
	return (line);
}

void add_data(PhoneBook &data, int index)
{
	std::string number;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string secreret;

	std::cout << "enter your data:" << std::endl;
	first_name = read_data("First Name", false);
	last_name = read_data("Last Name", false);
	nickname = read_data("Nickname", false);
	number = read_data("Phone number", true);
	secreret = read_data("Darkest secret", false);
	data.set_contact_data(index, number, first_name, last_name, nickname, secreret);
}

void search_for_data(PhoneBook data)
{
	std::string line;
	int i_input;

	print_data(data);
	while (1)
	{
		std::cout << "Enter an index to display the data of it (0-7): ";
		if (!getline(std::cin, line))
			break;
		if (line.length() != 1 || !isdigit(line[0]))
		{
			std::cout << "!! Input not valid !!" << std::endl;
			print_data(data);
		}
		else
		{
			i_input = atoi(line.c_str());
			if (i_input > 7)
			{
				std::cout << "!! Input not valid !!" << std::endl;
				print_data(data);
			}
			else
			{
				std::cout << "    <-------------------------->\n";
				data.get_contact_data(i_input, true);
				std::cout << "    <-------------------------->\n";
			}
		}
		break;
	}
}

int main()
{
	PhoneBook data;
	std::string line;
	int index = 0;

	while (1)
	{
		std::cout << "Enter one of three commands \"ADD, SEARCH, EXIT\":> " ;
		if (!getline(std::cin, line))
			break ;
		else if (!strcmp(line.c_str(), "ADD"))
		{
			if (index == 8)
				index = 0;
			add_data(data , index);
			index++;
		}
		else if (!strcmp(line.c_str(), "SEARCH"))
			search_for_data(data);
		else if (!strcmp(line.c_str(), "EXIT"))
			break ;
		else
			std::cout << "The program only accepts ADD, SEARCH and EXIT !!" << std::endl;
	}
}