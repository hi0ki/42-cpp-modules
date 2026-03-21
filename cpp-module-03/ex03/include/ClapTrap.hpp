#ifndef CLAPTRAP_HPP
	#define CLAPTRAP_HPP

	#include <iostream>
	#define RED "\033[31m"
	#define GREY "\033[90m"
	#define GREEN "\033[32m"
	#define RESET "\033[0m"
	class ClapTrap
	{
		protected:
			std::string	name;
			unsigned int			hitPoints;
			unsigned int			energyPoints;
			unsigned int			attackDamage;

		public:
			ClapTrap();
			ClapTrap(std::string name);
			ClapTrap(const ClapTrap &obj);
			~ClapTrap();

			ClapTrap	&operator=(const ClapTrap &obj);

			void	attack(std::string const &target);
			void	takeDamage(unsigned int amount);
			void	beRepaired(unsigned int amount);
	};

#endif