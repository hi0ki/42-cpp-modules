#ifndef PHONEBOOK_HPP
	# define PHONEBOOK_HPP

	#include <iostream>
	#include <string>
	#include "Contact.hpp"

	class PhoneBook
	{
		private:
			Contact contacts[8];
		public:
			void set_contact_data(int index, std::string number, std::string firstname, std::string lastname , std::string nickname, std::string secret);
			int get_contact_data(int index , bool helper);
	};

	void print_string(std::string str, int start, int end);
	int valid_number(std::string str);
	void print_data(PhoneBook data);
	void add_data(PhoneBook &data, int index);
	void search_for_data(PhoneBook data);

#endif