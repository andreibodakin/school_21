#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{
    PlasmaRifle::_attack = "* piouuu piouuu piouuu *";
    // std::cout << "PlasmaRifle call for default constructor." << std::endl;
}

PlasmaRifle::PlasmaRifle(std::string const & name, int apcost, int damage) : AWeapon(name, apcost, damage)
{
    PlasmaRifle::_name = "Plasma Rifle";
    PlasmaRifle::_apcost = 5;
    PlasmaRifle::_damage = 21;
    PlasmaRifle::_attack = "* piouuu piouuu piouuu *";
}

PlasmaRifle::~PlasmaRifle()
{}

void PlasmaRifle::attack() const
{
    std::cout << this->_attack << std::endl;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src)
{
    *this = src;
    std::cout << "*PlasmaRifle call copy constructor*";
    return ;
}

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle const & rhs)
{
    PlasmaRifle::_name = rhs._name;
    PlasmaRifle::_apcost = rhs._apcost;
    PlasmaRifle::_damage = rhs._damage;
    PlasmaRifle::_attack = rhs._attack;
    
    return (*this);
}
