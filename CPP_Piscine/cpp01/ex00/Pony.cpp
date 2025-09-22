#include "Pony.hpp"

Pony::Pony(void)
{
    std::cout << "Pony was born!" << std::endl;

    return ;
}

Pony::~Pony(void)
{
    std::cout << "Pony went to the farm." << std::endl;
    
    return ;
}

std::string Pony::getName(void)
{
    return (this->_name);
}
void        Pony::setName(std::string str)
{
    this->_name = str;
    return ;
}

std::string Pony::getColor(void)
{
    return (this->_color);
}
void        Pony::setColor(std::string str)
{
    this->_color = str;
    return ;
}

std::string Pony::getBirthday(void)
{
    return (this->_birthday);
}
void        Pony::setBirthday(std::string str)
{
    this->_birthday = str;
    return ;
}

std::string Pony::getWeight(void)
{
    return (this->_weight);
}
void        Pony::setWeight(std::string str)
{
    this->_weight = str;
    return ;
}
