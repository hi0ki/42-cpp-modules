#include "Zombie.hpp"

int main()
{
	int i = 0;
	int nb_of_zombies = 5;
	Zombie *objs = zombieHorde(nb_of_zombies, "foo");
	while (i < nb_of_zombies)
	{
		objs[i].announce();
		i++;
	}
	delete[] objs;
	return (0);
}