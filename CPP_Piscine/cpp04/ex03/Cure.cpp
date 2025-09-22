#include "Cure.hpp"

Cure::Cure():AMateria("cure")
{}

Cure::Cure(Cure const & src):AMateria("cure")
{
	this->_xp = src._xp;
}

Cure::~Cure()
{}

Cure &Cure::operator=(Cure const & rhs)
{
	this->_xp = rhs._xp;
	return(*this);
}

AMateria *Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
