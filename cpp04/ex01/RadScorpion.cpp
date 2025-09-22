#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion")
{
    this->_HP = 80;
    this->_type = "RadScorpion";
    Enemy::_die_message = "* SPROTCH *";
    std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(int hp, std::string const & type) : Enemy(80, "RadScorpion")
{
    this->_HP = hp;
    this->_type = type;
    Enemy::_die_message = "* SPROTCH *";
    std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{}

RadScorpion::RadScorpion(RadScorpion const & src)
{
    *this = src;
    std::cout << "*RadScorpion call copy constructor*";
    return ;
}

RadScorpion & RadScorpion::operator=(RadScorpion const & rhs)
{
    this->_HP = rhs._HP;
    this->_type = rhs._HP;
    
    return (*this);
}
