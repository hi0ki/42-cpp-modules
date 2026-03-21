#ifndef WRONGANIMAL_HPP
	#define WRONGANIMAL_HPP

	#include <iostream>

	#define GREEN   "\033[32m"
	#define GREY    "\033[90m"
	#define RESET   "\033[0m"
	class WrongAnimal
	{
		protected:
			std::string type;
		public:
			WrongAnimal();
			WrongAnimal(std::string type);
			WrongAnimal(const WrongAnimal &obj);
			virtual ~WrongAnimal();
			WrongAnimal &operator=(const WrongAnimal &obj);
			void makeSound() const;
			std::string getType() const;
	};
#endif