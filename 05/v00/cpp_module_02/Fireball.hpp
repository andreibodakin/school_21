#ifndef FIREBALL_H
# define FIREBALL_H

#include <iostream>
#include <string>

#include "ASpell.hpp"
class ASpell;

class Fireball : public ASpell
{
    public:
        Fireball();
        Fireball(std::string name, std::string effects);
        Fireball(const Fireball &);
        Fireball & operator=(const Fireball &);
        virtual ~Fireball();
        
        ASpell * clone() const;
};

#endif
