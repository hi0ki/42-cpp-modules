#ifndef CURE_HPP
	#define CURE_HPP

	#include "AMateria.hpp"

	class Cure : public AMateria
	{
		public:
			// Constructors & Destructor
			Cure();
			Cure(const Cure &cure);
			Cure &operator=(const Cure &cure);
			~Cure();

			// Member functions
			AMateria *clone() const;
			void use(ICharacter &target);
	};

#endif