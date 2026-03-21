#ifndef MATERIASOURCE_HPP
	#define MATERIASOURCE_HPP

	#include "IMateriaSource.hpp"

	class MateriaSource : public IMateriaSource
	{
		private:
			AMateria *materias[4];
		public:
			//Constructor & Destructor
			MateriaSource();
			MateriaSource(MateriaSource &obj);
			~MateriaSource();
			MateriaSource &operator=(MateriaSource &obj);

			//Member functions
			void learnMateria(AMateria* m);
			AMateria* createMateria(std::string const & type);
	};

#endif