#include "Weapon.hpp"

Weapon::Weapon(std::string str)
{
    this->_type =  str;
    return ;
}
Weapon::~Weapon(void)
{
    return ;
}

void        Weapon::setType(std::string str)
{
    this->_type =  str;

    return ;
}

std::string const &Weapon::getType(void)
{
    return (this->_type);
}
