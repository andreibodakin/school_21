#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine(TacticalMarine const & src)
{
	(void)src;
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

TacticalMarine & TacticalMarine::operator=(TacticalMarine const & rhs)
{
	(void)rhs;
	return(*this);
}

TacticalMarine::TacticalMarine() : ISpaceMarine()
{
    std::cout << "Tactical Marine ready for battle!" << std::endl;
}

TacticalMarine::~TacticalMarine()
{}

ISpaceMarine* TacticalMarine::clone() const
{
        return (new TacticalMarine(*this));
}

void TacticalMarine::battleCry() const
{
    std::cout << "For the holy PLOT!" << std::endl;
}

void TacticalMarine::rangedAttack() const
{
    std::cout << "* attacks with a bolter *" << std::endl;
}

void TacticalMarine::meleeAttack() const
{
    std::cout << "* attacks with a chainsword *" << std::endl;
}
