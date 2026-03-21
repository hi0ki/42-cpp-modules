#ifndef CHARACTER_HPP
	#define CHARACTER_HPP

	#include "ICharacter.hpp"
	#include "AMateria.hpp"

	typedef struct s_materia
	{
		AMateria *materia;
		struct s_materia *next;
	} t_materia;

	class Character : public ICharacter
	{
		private:
			std::string name;
			AMateria *materias[4];
			t_materia *list;
		public:
			// Constructors & Destructor
			Character(std::string name);
			Character(const Character &character);
			Character &operator=(const Character &character);
			~Character();

			// Member functions
			std::string const &getName() const;
			void equip(AMateria *m);
			void unequip(int idx);
			void use(int idx, ICharacter &target);
	};

	void t_add_back(t_materia **lst, AMateria *materia);
	void t_clear(t_materia **lst);

#endif