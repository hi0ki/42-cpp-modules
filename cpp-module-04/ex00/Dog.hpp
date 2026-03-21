#ifndef DOG_HPP
	#define DOG_HPP

#include "Animal.hpp"

	class Dog : public Animal
	{
		public:
			Dog();
			Dog(std::string type);
			Dog(const Dog &obj);
			Dog &operator=(const Dog &obj);
			void makeSound() const;
			std::string getType() const;
			~Dog();
	};

#endif