#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"


int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);


	ICharacter* bob = new Character("bob");
	std::cout << "--------------------------------" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << "--------------------------------" << std::endl;

	me->unequip(0);
	me->unequip(1);

	delete bob;
	delete me;
	delete src;
	return 0;
}