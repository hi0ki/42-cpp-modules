#include "PhoneBook.hpp"

void Contact::set_number(std::string phonenumber)
{
	number = phonenumber;
}

void Contact::set_fname(std::string fname)
{
	first_name = fname;
}

void Contact::set_lname(std::string lname)
{
	last_name = lname;
}
void Contact::set_nickname(std::string nick)
{
	nickname = nick;
}
void Contact::set_secreret(std::string d_secreret)
{
	darkest_secreret = d_secreret;
}

/*getters*/

std::string  Contact::get_number() {return (number);};
std::string Contact::get_fname() {return (first_name);};
std::string Contact::get_lname() {return (last_name);};
std::string Contact::get_secreret() {return (darkest_secreret);};
std::string Contact::get_nickname() {return (nickname);};