#ifndef NINJATRAP_H
# define NINJATRAP_H

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public virtual ClapTrap
{
    public:
        NinjaTrap (void);
        NinjaTrap (std::string name);
        NinjaTrap (NinjaTrap const & src);
        ~NinjaTrap (void);

        NinjaTrap & operator=(NinjaTrap const & rhs);

        void    ninjaShoebox(ClapTrap &trap);
        void    ninjaShoebox(FragTrap &trap);
        void    ninjaShoebox(ScavTrap &trap);
        void    ninjaShoebox(NinjaTrap &trap);
};

#endif
