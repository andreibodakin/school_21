#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class Zombie;

class ZombieHorde
{
    public:
        ZombieHorde (int nbr);
        ~ZombieHorde (void);

        void        announce(void);
    private:
        int         _nbr_zombie;
        Zombie      *_zombie;
};

#endif
