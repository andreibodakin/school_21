#include "Zombie.hpp"

Zombie::Zombie(void)
{
    return ;
}
Zombie::~Zombie(void)
{
    return ;
}

void        Zombie::announce(void)
{
    std::cout << this->_name << " say ARRRRRrrrrrr" << std::endl;
    std::cout << this->_type << " is his type." << std::endl;
}

void        Zombie::setName(std::string name)
{
    this->_name = name;
    return ;
}
std::string Zombie::getName(void)
{
    return (this->_name);
}

void        Zombie::setType(std::string type)
{
    this->_type = type;
    return ;
}
std::string Zombie::getType(void)
{
    return (this->_type);
}
