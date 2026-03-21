#include "Character.hpp"

Character::Character(std::string name)
{
	std::cout << "Character constructor called" << std::endl;
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->materias[i] = NULL;
}

Character::Character(const Character &character)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = character;
}

Character &Character::operator=(const Character &character)
{
	std::cout << "Character assignation operator called" << std::endl;
	if (this != &character)
	{
		this->name = character.name;
		for (int i = 0; i < 4; i++)
			this->materias[i] = character.materias[i];
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	t_clear(&this->list);
}

std::string const &Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->materias[i])
		{
			this->materias[i] = m;
			break;
		}
	}
}	

void Character::unequip(int idx)
{	
	if (idx >= 0 && idx < 4)
	{
		t_add_back(&this->list, this->materias[idx]);
		this->materias[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->materias[idx])
		this->materias[idx]->use(target);
}


// linked list functions

void t_add_back(t_materia **lst, AMateria *materia)
{
	t_materia *last = *lst;
	t_materia *node = new t_materia();
	node->materia = materia;
	node->next = NULL;

	if (!*lst)
	{
		*lst = node;
		return ;
	}
	for ( ;last->next; last = last->next);

	last->next = node;
	return ;
}
void t_clear(t_materia **lst)
{
	t_materia *tmp;
	while (*lst)
	{
		tmp = (*lst)->next;
		delete (*lst)->materia;
		delete *lst;
		*lst = tmp;
	}
}