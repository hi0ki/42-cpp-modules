#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *objs = new Zombie[N];

	while (N >= 0)
	{
		objs[N].set_name(name);
		N--;
	}
	return (objs);
}