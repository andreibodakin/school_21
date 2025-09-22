#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include "IMateriaSource.hpp"

class   MateriaSource : public IMateriaSource
{
    private:
		int _count;
		AMateria *mat_sources[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource const & src);
		~MateriaSource();

		MateriaSource &operator=(MateriaSource const & rhs);

		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const & type);
};

#endif
