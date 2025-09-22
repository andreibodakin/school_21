#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB (std::string const &str);
        ~HumanB (void);

        void        attack(void);
        void        setWeapon(Weapon &club);
    private:
        Weapon *club;
        std::string name;
};

#endif
