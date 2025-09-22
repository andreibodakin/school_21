

#include "ATarget.hpp"

ATarget::ATarget() : _type() {}
ATarget::ATarget(std::string type) : _type(type) {}
ATarget::ATarget(const ATarget& ref) {
    _type = ref._type;
}
ATarget& ATarget::operator = (const ATarget& ref) {
    _type = ref._type;
    return (*this);
}
ATarget::~ATarget() {}

const std::string& ATarget::getType() const {
    return _type;
}

void ATarget::getHitBySpell(const ASpell& spell) const {
    std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}
