#ifndef POLYMORPH_H
# define POLYMORPH_H

#include <iostream>
#include <string>

#include "ASpell.hpp"
class ASpell;

class Polymorph : public ASpell
{
    public:
        Polymorph();
        Polymorph(std::string name, std::string effects);
        Polymorph(const Polymorph &);
        Polymorph & operator=(const Polymorph &);
        virtual ~Polymorph();
        
        ASpell * clone() const;
};

#endif
