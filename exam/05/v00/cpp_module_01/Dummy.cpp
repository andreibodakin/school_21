#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {}

Dummy::Dummy(std::string type) : ATarget(type) {}
Dummy::Dummy(const Dummy & one) : ATarget(one) {}
Dummy & Dummy::operator=(const Dummy & one)
{
    if (this != &one)
        *this = one;
    return (*this);
}
Dummy::~Dummy() {}


ATarget * Dummy::clone() const
{
    return (new Dummy(*this)); // *this!!!!!
}
