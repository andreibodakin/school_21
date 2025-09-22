#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    this->_Name = "noname";
    this->_Hit_points = 100;
    this->_Max_hit_points = 100;
    this->_Energy_points = 50;
    this->_Max_energy_points = 50;
    this->_Level = 1;
    this->_Melee_attack_damage = 20;
    this->_Ranged_attack_damage = 15;
    this->_Armor_damage_reduction = 3;
    this->_Challenge[0] = "Hot Chili Challenge";
    this->_Challenge[1] = "Brain Freezer Challenge";
    this->_Challenge[2] = "Yoga Pose Challenge";
    this->_Challenge[3] = "Karaoke Challenge";
    this->_Challenge[4] = "Tornado Challenge";
    std::cout << "FR4G-TP: ";
    std::cout << this->_Name;
    std::cout << " ScavTrap tells: I dare you!";
    std::cout << std::endl;
    return ;
}

ScavTrap::ScavTrap(std::string name)
{
    this->_Name = name;
    this->_Hit_points = 100;
    this->_Max_hit_points = 100;
    this->_Energy_points = 50;
    this->_Max_energy_points = 50;
    this->_Level = 1;
    this->_Melee_attack_damage = 20;
    this->_Ranged_attack_damage = 15;
    this->_Armor_damage_reduction = 3;
    this->_Challenge[0] = "Hot Chili Challenge";
    this->_Challenge[1] = "Brain Freezer Challenge";
    this->_Challenge[2] = "Yoga Pose Challenge";
    this->_Challenge[3] = "Karaoke Challenge";
    this->_Challenge[4] = "Tornado Challenge";
    std::cout << "FR4G-TP: ";
    std::cout << this->_Name;
    std::cout << " ScavTrap tells: I dare you!";
    std::cout << std::endl;
    return ;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
    *this = src;
    std::cout << "FR4G-TP: ";
    std::cout << this->_Name;
    std::cout << " ScavTrap tells: Hey everybody! I've been copied!";
    std::cout << std::endl;
    return ;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "FR4G-TP: ";
    std::cout << this->_Name;
    std::cout << " ScavTrap tells: No no no, you're not dead, you're destructed.";
    std::cout << std::endl;
    return ;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
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
    this->_Challenge[0] = rhs._Challenge[0];
    this->_Challenge[1] = rhs._Challenge[1];
    this->_Challenge[2] = rhs._Challenge[2];
    this->_Challenge[3] = rhs._Challenge[3];
    this->_Challenge[4] = rhs._Challenge[4];
    std::cout << "Assignation operator called" << std::endl;
    return (*this);
}

void    ScavTrap::rangedAttack(std::string const & target)
{
    std::cout << "Hey, best friend! ScavTrap ";
    std::cout << this->_Name;
    std::cout << " rangedAttacks ";
    std::cout << target;
    std::cout << " at range, causing ";
    std::cout << this->_Ranged_attack_damage;
    std::cout << " points of damage!";
    std::cout << std::endl;
    return ;
}

void    ScavTrap::meleeAttack(std::string const & target)
{
    std::cout << "Hit me, baby! ScavTrap ";
    std::cout << this->_Name;
    std::cout << " meleeAttacks ";
    std::cout << target;
    std::cout << " at range, causing ";
    std::cout << this->_Melee_attack_damage;
    std::cout << " points of damage!";
    std::cout << std::endl;
    return ;
}

void    ScavTrap::challengeNewcomer(std::string const & target)
{
    int temp;
    
    temp = rand() % 5;
    std::cout << "There is no way this ends badly! ";
    std::cout << this->_Name;
    std::cout << " challengeNewcomer ";
    std::cout << target;
    std::cout << " with ";
    std::cout <<  _Challenge[temp];
    std::cout << std::endl;
    return ;
}

void    ScavTrap::takeDamage(unsigned int amount)
{
    if (amount <= this->_Armor_damage_reduction)
        amount = 0;
    else if ((amount - this->_Armor_damage_reduction) < this->_Hit_points)
        this->_Hit_points -= (amount - this->_Armor_damage_reduction);
    else
        this->_Hit_points = 0;
    std::cout << "Ow hohoho, that hurts! Yipes! ScavTrap ";
    std::cout << this->_Name;
    std::cout << " takeDamage ";
    std::cout << amount;
    std::cout << " current HP is ";
    std::cout << this->_Hit_points;
    std::cout << std::endl;
    return ;
}

void    ScavTrap::beRepaired(unsigned int amount)
{
    if (amount + this->_Hit_points >= _Max_hit_points)
        this->_Hit_points = this->_Max_hit_points;
    else
        this->_Hit_points += amount;
    std::cout << "Sweet life juice! ScavTrap ";
    std::cout << this->_Name;
    std::cout << " beRapaired ";
    std::cout << amount;
    std::cout << " current HP is ";
    std::cout << this->_Hit_points;
    std::cout << std::endl;
    return ;
}
