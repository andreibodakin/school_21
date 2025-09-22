#include "HumanB.hpp"

HumanB::HumanB(std::string const &str) : name(str)
{
    this->club = NULL;
    std::cout << "HumanB constructed" << std::endl;

    return ;
}
HumanB::~HumanB(void)
{
    std::cout << "HumanA destructed" << std::endl;
    
    return ;
}

void        HumanB::setWeapon(Weapon &club)
{
    this->club = &club;

    return ;
}

void    HumanB::attack(void)
{
    std::cout << this->name << " attacks with his " << club->getType() << std::endl;
}
