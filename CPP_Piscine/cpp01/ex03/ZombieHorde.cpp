#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int nbr)
{
    this->_nbr_zombie = nbr;

    if (nbr < 1)
        std::cout << "Enter a valid number of zombie" << std::endl;
    else
    {
        this->_zombie = new Zombie[nbr];
        for (int i = 0; i < nbr; i++)
        {
            this->_zombie[i].setName(randomName());
            this->_zombie[i].setType(randomType());
        }
    }
    return ;
}

ZombieHorde::~ZombieHorde(void)
{
    delete [] this->_zombie;
    return ;
}

void        ZombieHorde::announce(void)
{
    for (int i = 0; i < this->_nbr_zombie; i++)
    {
        _zombie[i].announce();
    }
}
