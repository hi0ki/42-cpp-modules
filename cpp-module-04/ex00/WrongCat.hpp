#ifndef WRONGCAT_HPP
	#define WRONGCAT_HPP

	#include "WrongAnimal.hpp"

	class WrongCat : public WrongAnimal
	{
		public:
			WrongCat();
			WrongCat(const WrongCat &obj);
			WrongCat(std::string type);
			~WrongCat();
			WrongCat &operator=(const WrongCat &obj);
			void makeSound() const;
			std::string getType() const;
	};

#endif