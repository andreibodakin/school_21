#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "SuperMutant")
{
    this->_HP = 170;
    this->_type = "SuperMutant";
    Enemy::_die_message = "Aaargh...";
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(int hp, std::string const & type) : Enemy(170, "SuperMutant")
{
    this->_HP = hp;
    this->_type = type;
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

void SuperMutant::takeDamage(int damage)
{
    std::cout << "SuperMutant take 3 less damage!!! Eay eay eay" << std::endl;
    // std::cout << "My damage: " << damage / 3 << std::endl;
    // std::cout << "My HP: " << this->_HP - (damage / 3) << std::endl;
    this->_HP = this->_HP - (damage / 3);
    if (this->_HP <= 0)
    {
        this->_HP = 0;
        std::cout << this->_die_message << std::endl;
    }
}

SuperMutant::~SuperMutant()
{}

SuperMutant::SuperMutant(SuperMutant const & src)
{
    *this = src;
    std::cout << "*SuperMutant call copy constructor*";
    return ;
}

SuperMutant & SuperMutant::operator=(SuperMutant const & rhs)
{
    this->_HP = rhs._HP;
    this->_type = rhs._HP;
    
    return (*this);
}
