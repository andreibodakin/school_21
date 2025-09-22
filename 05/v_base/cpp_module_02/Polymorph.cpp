

#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "fwooshed") {}
Polymorph::Polymorph(std::string name, std::string effects) : ASpell(name, effects) {}
Polymorph::Polymorph(const Polymorph &spell) : ASpell(spell) {}
Polymorph& Polymorph::operator = (const Polymorph& ref) {
    if (this != &ref)
        *this = ref;
    return (*this);
}
Polymorph::~Polymorph() {}

ASpell* Polymorph::clone() const {
    return (new Polymorph(*this));
}
