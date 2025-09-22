#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall") {}
BrickWall::BrickWall(std::string type) : ATarget(type) {}
BrickWall::BrickWall(const BrickWall & one) : ATarget(one) {}
BrickWall & BrickWall::operator=(const BrickWall & one)
{
    if (this != &one)
        *this = one;
    return (*this);
}
BrickWall::~BrickWall() {}

ATarget * BrickWall::clone() const
{
    return (new BrickWall(*this));
}
