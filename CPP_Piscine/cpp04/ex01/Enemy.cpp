#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const & type)
{
    this->_HP = hp;
    this->_type = type;
}

Enemy::~Enemy()
{}

const std::string & Enemy::getType() const
{
    return (this->_type);
}

int Enemy::getHP() const
{
    return (this->_HP);
}

void Enemy::takeDamage(int damage)
{
    this->_HP = this->_HP - damage;
    if (this->_HP <= 0)
    {
        this->_HP = 0;
        std::cout << this->_die_message << std::endl;
    }
}

Enemy::Enemy()
{
    this->_HP = 0;
    this->_type = "";
}

Enemy::Enemy(Enemy const & src)
{
    *this = src;
    std::cout << "*Enemy call copy constructor*";
    return ;
}

Enemy & Enemy::operator=(Enemy const & rhs)
{
    this->_HP = rhs._HP;
    this->_type = rhs._type;
    
    return (*this);
}
