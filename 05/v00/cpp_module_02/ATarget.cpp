#include "ATarget.hpp"

ATarget::ATarget() : _type() {}
ATarget::ATarget(std::string type) : _type(type) {}
ATarget::ATarget(const ATarget & one)
{
    _type = one._type;
}
ATarget & ATarget::operator=(const ATarget & one)
{
    _type = one._type;
    return (*this);
}
ATarget::~ATarget() {}

const std::string & ATarget::getType() const
{
    return (_type);
}

void ATarget::getHitBySpell(const ASpell & one) const
{
    std::cout << _type << " has been " << one.getEffects() << "!" << std::endl;
}
