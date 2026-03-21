#ifndef CONTACT_HPP
	#define CONTACT_HPP

#include "PhoneBook.hpp"

	class Contact{
		private:
			std::string number;
			std::string first_name;
			std::string last_name;
			std::string nickname;
			std::string darkest_secreret;
		public:
			void set_number(std::string phonenumber);
			void set_fname(std::string fname);
			void set_lname(std::string lname);
			void set_nickname(std::string nick);
			void set_secreret(std::string d_secreret);

			std::string get_number();
			std::string get_fname();
			std::string get_lname();
			std::string get_secreret();
			std::string get_nickname();
	};

#endif