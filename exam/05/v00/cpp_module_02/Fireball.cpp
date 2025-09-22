#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp") {}
Fireball::Fireball(std::string name, std::string effects) : ASpell(name, effects) {}
Fireball::Fireball(const Fireball & one) : ASpell(one) {}
Fireball & Fireball::operator=(const Fireball & one)
{
    if (this != &one)
        *this = one;
    return (*this);
}
Fireball::~Fireball() {}

ASpell * Fireball::clone() const
{
    return (new Fireball(*this));
}
