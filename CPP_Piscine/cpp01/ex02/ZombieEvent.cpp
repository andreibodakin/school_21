#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void)
{
    return ;
}
ZombieEvent::~ZombieEvent(void)
{
    return ;
}

void        ZombieEvent::setZombieType(std::string type)
{
    this->_type = type;

    return ;
}

Zombie      *ZombieEvent::newZombie(std::string name)
{
    return (new Zombie(name, this->_type));
}
