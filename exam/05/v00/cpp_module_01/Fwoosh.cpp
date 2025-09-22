#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {}


Fwoosh::Fwoosh(std::string name, std::string effects) : ASpell(name, effects) {}
Fwoosh::Fwoosh(const Fwoosh & one) : ASpell(one) {}
Fwoosh & Fwoosh::operator=(const Fwoosh & one)
{
    if (this != &one)
        *this = one;
    return (*this);
}
Fwoosh::~Fwoosh() {}


ASpell * Fwoosh::clone() const
{
    return (new Fwoosh(*this));  // *this!!!!!
}
