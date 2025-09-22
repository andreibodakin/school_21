#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>
#include <cstdlib>

class ClapTrap
{
    public:
        ClapTrap (void);
        ClapTrap (std::string name);
        ClapTrap (ClapTrap const & src);
        ~ClapTrap (void);

        ClapTrap & operator=(ClapTrap const & rhs);

        void    rangedAttack(std::string const & target);
        void    meleeAttack(std::string const & target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

        std::string     getName(void);
    protected:
        std::string     _Name;
        unsigned int    _Hit_points;
        unsigned int    _Max_hit_points;
        unsigned int    _Energy_points;
        unsigned int    _Max_energy_points;
        unsigned int    _Level;
        unsigned int    _Melee_attack_damage;
        unsigned int    _Ranged_attack_damage;
        unsigned int    _Armor_damage_reduction;
        std::string     _Type;
    private:
        std::string     _BaseType;
};

#endif
