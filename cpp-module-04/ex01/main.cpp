#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << std::endl;

	const Animal *a[4] = {
		new Dog(),
		new Dog(),
		new Cat(),
		new Cat()
	};

	for (int i = 0; i < 4; i++)
	{
		a[i]->makeSound();
	}
	for (int i = 0; i < 4; i++)
	{
		delete a[i];
	}
	return 0;
}