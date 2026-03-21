#include "Zombie.hpp"

int main()
{
	Zombie *obj = newZombie("Foo");
	obj->announce();
	randomChump("Zombie");
	delete obj;
	return (0);
}