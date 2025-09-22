#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
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
    this->_BaseType = "ClapTrap";
    this->_Type = "none";
    std::cout << this->_BaseType;
    std::cout << " constructed. ";
    std::cout << this->_Name;
    std::cout << " tells: I'm the base for all Traps!";
    std::cout << std::endl;
    return ;
}

ClapTrap::ClapTrap(std::string name)
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
    this->_BaseType = "ClapTrap";
    this->_Type = "none";
    std::cout << this->_BaseType;
    std::cout << " constructed. ";
    std::cout << this->_Name;
    std::cout << " tells: I'm the base for all Traps!";
    std::cout << std::endl;
    return ;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
    *this = src;
    std::cout << this->_BaseType;
    std::cout << " constructed. ";
    std::cout << this->_Name;
    std::cout << " tells: Hey everybody! I've been copied!";
    std::cout << std::endl;
    return ;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << this->_BaseType;
    std::cout << " ";
    std::cout << this->_Name;
    std::cout << " tells: No no no, you're not dead, you're destructed.";
    std::cout << std::endl;
    return ;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
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
    this->_BaseType = rhs._BaseType;
    this->_Type = rhs._Type;
    std::cout << "Assignation operator called" << std::endl;
    return (*this);
}

void    ClapTrap::rangedAttack(std::string const & target)
{
    std::cout << "Hey, best friend! ";
    std::cout << this->_Type;
    std::cout << " ";
    std::cout << this->_Name;
    std::cout << " rangedAttacks ";
    std::cout << target;
    std::cout << " at range, causing ";
    std::cout << this->_Ranged_attack_damage;
    std::cout << " points of damage!";
    std::cout << std::endl;
    return ;
}

void    ClapTrap::meleeAttack(std::string const & target)
{
    std::cout << "Hit me, baby! ";
    std::cout << this->_Type;
    std::cout << " ";
    std::cout << this->_Name;
    std::cout << " meleeAttacks ";
    std::cout << target;
    std::cout << " at range, causing ";
    std::cout << this->_Melee_attack_damage;
    std::cout << " points of damage!";
    std::cout << std::endl;
    return ;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (amount <= this->_Armor_damage_reduction)
        amount = 0;
    else if ((amount - this->_Armor_damage_reduction) < this->_Hit_points)
        this->_Hit_points -= (amount - this->_Armor_damage_reduction);
    else
        this->_Hit_points = 0;
    std::cout << "Ow hohoho, that hurts! Yipes! ";
    std::cout << this->_Type;
    std::cout << " ";
    std::cout << this->_Name;
    std::cout << " takeDamage ";
    std::cout << amount;
    std::cout << " current HP is ";
    std::cout << this->_Hit_points;
    std::cout << std::endl;
    return ;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (amount + this->_Hit_points >= _Max_hit_points)
        this->_Hit_points = this->_Max_hit_points;
    else
        this->_Hit_points += amount;
    std::cout << "Sweet life juice! ";
    std::cout << this->_Type;
    std::cout << " ";
    std::cout << this->_Name;
    std::cout << " beRapaired ";
    std::cout << amount;
    std::cout << " current HP is ";
    std::cout << this->_Hit_points;
    std::cout << std::endl;
    return ;
}

std::string     ClapTrap::getName(void)
{
    return (this->_Name);
}