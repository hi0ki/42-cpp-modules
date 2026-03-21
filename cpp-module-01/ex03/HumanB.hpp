#ifndef HUMANB_HPP
	#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon *wp;
		std::string name;
	public:
		HumanB(std::string n_name);
		~HumanB();
		void setWeapon(Weapon &n_wp);
		void attack();
};

#endif