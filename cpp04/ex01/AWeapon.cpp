#include "AWeapon.hpp"

AWeapon::AWeapon()
{
    std::cout << "AWeapon default constructor" << std::endl;
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
{
    this->_name = name;
    this->_apcost = apcost;
    this->_damage = damage;
}

AWeapon::~AWeapon()
{}

const std::string & AWeapon::getName() const
{
    return (this->_name);
}

int AWeapon::getAPCost() const
{
    return (this->_apcost);
}

int AWeapon::getDamage() const
{
    return (this->_damage);
}

AWeapon::AWeapon(AWeapon const & src)
{
    *this = src;
    std::cout << "*AWeapon call copy constructor*";
    return ;
}

AWeapon & AWeapon::operator=(AWeapon const & rhs)
{
    this->_name = rhs._name;
    this->_apcost = rhs._apcost;
    this->_damage = rhs._damage;
    
    return (*this);
}
