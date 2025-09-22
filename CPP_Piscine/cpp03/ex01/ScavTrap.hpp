#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "FragTrap.hpp"

class ScavTrap
{
    public:
        ScavTrap (void);
        ScavTrap (std::string name);
        ScavTrap (ScavTrap const & src);
        ~ScavTrap (void);

        ScavTrap & operator=(ScavTrap const & rhs);

        void    rangedAttack(std::string const & target);
        void    meleeAttack(std::string const & target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        void    challengeNewcomer(std::string const & target);

    private:
        std::string     _Name;
        unsigned int    _Hit_points;
        unsigned int    _Max_hit_points;
        unsigned int    _Energy_points;
        unsigned int    _Max_energy_points;
        unsigned int    _Level;
        unsigned int    _Melee_attack_damage;
        unsigned int    _Ranged_attack_damage;
        unsigned int    _Armor_damage_reduction;
        std::string     _Challenge[5];
};

#endif
