#ifndef ICE_HPP
	#define ICE_HPP

	#include <iostream>
	#include "AMateria.hpp"

	class Ice : public AMateria
	{
		public:
			// Constructors & Destructor
			Ice();
			Ice(const Ice &ice);
			Ice &operator=(const Ice &ice);
			~Ice();

			// Member functions
			AMateria *clone() const;
			void use(ICharacter &target);
	};

#endif