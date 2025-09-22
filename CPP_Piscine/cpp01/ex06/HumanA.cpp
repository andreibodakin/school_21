#include "HumanA.hpp"

HumanA::HumanA(std::string const &str, Weapon &club) : name(str), club(club)
{
    std::cout << "HumanA constructed" << std::endl;

    return ;
}
HumanA::~HumanA(void)
{
    std::cout << "HumanA destructed" << std::endl;
    return ;
}

void    HumanA::attack(void)
{
    std::cout << this->name << " attacks with his " << this->club.getType() << std::endl;
}
