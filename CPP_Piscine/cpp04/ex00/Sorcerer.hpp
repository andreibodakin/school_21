#ifndef SORCERER_H
# define SORCERER_H

#include <iostream>
#include <string>
#include <sstream>

#include "Victim.hpp"

class Sorcerer
{
    public:
        Sorcerer (std::string name, std::string title);
        virtual ~Sorcerer (void);

        Sorcerer & operator=(Sorcerer const & rhs);

        std::string     hello(void) const;
        void            polymorph(Victim &one);

    private:
        Sorcerer (void);
        Sorcerer (Sorcerer const & src);

        std::string     _Name;
        std::string     _Title;
};

std::ostream & operator<<(std::ostream & o, Sorcerer const & rhs);

#endif
