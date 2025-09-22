#include "ASpell.hpp"

ASpell::ASpell() : _name(), _effects() {}
ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects) {}
ASpell::ASpell(const ASpell & one)
{
    _name = one._name;
    _effects = one._effects;
}
ASpell & ASpell::operator=(const ASpell & one)
{
    _name = one._name;
    _effects = one._effects;
    return (*this);
}
ASpell::~ASpell() {}

std::string ASpell::getName() const
{
    return (_name);
}

std::string ASpell::getEffects() const
{
    return (_effects);
}

void ASpell::launch(const ATarget & one) const
{
    one.getHitBySpell(*this);
}
