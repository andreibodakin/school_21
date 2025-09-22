#ifndef FWOOSH_H
# define FWOOSH_H

#include <iostream>
#include <string>

#include "ASpell.hpp"
class ASpell;

class Fwoosh : public ASpell
{
    public:
        Fwoosh();
        Fwoosh(std::string name, std::string effects);
        Fwoosh(const Fwoosh &);
        Fwoosh & operator=(const Fwoosh &);
        virtual ~Fwoosh();
        
        ASpell * clone() const;
};

#endif
