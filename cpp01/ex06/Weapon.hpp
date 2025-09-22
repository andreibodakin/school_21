#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>
#include <sstream>

class Weapon
{
    public:
        Weapon (std::string str);
        ~Weapon (void);

        void        setType(std::string str);
        std::string const &getType(void);
    private:
        std::string _type;
};

#endif
