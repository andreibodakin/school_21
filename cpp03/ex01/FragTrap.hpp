#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include <iostream>
#include <cstdlib>

class FragTrap
{
    public:
        FragTrap (void);
        FragTrap (std::string name);
        FragTrap (FragTrap const & src);
        ~FragTrap (void);

        FragTrap & operator=(FragTrap const & rhs);

        void    rangedAttack(std::string const & target);
        void    meleeAttack(std::string const & target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        void    vaulthunter_dot_exe(std::string const & target);

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
        std::string     _Attacks[5];
};

#endif
