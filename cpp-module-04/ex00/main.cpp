#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;
	
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	std::cout << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << std::endl;

	const WrongAnimal* meta1 = new WrongAnimal();
	const WrongAnimal* i1 = new WrongCat();

	std::cout << std::endl << "WrongCat type : " << i1->getType() << " " << std::endl;
	std::cout << "WrongAnimal type : "<< meta1->getType() << " " << std::endl;
	std::cout << std::endl;

	i1->makeSound();
	meta1->makeSound();

	delete meta1;
	delete i1;
	return 0;
}