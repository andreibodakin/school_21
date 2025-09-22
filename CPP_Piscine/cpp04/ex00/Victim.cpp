#include "Victim.hpp"

Victim::Victim(void)
{
    std::cout << "Victim call for Default constructor" << std::endl;
    return ;
}

Victim::Victim(std::string name)
{
    this->_Name = name;
    std::cout << "Some random victim called ";
    std::cout << this->_Name;
    std::cout << " just appeared!";
    std::cout << std::endl;
    return ;
}

Victim::Victim(Victim const & src)
{
    *this = src;
    std::cout << "Some random victim called ";
    std::cout << this->_Name;
    std::cout << " just been copied!";
    std::cout << std::endl;
    return ;
}

Victim::~Victim(void)
{
    std::cout << "Victim ";
    std::cout << this->_Name;
    std::cout << " just died for no apparent reason!";
    std::cout << std::endl;
    return ;
}

Victim & Victim::operator=(Victim const & rhs)
{
    this->_Name = rhs._Name;
    
    return (*this);
}

std::string        Victim::hello(void) const
{
    std::stringstream   s_strem;

    s_strem << "I'm ";
    s_strem << this->_Name;
    s_strem << " and I like otters!";
    s_strem << std::endl;

    return (s_strem.str());
}

std::ostream & operator<<(std::ostream & o, Victim const & rhs)
{
    o << rhs.hello();

    return (o);
}

std::string     Victim::getName(void) const
{
    return (this->_Name);
}

void            Victim::getPolymorphed() const
{
    std::cout << this->getName() << " has been turned into a cute little sheep!" << std::endl;
}
