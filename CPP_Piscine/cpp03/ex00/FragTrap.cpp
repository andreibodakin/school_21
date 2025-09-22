#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    this->_Name = "noname";
    this->_Hit_points = 100;
    this->_Max_hit_points = 100;
    this->_Energy_points = 100;
    this->_Max_energy_points = 100;
    this->_Level = 1;
    this->_Melee_attack_damage = 30;
    this->_Ranged_attack_damage = 20;
    this->_Armor_damage_reduction = 5;
    this->_Attacks[0] = "Perfect Susanoo";
    this->_Attacks[1] = "Roof Tile Shuriken";
    this->_Attacks[2] = "Hidden Lotus";
    this->_Attacks[3] = "Twin Rising Dragons";
    this->_Attacks[4] = "Full Power Ninja";
    std::cout << "FR4G-TP: ";
    std::cout << this->_Name;
    std::cout << " tells: Hey everybody! Check out my package!";
    std::cout << std::endl;
    return ;
}

FragTrap::FragTrap(std::string name)
{
    this->_Name = name;
    this->_Hit_points = 100;
    this->_Max_hit_points = 100;
    this->_Energy_points = 100;
    this->_Max_energy_points = 100;
    this->_Level = 1;
    this->_Melee_attack_damage = 30;
    this->_Ranged_attack_damage = 20;
    this->_Armor_damage_reduction = 5;
    this->_Attacks[0] = "Perfect Susanoo";
    this->_Attacks[1] = "Roof Tile Shuriken";
    this->_Attacks[2] = "Hidden Lotus";
    this->_Attacks[3] = "Twin Rising Dragons";
    this->_Attacks[4] = "Full Power Ninja";
    std::cout << "FR4G-TP: ";
    std::cout << this->_Name;
    std::cout << " tells: Hey everybody! Check out my package!";
    std::cout << std::endl;
    return ;
}

FragTrap::FragTrap(FragTrap const & src)
{
    *this = src;
    std::cout << "FR4G-TP: ";
    std::cout << this->_Name;
    std::cout << " tells: Hey everybody! I've been copied!";
    std::cout << std::endl;
    return ;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FR4G-TP: ";
    std::cout << this->_Name;
    std::cout << " tells: No no no, you're not dead, you're destructed.";
    std::cout << std::endl;
    return ;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
    this->_Name = rhs._Name;
    this->_Hit_points = rhs._Hit_points;
    this->_Max_hit_points = rhs._Max_hit_points;
    this->_Energy_points = rhs._Energy_points;
    this->_Max_energy_points = rhs._Max_energy_points;
    this->_Level = rhs._Level;
    this->_Melee_attack_damage = rhs._Melee_attack_damage;
    this->_Ranged_attack_damage = rhs._Ranged_attack_damage;
    this->_Armor_damage_reduction = rhs._Armor_damage_reduction;
    this->_Attacks[0] = rhs._Attacks[0];
    this->_Attacks[1] = rhs._Attacks[1];
    this->_Attacks[2] = rhs._Attacks[2];
    this->_Attacks[3] = rhs._Attacks[3];
    this->_Attacks[4] = rhs._Attacks[4];
    std::cout << "Assignation operator called" << std::endl;
    return (*this);
}

void    FragTrap::rangedAttack(std::string const & target)
{
    std::cout << "Hey, best friend! FR4G-TP ";
    std::cout << this->_Name;
    std::cout << " rangedAttacks ";
    std::cout << target;
    std::cout << " at range, causing ";
    std::cout << this->_Ranged_attack_damage;
    std::cout << " points of damage!";
    std::cout << std::endl;
    return ;
}

void    FragTrap::meleeAttack(std::string const & target)
{
    std::cout << "Hit me, baby! FR4G-TP ";
    std::cout << this->_Name;
    std::cout << " meleeAttacks ";
    std::cout << target;
    std::cout << " at range, causing ";
    std::cout << this->_Melee_attack_damage;
    std::cout << " points of damage!";
    std::cout << std::endl;
    return ;
}

void    FragTrap::vaulthunter_dot_exe(std::string const & target)
{
    int temp;
    
    if (this->_Energy_points >= 25)
        this->_Energy_points -= 25;
    else
        {
            std::cout << "NO Energy points for vaulthunter" << std::endl;
            return ;
        }
    temp = rand() % 5;
    std::cout << "Let's get this party started!! FR4G-TP ";
    std::cout << this->_Name;
    std::cout << " vaulthunter ";
    std::cout << target;
    std::cout << " with ";
    std::cout <<  _Attacks[temp];
    std::cout << " , causing 25 Energy points. Current EP is ";
    std::cout << this->_Energy_points;
    std::cout << std::endl;
    return ;
}

void    FragTrap::takeDamage(unsigned int amount)
{
    if (amount <= this->_Armor_damage_reduction)
        amount = 0;
    else if ((amount - this->_Armor_damage_reduction) < this->_Hit_points)
        this->_Hit_points -= (amount - this->_Armor_damage_reduction);
    else
        this->_Hit_points = 0;
    std::cout << "Ow hohoho, that hurts! Yipes! FR4G-TP ";
    std::cout << this->_Name;
    std::cout << " takeDamage ";
    std::cout << amount;
    std::cout << " current HP is ";
    std::cout << this->_Hit_points;
    std::cout << std::endl;
    return ;
}

void    FragTrap::beRepaired(unsigned int amount)
{
    if (amount + this->_Hit_points >= _Max_hit_points)
        this->_Hit_points = this->_Max_hit_points;
    else
        this->_Hit_points += amount;
    std::cout << "Sweet life juice! FR4G-TP ";
    std::cout << this->_Name;
    std::cout << " beRapaired ";
    std::cout << amount;
    std::cout << " current HP is ";
    std::cout << this->_Hit_points;
    std::cout << std::endl;
    return ;
}

    //There is no way this ends badly!
