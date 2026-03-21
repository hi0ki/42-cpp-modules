#ifndef ANIMAL_HPP
	#define ANIMAL_HPP

	#include <iostream>

	#define GREEN   "\033[32m"
	#define GREY    "\033[90m"
	#define RESET   "\033[0m"

	class Animal
	{
		protected:
			std::string type;
		public:
			Animal();
			Animal(std::string type);
			Animal(const Animal &obj);
			Animal &operator=(const Animal &obj);
			virtual void makeSound() const;
			std::string getType() const;
			virtual ~Animal();
	};
#endif