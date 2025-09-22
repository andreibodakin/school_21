#ifndef VICTIM_H
# define VICTIM_H

#include <iostream>
#include <string>
#include <sstream>

class Victim
{
    public:
        Victim (std::string name);
        virtual ~Victim (void);

        Victim & operator=(Victim const & rhs);

        std::string     hello(void) const;
        std::string     getName(void) const;
        virtual void    getPolymorphed(void) const;
    protected:
        std::string     _Name;
        Victim (void);
        Victim (Victim const & src);
};

std::ostream & operator<<(std::ostream & o, Victim const & rhs);

// # include "Sorcerer.hpp"

#endif
