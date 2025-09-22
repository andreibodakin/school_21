

#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {}
Dummy::Dummy(std::string type) : ATarget(type) {}
Dummy::Dummy(const Dummy &spell) : ATarget(spell) {}
Dummy& Dummy::operator = (const Dummy& ref) {
    if (this != &ref)
        *this = ref;
    return (*this);
}
Dummy::~Dummy() {}

ATarget* Dummy::clone() const {
    return (new Dummy(*this));
}
