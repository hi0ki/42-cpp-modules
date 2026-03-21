#ifndef AMATERIA_HPP
	#define AMATERIA_HPP

	#include <iostream>
	#include <string>
	#include "ICharacter.hpp"

	class AMateria
	{
		protected:
			std::string type;
		public:
			// Constructors & Destructor
			AMateria(std::string const &type);
			AMateria(const AMateria &amateria);
			AMateria &operator=(const AMateria &amateria);
			virtual ~AMateria();

			// Getters
			std::string const &getType() const;

			// Member functions & pure virtual functions
			virtual AMateria *clone() const = 0;
			virtual void use(ICharacter &target);

	};
#endif