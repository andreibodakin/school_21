#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
	this->_xp = 0;
	this->_type = type;
}

AMateria::~AMateria()
{}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

unsigned int AMateria::getXP() const
{
	return (this->_xp);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	this->_xp += 10;
}
