

#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp") {}
Fireball::Fireball(std::string name, std::string effects) : ASpell(name, effects) {}
Fireball::Fireball(const Fireball &spell) : ASpell(spell) {}
Fireball& Fireball::operator = (const Fireball& ref) {
    if (this != &ref)
        *this = ref;
    return (*this);
}
Fireball::~Fireball() {}

ASpell* Fireball::clone() const {
    return (new Fireball(*this));
}
