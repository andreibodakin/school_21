#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type)
{
    this->_name = name;
    this->_type = type;

    return ;
}
Zombie::~Zombie(void)
{
    return ;
}

void    Zombie::announce(void)
{
    std::cout << this->_name << " say ARRRRRrrrrrr" << std::endl;
    std::cout << this->_type << " is his type." << std::endl;
}
