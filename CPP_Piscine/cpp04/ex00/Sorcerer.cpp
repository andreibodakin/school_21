#include "Sorcerer.hpp"

Sorcerer::Sorcerer(void)
{
    std::cout << "Sorcerer call for Default constructor" << std::endl;
    return ;
}

Sorcerer::Sorcerer(std::string name, std::string title)
{
    this->_Name = name;
    this->_Title = title;
    std::cout << this->_Name;
    std::cout << ", ";
    std::cout << this->_Title;
    std::cout << ", is born!";
    std::cout << std::endl;
    return ;
}

Sorcerer::Sorcerer(Sorcerer const & src)
{
    *this = src;
    std::cout << this->_Name;
    std::cout << ", ";
    std::cout << this->_Title;
    std::cout << ", is born!";
    std::cout << std::endl;
    return ;
}

Sorcerer::~Sorcerer(void)
{
    std::cout << this->_Name;
    std::cout << ", ";
    std::cout << this->_Title;
    std::cout << ", is dead. Consequences will never be the same!";
    std::cout << std::endl;
    return ;
}

Sorcerer & Sorcerer::operator=(Sorcerer const & rhs)
{
    this->_Name = rhs._Name;
    this->_Title = rhs._Title;
    
    return (*this);
}

std::string        Sorcerer::hello(void) const
{
    std::stringstream   s_strem;

    s_strem << "I am ";
    s_strem << this->_Name;
    s_strem << ", ";
    s_strem << this->_Title;
    s_strem << ", and I like ponies!";
    s_strem << std::endl;

    return (s_strem.str());
}

std::ostream & operator<<(std::ostream & o, Sorcerer const & rhs)
{
    o << rhs.hello();

    return (o);
}

void            Sorcerer::polymorph(Victim &one)
{
    one.getPolymorphed();
}
