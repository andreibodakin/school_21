#include "ASpell.hpp"


ASpell::ASpell() : _name(), _effects() {}
ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects) {}


// ASpell::ASpell(std::string type) : _type(type)
// {} - del

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

ASpell::~ASpell()
{}

const std::string & ASpell::getName() const
{
    return (_name);
}

const std::string & ASpell::getEffects() const
{
    return (_effects);
}

void ASpell::launch(const ATarget & one) const // const!!!
{
    one.getHitBySpell(*this); // *this!!!
}
