#include "Peon.hpp"

Peon::Peon(void)
{
    std::cout << "Peon call for Default constructor" << std::endl;
    return ;
}

Peon::Peon(std::string name) : Victim(name)
{
    Peon::_Name = name;
    std::cout << "Zog zog.";
    std::cout << std::endl;
    return ;
}

Peon::Peon(Peon const & src)
{
    *this = src;
    std::cout << "Zog zog copy.";
    std::cout << std::endl;
    return ;
}

Peon::~Peon(void)
{
    std::cout << "Bleuark...";
    std::cout << std::endl;
    return ;
}

Peon & Peon::operator=(Peon const & rhs)
{
    this->_Name = rhs._Name;
    
    return (*this);
}

std::ostream & operator<<(std::ostream & o, Peon const & rhs)
{
    o << rhs.hello();

    return (o);
}

void            Peon::getPolymorphed() const
{
    std::cout << this->getName() << " has been turned into a pink pony!" << std::endl;
}
