#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	this->_count = 0;
	for (int i = 0; i < 4; i++)
		this->mat_sources[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	this->_count = 0;
	for (int i = 0; i < src._count; i++)
		this->learnMateria(src.mat_sources[i]->clone());
	for (int i = 0; i < 4; i++)
		this->mat_sources[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < this->_count; i++)
		delete this->mat_sources[i];
}

MateriaSource &MateriaSource::operator=(MateriaSource const & rhs)
{
	for (int i = 0; i < this->_count; i++)
		delete this->mat_sources[i];
	this->_count = 0;
	for (int i = 0; i < rhs._count; i++)
		this->learnMateria(rhs.mat_sources[i]->clone());
	for (int i = 0; i < 4; i++)
		this->mat_sources[i] = NULL;
	return(*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (this->_count  == 4 || !m)
		return ;
	for (int i = 0; i < this->_count; i++)
		if (this->mat_sources[i] == m)
			return ;
	this->mat_sources[this->_count++] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->_count; i++)
		if (this->mat_sources[i]->getType() == type)
			return (this->mat_sources[i]->clone());
	return (NULL);
}
