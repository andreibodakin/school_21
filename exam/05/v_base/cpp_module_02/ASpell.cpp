#include "ASpell.hpp"

ASpell::ASpell() : _name(), _effects() {}
ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects) {}
ASpell::ASpell(const ASpell& ref) {
    _name = ref._name;
    _effects = ref._effects;
}
ASpell& ASpell::operator = (const ASpell& ref) {
    _name = ref._name;
    _effects = ref._effects;
    return (*this);
}
ASpell::~ASpell() {}

std::string ASpell::getName() const {
    return _name;
}

std::string ASpell::getEffects() const {
    return _effects;
}

void ASpell::launch(const ATarget& target) const {
    target.getHitBySpell(*this);
}
