#ifndef PEON_H
# define PEON_H

#include "Victim.hpp"

class Peon : public Victim
{
    public:
        Peon (std::string name);
        virtual ~Peon (void);

        Peon & operator=(Peon const & rhs);

        virtual void    getPolymorphed(void) const;
    private:
        Peon (void);
        Peon (Peon const & src);

        std::string     _Name;
};

std::ostream & operator<<(std::ostream & o, Peon const & rhs);

#endif
