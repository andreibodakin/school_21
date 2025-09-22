#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter") {}
Polymorph::Polymorph(std::string name, std::string effects) : ASpell(name, effects) {}
Polymorph::Polymorph(const Polymorph & one) : ASpell(one) {}
Polymorph & Polymorph::operator=(const Polymorph & one)
{
    if (this != &one)
        *this = one;
    return (*this);
}
Polymorph::~Polymorph() {}

ASpell * Polymorph::clone() const
{
    return (new Polymorph(*this));
}
