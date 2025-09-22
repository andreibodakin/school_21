#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator(AssaultTerminator const & src)
{
	(void)src;
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator & AssaultTerminator::operator=(AssaultTerminator const & rhs)
{
	(void)rhs;
	return(*this);
}

AssaultTerminator::AssaultTerminator() : ISpaceMarine()
{
    std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::~AssaultTerminator()
{}

ISpaceMarine* AssaultTerminator::clone() const
{
    return (new AssaultTerminator(*this));
}

void AssaultTerminator::battleCry() const
{
    std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void AssaultTerminator::rangedAttack() const
{
    std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack() const
{
    std::cout << "* attacks with chainfists *" << std::endl;
}
