#ifndef HUMANA_HPP
	#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon &wp;
		std::string name;
	public:
		HumanA(std::string n_name, Weapon &n_wp);
		~HumanA();
		void attack();
};


#endif