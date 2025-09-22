#ifndef SUPERTRAP_H
# define SUPERTRAP_H

#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
    public:
        SuperTrap (void);
        SuperTrap (std::string name);
        SuperTrap (SuperTrap const & src);
        ~SuperTrap (void);

        SuperTrap & operator=(SuperTrap const & rhs);
};

#endif
