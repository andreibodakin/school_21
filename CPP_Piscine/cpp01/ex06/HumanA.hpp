#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA (std::string const &str, Weapon &club);
        ~HumanA (void);

        void        attack(void);
    private:
        std::string name;
        Weapon &club;
};

#endif
