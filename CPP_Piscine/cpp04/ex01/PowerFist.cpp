#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{
    PowerFist::_attack = "* pschhh... SBAM! *";
}

PowerFist::PowerFist(std::string const & name, int apcost, int damage) : AWeapon(name, apcost, damage)
{
    PowerFist::_name = "Power Fist";
    PowerFist::_apcost = 8;
    PowerFist::_damage = 50;
    PowerFist::_attack = "* pschhh... SBAM! *";
}

PowerFist::~PowerFist()
{}

void PowerFist::attack() const
{
    std::cout << this->_attack << std::endl;
}

PowerFist::PowerFist(PowerFist const & src)
{
    *this = src;
    std::cout << "*PowerFist call copy constructor*";
    return ;
}

PowerFist & PowerFist::operator=(PowerFist const & rhs)
{
    PowerFist::_name = rhs._name;
    PowerFist::_apcost = rhs._apcost;
    PowerFist::_damage = rhs._damage;
    PowerFist::_attack = rhs._attack;
    
    return (*this);
}
